
#ifndef ALGORITHM_COMPETITION_DOUBLE_LINKLIST_H
#define ALGORITHM_COMPETITION_DOUBLE_LINKLIST_H
//双向链表
#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct DualNode{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode,*DuLinkList;

//初始化操作和单链表类似，只不过注意前驱要记得链接上
//i前面插入操作
void Insert(DualNode* head,int i,ElemType d){
    int j=1;
    auto temp=head;
    while(j<i) temp=temp->next,j++;
    auto p=(DualNode*)malloc(sizeof(DualNode));
    p->data=d;
    p->prior=temp->prior; //先搭再拆
    p->next=temp;
    temp->prior->next=p;
    temp->prior=p;
}
//删除操作
void Delete(DualNode* head,int i){
    int j=1;
    auto temp=head;
    while(j<i) temp=temp->next,j++;
    auto p=temp;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
}
#endif //ALGORITHM_COMPETITION_DOUBLE_LINKLIST_H
