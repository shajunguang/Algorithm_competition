
#ifndef ALGORITHM_COMPETITION_LINKQUEUE_H
#define ALGORITHM_COMPETITION_LINKQUEUE_H
//队列的链式表达
#include<bits/stdc++.h>
using namespace std;

typedef char ElemType;
typedef struct QNode{
    ElemType data;
    QNode *next;
}QNode,*QueuePrt;
typedef struct{
    QueuePrt front,rear;//头指针，尾指针
}LinkQueue;
//队列初始化
void initQueue(LinkQueue *q){
    q->front=q->rear=(QueuePrt)malloc(sizeof(QNode));
    if(!q->front)exit(0);
    q->front->next=NULL;
}
//入队操作
void InsertQueue(LinkQueue *q,ElemType e){
    QueuePrt p;
    p=(QueuePrt)malloc(sizeof(QNode));
    if(!p)exit(0);
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}
//出队操作
void PopQueue(LinkQueue *q,ElemType *e){
    QueuePrt p;
    if(q->front==q->rear) return;
    p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if(q->rear==p) q->rear=q->front;//如果删除的是队尾，要把队尾指向头结点
    free(p);
}
//销毁队列
void DestroyQueue(LinkQueue *q) {
    while(q->front){
        q->rear=q->front->next;
        free(q->front);//释放内存
        q->front=q->rear;
    }
}
bool is_Empty(LinkQueue *q){
    return q->front==q->rear;
}
#endif //ALGORITHM_COMPETITION_LINKQUEUE_H
