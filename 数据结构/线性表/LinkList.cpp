#include "LinkList.h"

int main()
{
    Node* head=new Node(0);
    createListTail(head,10);
    cout<<GetElem(head,2)<<endl;
    head=InsertList(head,2,3);
    head=ListDelete(head,2);
    auto mid=GetMedianElem(head);
    cout<<mid->data<<endl;
    return 0;
}