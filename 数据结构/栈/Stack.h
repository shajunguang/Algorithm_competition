#ifndef ALGORITHM_COMPETITION_STACK_H
#define ALGORITHM_COMPETITION_STACK_H
//栈的顺序存储结构
#include<bits/stdc++.h>
using namespace std;

#define Stack_Init_Size 100
#define Stack_Increment 10
typedef char ElemType;
typedef struct {
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;
//初始化栈
void initStack(sqStack *s){
    s->base=(ElemType*)malloc(Stack_Init_Size*sizeof(ElemType));
    if(!s->base) exit(0);
    s->top=s->base;
    s->stackSize=Stack_Init_Size;
}
//push操作
void Push(sqStack *s,ElemType e) {
    if (s->top - s->base >= s->stackSize) {
        s->base = (ElemType *) realloc(s->base, (s->stackSize + Stack_Increment) * sizeof(ElemType));
        if (!s->base)exit(0);
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + Stack_Increment;
    }
    *(s->top)=e; //push element e
    s->top++;
}
//pop操作
void Pop(sqStack *s,ElemType *e){
    if(s->top==s->base) return;
    *e = *--(s->top);
}
//清空栈
void Clear(sqStack *s){
    s->top=s->base;
}
//销毁栈
void destroy(sqStack *s){
    int i,len;
    len=s->stackSize;
    for(i=0;i<len;i++){
        free(s->base);
        s->base++;
    }
    s->top=s->base=NULL;
    s->stackSize=0;
}
//获取栈的容量
int StackLen(sqStack s){
    return (s.top-s.base);
}
#endif //ALGORITHM_COMPETITION_STACK_H
