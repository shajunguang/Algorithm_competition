//判断链表是否存在环
//两种方法，一种是快慢指针，另一种暴力遍历
#include "LinkList.h"

//暴力遍历，双指针 O(n^2)
void is_Loop(LinkList Node){
    LinkList p=Node;
    LinkList q=Node;
    int i=1,j;
    while(p){
        p=p->next;
        for(j=0;j<i;j++) {
            if(q==p){
                printf("存在环！位置在%d\n",j+1);
                return;
            }
            q=q->next;
        }
        q=Node;
        i++;
    }
    printf("不存在环！");
}
//快慢指针O(n)
void is_Loop1(LinkList Node){
    LinkList p=Node;
    LinkList q=Node;
    while(p && q && q->next){
        p=p->next;
        q=q->next->next;
        if(p==q) {cout<<"存在环！";return;}
    }
    cout<<"不存在环！";
}

int main()
{
    Node* head=new Node(0);
    createListTail(head,5);
    auto temp=head;
    while(temp->next) temp=temp->next;
    temp->next=head->next->next;
    is_Loop1(head);
    return 0;
}