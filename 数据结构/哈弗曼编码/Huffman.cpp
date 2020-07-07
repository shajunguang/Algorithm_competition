//完成霍夫曼编码实现
//流程 1.创建优先队列 2.构建霍夫曼树 3.encoding 4.decoding

#include<bits/stdc++.h>
using namespace std;

typedef int Elemtype;

//队列节点
typedef struct QueueNode{
    Elemtype data;
    QueueNode* next;
}QueueNode,*QueuePtr;

//队列
typedef struct{
    QueuePtr front,rear;
}Prority_Queue;

//初始化队列
void initQueue(Prority_Queue* q){
    q->front=q->rear=(QueuePtr)malloc(sizeof(QueueNode));
    q->front->next=NULL;
}
//push操作从小到大排序
void InsertQueue(Prority_Queue* q,Elemtype e){
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QueueNode));
    p->data=e;
    QueuePtr t=q->front->next;
    while(t!=NULL && t!=q->rear) {
        if(t->data>e){
            p->next=t;
            q->front->next=p;
            break;
        }
        if(t->data <= e && t->next->data >= e) {
            p->next = t->next;
            t->next = p;
            break;
        }
        t=t->next;
    }
    if(t==NULL || t==q->rear){
        p->next=NULL;
        q->rear->next=p;
        q->rear=p;
    }
}
//pop操作
void PopQueue(Prority_Queue* q,Elemtype* e){
    if(q->front==q->rear)return;
    auto p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if(p==q->rear) q->rear=q->front;
    free(p);
}
//构建Huffman树
struct HuffmanTree{
    Elemtype val;
    HuffmanTree* left,*right;
    HuffmanTree(int x):val(x),left(NULL),right(NULL){}
};
//根据优先队列构建
void creatHuffmanTree(HuffmanTree **T,Prority_Queue* q){
    *T=new HuffmanTree(-1);
    HuffmanTree* p;
    while(q->front!=q->rear) {
        Elemtype e;
        PopQueue(q, &e);
        Elemtype f;
        PopQueue(q, &f);
        auto t1 = new HuffmanTree(e);
        auto t2 = new HuffmanTree(f);
        p = new HuffmanTree(e + f);
        if((*T)->val==e) t1=*T;
        if((*T)->val==f) t2=*T;
        p->left = t1;
        p->right = t2;
        *T=p;
        if(q->front!=q->rear) InsertQueue(q, e + f);
    }
}
bool is_leaf(HuffmanTree* T){
    if(T==NULL) return false;
    return T->left == NULL && T->right == NULL;
}
//Encoding
void EncodingHuffman(string s[],HuffmanTree* T){
    auto p=T;
    int flag=0;
    string str;
    while(p){
        if(is_leaf(p->left)) s[p->left->val]=str+"1",flag=1;
        if(is_leaf(p->right)) s[p->right->val]=str+"0",flag=0;
        if(flag) p=p->right,str+='0';
        else p=p->left,str+='1';
    }
}
//Decoding
void DecodingHuffman(string s,HuffmanTree* T,Elemtype *e){
    auto p=T;

    for(auto i:s){
        if(i=='0') p=p->right;
        else p=p->left;
    }
    *e=p->val;
}

int main()
{
    char s[100];
    int a[4]={4,17,8,20};
    s[4]='f',s[17]='d',s[8]='a',s[20]='e';
    Prority_Queue q;
    initQueue(&q);
    for(int i:a) InsertQueue(&q,i);
    HuffmanTree* T;
    creatHuffmanTree(&T,&q);
    string str[100];
    EncodingHuffman(str,T);
    Elemtype e;
    DecodingHuffman(str[4],T,&e);
    cout<<s[e]<<endl;
    return 0;
}