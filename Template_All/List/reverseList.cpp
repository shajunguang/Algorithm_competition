#include<bits/stdc++.h>
using namespace std;
struct List{
    int val;
    List* next;
    List(int x):val(x),next(NULL){}
};
//递归版本 拆分为头结点和剩余链表（整体），剩余链表反转（递推），修改指向，头结点指向NULL
List* reverseList(List* head){
    if(head==NULL || head->next==NULL) return head;
    auto temp=head->next;
    auto node=reverseList(temp);
    temp->next=head;
    head->next=NULL;
    return node;
}
vector<int> reverseList2(List* head){
    vector<int> ans;
    head=reverseList(head);
    while(head){
        ans.push_back(head->val);
        head=head->next;
    }
    return ans;
}
vector<int> res;
vector<int> reverseList3(List* head){
    if (head== NULL)return res;
    reverseList3(head->next);
    res.push_back(head->val);
    return res;
}
//迭代版本
List* reverseList1(List* head){
    List* pre=NULL;
    while(head){
        auto temp=head->next;
        head->next=pre;
        pre=head;
        head=temp;
    }
    return pre;
}
int main()
{
    List* head=new List(1);
    auto t=head;
    //构造链表1->2->3->4->5->NULL
    for(int i=2;i<=5;i++){
        auto temp=new List(i);
        t->next=temp;
        t=temp;
    }
   // auto ans=reverseList(head);
    //auto ans=reverseList1(head);
//    while(ans){
//        cout<<ans->val<<" ";
//        ans=ans->next;
//    }
    reverseList3(head);
    return 0;
}