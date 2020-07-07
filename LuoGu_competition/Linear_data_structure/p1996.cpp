//约瑟夫问题
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++) nums[i]=i;
    int count=0,r=0,s=n;
    while(count<n){
       cout<<nums[(r+m-1)%s]+1<<" ";
       nums.erase(nums.begin()+(r+m-1)%s);
       r=(r+m-1)%s;
       s--;
       count++;
    }
    return 0;
}
 */
//队列方法
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,e=1,f=0;
    cin>>n>>m;
    queue<int> q;
    for(int i=1;i<=n;i++)q.push(i);
    while(!q.empty()){
        if(e==m){
            cout<<q.front()<<" ";
            q.pop();
            e=1;
        }else{
            q.push(q.front());q.pop();
            e++;
        }
    }
    return 0;
}