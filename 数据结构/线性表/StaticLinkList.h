
#ifndef ALGORITHM_COMPETITION_STATICLINKLIST_H
#define ALGORITHM_COMPETITION_STATICLINKLIST_H
//线性表的静态链表存储结构，游标法
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
typedef int ElemType;
typedef struct {
    ElemType data;
    int cur;
}Component, StaticLinkList[MAXN];

//初始化链表
void InitLinkList(StaticLinkList space){
    int i;
    for(i=0;i<MAXN-1;i++) space[i].cur=i+1;
    space[MAXN-1].cur=0;
}
//获取空闲游标位置
int Malloc_SLL(StaticLinkList space){
    int i=space[0].cur;
    if(space[0].cur) space[0].cur=space[i].cur; //游标记录的是指向下一个元素的位置

    return i;
}
//插入元素e在第i数据之前
int InsertList(StaticLinkList space,int i,ElemType e){
    int j,k,l;
    k=MAXN-1; //处于头指针的位置
    if(i<1 || i>MAXN)return -1;
    j=Malloc_SLL(space);
    if(j){
        space[j].data=e;
        for(l=1;l<i;l++) k=space[k].cur;//找到i-1的游标，即指针，需要修改的
        space[j].cur=space[k].cur; //然后赋值给新插入的游标
        space[k].cur=j; //另外自己的游标改为j
        return 1;
    }
    return -1;
}
//释放空间,收回当备用链表
void Free_SLL(StaticLinkList space,int i){
    space[i].cur=space[0].cur;
    space[0].cur=i;
}
//删除第i个数据
int ListDelete(StaticLinkList L,int i,ElemType *e){
    int j,k;
    if(i<1 || i>MAXN)return -1;
    k=MAXN-1;
    for(j=1;j<i;j++) k=L[k].cur;
    j=L[k].cur;
    *e=L[j].data;
    L[k].cur=L[j].cur;

    Free_SLL(L,j);
    return 1;

}
//获得链表长度
int ListLength(StaticLinkList L){
    int j=0;
    int i=L[MAXN-1].cur;
    while(i){
        i=L[i].cur;
        j++;
    }
    return j;
}
#endif //ALGORITHM_COMPETITION_STATICLINKLIST_H
