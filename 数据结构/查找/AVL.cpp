//AVL-平衡二叉排序树
#include<bits/stdc++.h>
using namespace std;

typedef struct BalanceBiTree{
    int data,height;
    BalanceBiTree* left,*right;
    BalanceBiTree(int _x,int _y):data(_x),height(_y),left(NULL),right(NULL){}
}*BiTree;

//更新深度
int UpdataHeight(BiTree *T){
    auto t=*T;
    if(t==NULL) return 0;
    else if(t->left==NULL && t->right==NULL) return t->height=0;
    int l=0,r=0;
    if(t->left!=NULL) l=UpdataHeight(&(t->left));
    if(t->right!=NULL) r=UpdataHeight(&(t->right));
    return t->height=max(l,r)+1;

}
//获取深度
int GetHeight(BiTree T){
    return (T==NULL?0:T->height);
}
//判断是否不平衡以及属于LL,RR,RL,LR哪一种
int isBalance(BiTree T){
   if(T==NULL) return 1;
   int l=GetHeight(T->left),r=GetHeight(T->right);
   if(abs((T->left==NULL?0:l+1)-(T->right==NULL?0:r+1))<2) return 1;
   else return 0;
}
void LL(BiTree *T){ //左左
    auto t=*T;
    auto tmp=t->left;
    t->left=tmp->right;
    tmp->right=t;
    *T=tmp;
}
void RR(BiTree *T){ //右右
    auto t=*T;
    auto tmp=t->right;
    t->right=tmp->left;
    tmp->left=t;
    *T=tmp;
}
void LR(BiTree *T){ //左右
    auto tmp=(*T)->left;
    RR(&tmp);
    (*T)->left=tmp; //移花接木
    LL(T);

}
void RL(BiTree *T){ //右左
    auto tmp=(*T)->right;
    LL(&tmp);
    (*T)->right=tmp; //移花接木
    RR(T);
}
//处理LL,RR,RL,LR变为平衡,
//要点是LL右旋,RR左旋,RL右左,LR左右
//这里遵循先调整子节点的不平衡,再调整祖先节点的不平衡
void ChangeBalance(BiTree *T){
    auto t=*T;
    if(!isBalance(t) && isBalance(t->left) && isBalance(t->right)){
        if (GetHeight(t->left) > GetHeight((t->right))) {//左子树偏深
            auto tmp = t->left; //t是国王,tmp是出问题的小弟,现在看是LL,还是LR
            if (!tmp->right || GetHeight(tmp->left) >= GetHeight(tmp->right)) { //LL类型
                //鸠占鹊巢方法.即单右旋
                LL(T);
                UpdataHeight(T);
                return;
            }
            if(!tmp->left || GetHeight(tmp->left) < GetHeight(tmp->right)) { //LR类型
                //丢锅,让小弟先左旋,再国王右旋
                LR(T);
                UpdataHeight(T);
                return;
            }
        } else {
            auto tmp = t->right;
            if (!tmp->left || GetHeight(tmp->left) <= GetHeight(tmp->right)) {//RR
                RR(T);
                UpdataHeight(T);
                return;
            }
            if (!tmp->right || GetHeight(tmp->left) > GetHeight(tmp->right)) {//RL
                RL(T);
                UpdataHeight(T);
                return;
            }
        }
    }
    if(!isBalance(t->left)) ChangeBalance(&(*T)->left); //调整左孩子
    if(!isBalance(t->right)) ChangeBalance(&(*T)->right); //调整右孩子
    if(!isBalance(t)) ChangeBalance(T); //调整父亲节点
}

//构建平衡二叉树,大概思路先按照二叉排序构建,调整深度,每插入点后,判断是否存在不平衡
//节点,并对不平衡节点进行平衡调整,最后再次更新深度.
void creatBitree(BiTree *T,vector<int> nums){
    if(nums.empty()) return;
    *T=new BalanceBiTree(nums[0],0);
    for(int i=1;i<(int)nums.size();i++){
        int key=nums[i];
        auto tmp=*T;
        while(tmp){
            if(tmp->data>key){
                if(!tmp->left) {
                    tmp->left=new BalanceBiTree(nums[i],0);
                    UpdataHeight(T);
                    break;
                }
                tmp=tmp->left;
            }
            else {
                if(!tmp->right) {
                    tmp->right=new BalanceBiTree(nums[i],0);
                    UpdataHeight(T);
                    break;
                }
                tmp=tmp->right;
            }
        }
        ChangeBalance(T);
        UpdataHeight(T); //这里不能忘记也要更新下深度
    }
}
//查找节点
int FindKey(BiTree T,BiTree *f,BiTree *p,int key){
    if(!T){
        *p=*f;
        return 0;
    }
    if(T->data==key){
        *p=T;
        return 1;
    }
    *f=T;
    T->data>key?FindKey(T->left,f,p,key):FindKey(T->right,f,p,key);
}
//删除节点
int DeleteKey(BiTree *T,int key){
    BiTree f,tmp,p;
    if(FindKey(*T,&f,&p,key)){
        if(!p) return 0;
        if(!p->left){
            f->right==p?f->right=p->right:f->left=p->right;
            delete p;
            UpdataHeight(T);
            ChangeBalance(T);
            UpdataHeight(T);
        }else if(!p->right){
            f->right==p?f->right=p->left:f->left=p->left;
            delete p;
            UpdataHeight(T);
            ChangeBalance(T);
            UpdataHeight(T);
        }else{
            tmp=p->left;
            auto s=tmp->right;
            if(!s){
                p->data=tmp->data;
                p->left=NULL;
                UpdataHeight(T);
                ChangeBalance(T);
                UpdataHeight(T);
                return 1;
            }else{
                while (s->right) {
                    s = s->right;
                    if (s) tmp = tmp->right;
                }
                p->data = s->data;
                tmp->right = s->left;
                UpdataHeight(T);
                ChangeBalance(T);
                UpdataHeight(T);
                return 1;
            }
        }
    }
}

int main()
{
    BiTree T;
    vector<int> nums={12,4,1,10,9,5,6};
    creatBitree(&T,nums);
    DeleteKey(&T,10);
    //层次遍历
    queue<BiTree> q;
    q.push(T);
    while(!q.empty()){
        BiTree t=q.front();q.pop();
        cout<<t->data<<" "<<t->height<<endl;
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
    return 0;
}