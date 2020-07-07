/*
 * 1~N的N个人按顺时针方向围坐一圈，每个人持有一个密码，开始人选择其作为上限值M,顺时针报数M个，出列，并
 * 以其密码值作为新的上限M，一直下去，记录出列顺序.
 */
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int order;
    int M;
    Node* next;
};

void creatList(Node **p){
    int N;
    cin>>N;
    Node* rear; //尾指针
    Node* temp;
    for(int i=1,M;i<=N;i++){
        cin>>M;
        if(*p==NULL) {
            *p=(Node*)malloc(sizeof(Node));
            (*p)->order=i;(*p)->M=M;
            (*p)->next=*p;
            rear=*p;
        }else{
            temp=(Node*)malloc(sizeof(Node));

            temp->order=i;
            temp->M=M;
            rear->next=temp;
            temp->next=*p;
            rear=temp;
        }
    }
}

int main()
{
    Node* p=NULL;
    creatList(&p);
    Node* temp=p;
    int i,M=temp->M;
    Node* rear=p;
    while(rear->next!=p) rear=rear->next;
    while(temp->next!=temp){
        for(i=1;i<M-1;i++) temp=temp->next;
        Node* q;
        if(M==1 && temp==p) {
            q=temp;
            rear->next=q->next;
            p=q->next;
        }
        else {
            q=temp->next;
            temp->next=q->next;
        }
        cout<<q->order<<" ";
        temp=q->next;
        M=q->M;
        free(q);
    }
    cout<<temp->order;
    return 0;
}