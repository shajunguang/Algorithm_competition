#ifndef ALGORITHM_COMPETITION_LINKSTACK_H
#define ALGORITHM_COMPETITION_LINKSTACK_H
#include<bits/stdc++.h>
using namespace std;
typedef int Elemtype;
typedef struct StackNode{
    Elemtype data;
    StackNode* next;
}StackNode,*LinkStackPtr;
typedef struct LinkStack{
    LinkStackPtr top;
    int count; //元素个数
}LinkStack;
//push操作
void push(LinkStack *s,Elemtype e){
    auto t=(LinkStackPtr)malloc(sizeof(StackNode));
    t->data=e;
    t->next=s->top,s->top=t;
    s->count++;
}
//pop操作
void pop(LinkStack *s,Elemtype *e){
    if(s->top==NULL) return;
    LinkStackPtr p;
    *e=s->top->data;
    p=s->top;
    s->top=p->next;
    free(p);
    s->count--;
}
#endif //ALGORITHM_COMPETITION_LINKSTACK_H
