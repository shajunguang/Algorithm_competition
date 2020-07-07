#include <bits/stdc++.h>
using namespace std;
int nums[105];

struct ListNode{
    int val;
    int cost;
    ListNode* prev,*next;
    ListNode():val(0),cost(1),prev(NULL),next(NULL){}
    ListNode(int _x,int _y):val(_x),cost(_y),prev(NULL),next(NULL){}
};

int main()
{
    int n;
    while(cin>>n && n){
        for(int i=0;i<n;i++) cin>>nums[i];
        if(n==2){
            cout<<__gcd(nums[0],nums[1])<<endl;
            continue;
        }
        auto head=new ListNode(nums[0],__gcd(nums[1],nums[n-1]));
        auto tail=new ListNode(nums[n-1],__gcd(nums[n-2],nums[0]));
        //循环链表
        head->next=tail;
        head->prev=tail;
        tail->prev=head;
        tail->next=head;
        auto t=head;
        for(int i=1;i<n-1;i++){
            auto tmp=new ListNode(nums[i],__gcd(nums[i-1],nums[i+1]));
            t->next=tmp;
            tmp->prev=t;
            tmp->next=tail;
            tail->prev=tmp;
            t=tmp;
        }
        int ans=0;
        for(int i=0;i<n-2;i++){
            auto t1=head;
            ListNode* temp=t1;
            int min=INT_MAX;
            while(t1!=tail){
                if(t1->cost<min) min=t1->cost,temp=t1;
                t1=t1->next;
            }
            if(t1->cost<min) min=t1->cost,temp=t1;
            ans+=min;
            auto l=temp->prev;auto r=temp->next;
            l->next=r;
            r->prev=l;
            if(temp==head) head=r;
            else if(temp==tail) tail=l;
            free(temp);
            if(l->prev!=r) {
                l->cost = __gcd(l->prev->val, r->val);
                r->cost = __gcd(l->val, r->next->val);
            }
        }
        ans+=__gcd(head->val,tail->val);
        cout<<ans<<endl;
    }

    return 0;
}

