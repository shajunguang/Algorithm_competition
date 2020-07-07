#include "Double_LinkList.h"

void createList(DualNode* &head){
    head=(DualNode*)malloc(sizeof(DualNode));
    head->data=0;
    auto rear=head;
    rear->next=head;
    rear->prior=head;
    for(int i=1;i<26;i++){
        auto temp=(DualNode*)malloc(sizeof(DualNode));
        temp->data=i;
        rear->next=temp;
        temp->next=head;
        temp->prior=rear;
        rear=temp;
        head->prior=rear;
    }
}
void print_order(DualNode* head,int n){
    int i=1;
    auto temp=head;
    if(n>=0)
        while(i<=n) temp=temp->next,i++;
    else
        while(i<=abs(n)) temp=temp->prior,i++;

    for(int j=0;j<26;j++){
        char c='A'+temp->data;
        cout<<c;
        temp=temp->next;
    }
}
int main()
{
    int n;
    cin>>n;
    DualNode* head=NULL;
    createList(head);
    print_order(head,n%26);
    return 0;
}