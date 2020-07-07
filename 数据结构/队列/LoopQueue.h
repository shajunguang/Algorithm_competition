
#ifndef ALGORITHM_COMPETITION_LOOPQUEUE_H
#define ALGORITHM_COMPETITION_LOOPQUEUE_H
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
    ElemType *base;
    int front;
    int rear;
}LoopQueue;
//初始化
void initQueue(LoopQueue *q){
    q->base=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    if(!q->base) exit(0);
    q->front=q->rear=0;
}
//入队
void InsertQueue(LoopQueue *q,ElemType e){
    if((q->rear+1)%MAXSIZE==q->front) return; //追尾，队列满了
    q->base[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
}
//出队
void PopQueue(LoopQueue *q,ElemType *e){
    if(q->front==q->rear) return; //队列已经空了
    *e=q->base[q->front];
    q->front=(q->front+1)%MAXSIZE;
}
#endif //ALGORITHM_COMPETITION_LOOPQUEUE_H
