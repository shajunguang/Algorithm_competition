//寻找两个链表交点
#include<bits/stdc++.h>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* Listintersect(ListNode* headA,ListNode* headB){
    ListNode* t1=headA;
    ListNode* t2=headB;

    while(t1!=t2){
        if(!t1) t1=headB;
        else t1=t1->next;

        if(!t2) t2=headA;
        else t2=t2->next;
    }

    return t1;
}