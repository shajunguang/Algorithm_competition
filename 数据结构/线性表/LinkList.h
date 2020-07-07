
#ifndef ALGORITHM_COMPETITION_LINKLIST_H
#define ALGORITHM_COMPETITION_LINKLIST_H
//链式线性表，虽然插入删除需要先O(n)找到删除和插入位置，但是对于频繁的删除和插入操作，只需要一次找到
//位置，插入和删除都是O(1)
#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    Node* next;
    Node(ElemType x):data(x),next(NULL){}
}Node;
typedef struct Node* LinkList;

//创建链表，头插法
void createListHead(LinkList &head,int n){
    LinkList p;
    srand(time(0));
    head=(LinkList) malloc(sizeof(Node)); //这种方法int值默认取0
    head->next=NULL;
    for(int i=0;i<n;i++){
        p=(LinkList) malloc(sizeof(Node));
        p->data=rand()%100+1;  //随机产生1-100数
        p->next=head->next;
        head->next=p;
    }
}

//创建链表，尾插法
void createListTail(LinkList &head,int n){
    LinkList p,s;
    srand(time(0));
    head=(LinkList) malloc(sizeof(Node));
    s=head;
    for(int i=0;i<n;i++){
        p=(LinkList) malloc(sizeof(Node));
        p->data=rand()%100+1;
        s->next=p;
        s=p;
    }
    s->next=NULL; //最后指向NULL
}

//获取链表第i个元素的值O(n)
ElemType GetElem(LinkList head,int i){
    if(head==NULL) return -1;
    int j=1;
    LinkList temp=head->next;
    while(j<i && temp){
        temp=temp->next;
        j++;
    }
    if(temp==NULL) return -1;
    return temp->data;
}

//插入一个节点在i前
LinkList InsertList(LinkList head,int i,ElemType e){
    LinkList p=head->next;
    int j=1;
    while(p && j<i){
        p=p->next;
        j++;
    }
    if(p==NULL || j>i) return head;
    Node* q=new Node(e);
    q->next=p->next;
    p->next=q;
    return head;
}

//删除第i个节点
LinkList ListDelete(LinkList head,int i){
    if(head==NULL) return head;
    LinkList p=head->next;
    int j=1;
    while(p && j<i){
        p=p->next;
        j++;
    }
    if(!(p->next) || j>i) return head;
    p->next=p->next->next;

    return head;

}

//删除列表
void ClearList(LinkList &head){
    LinkList p,q;
    p=head->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    head->next=NULL;
}
//获取未知长度链表的中间元素
LinkList GetMedianElem(LinkList head){
    if(head==NULL || head->next==NULL) return head;
    if(head->next->next==NULL) return head;
    LinkList mid=head;LinkList search=head;
    while(search->next){
        mid=mid->next;
        search=search->next;
        if(search->next==NULL) break;
        search=search->next;
    }
    return mid;
}
#endif //ALGORITHM_COMPETITION_LINKLIST_H
