/*
 给出两个 非空 的链表用来表示两个非负的整数。
 其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字
 思路：模拟加法，注意最后的x大于0，别漏了 O(n) O(1)
 */
#include<bits/stdc++.h>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto t=new ListNode(0);
        t->next=NULL;
        auto ans=t;
        int x=0;
        while(l1||l2 || x){
            int a=(l1?l1->val:0)+(l2?l2->val:0);
            auto tmp=new ListNode((a+x)%10);
            x=(a+x)/10;
            t->next=tmp;
            t=tmp;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return ans->next;
    }
};