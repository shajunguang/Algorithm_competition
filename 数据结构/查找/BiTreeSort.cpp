//二叉排序树对倒序和顺序的序列是最差的
#include<bits/stdc++.h>
using namespace std;

typedef struct Bitree{
    int data;
    Bitree* left,*right;
    Bitree(int _data):data(_data),left(NULL),right(NULL){}
}Bitree,*BiNode;

//构建二叉排序树
void createBiTreeSort(vector<int> nums,Bitree**T){
    *T = new Bitree(nums[0]);

    for(int i=1;i<nums.size();i++){ //O(n^2)
        int key=nums[i];
        auto tmp=*T;
        while(tmp){
            if(tmp->data>key){
                if(!tmp->left) {tmp->left=new Bitree(nums[i]);break;}
                tmp=tmp->left;
            }
            else {
                if(!tmp->right) {tmp->right=new Bitree(nums[i]);break;}
                tmp=tmp->right;
            }
        }
    }
}
//查找
int FindKey(Bitree* T,int key,BiNode* f,BiNode* p){ //f是查找节点的父亲节点,p是查找节点
    if(!T){
        *p=*f;
        return 0;
    }
    if(T->data==key){
        *p=T;
        return 1;
    }
   if(T->data>key){
       *f=T;
       FindKey(T->left,key,f,p);
   }else{
       *f=T;
       FindKey(T->right,key,f,p);
   }
}

int InsertKey(BiNode* T,int key){
    BiNode s,p,f;
    if(!FindKey(*T,key,&f,&p)){
        s=new Bitree(key);
        if(!p)*T=s; //s为根节点
        else if(p->data>key) p->left=s;
        else p->right=s;
        return 1;
    }else return 0;
}

int DeleteKey(BiNode* T,int key){
    BiNode f,tmp,p;
    if(FindKey(*T,key,&f,&p)){
        if(!p) return 0;//树为空删除失败
        if(!p->left) {
            f->right==p?f->right=p->right:f->left=p->right;
            return 1;
        }else if(!p->right) {
            f->right==p?f->right=p->left:f->left=p->left;
            return 1;
        }else{
            tmp=p->left;
            auto s=tmp->right;
            if(!s){
                p->data=tmp->data;
                p->left=NULL;
                return 1;
            }else{
                while (s->right) {
                    s = s->right;
                    if (s) tmp = tmp->right;
                }
                p->data = s->data;
                tmp->right = s->left;
                return 1;
            }
        }
    }else return 0;
}

int main()
{
    Bitree* T,*f,*p;
    vector<int> nums={12,4,1,3,7,8,10,9,2,11,6,5};
    createBiTreeSort(nums,&T);
    cout<<FindKey(T,6,&f,&p);
    InsertKey(&T,7);
    DeleteKey(&T,10);
    return 0;
}