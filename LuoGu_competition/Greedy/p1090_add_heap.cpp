#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;

int main()
{
    int n;
    cin>>n;
    int num;
    for(int i=0;i<n;i++) cin>>num,q.push(num);
    long long sum=0;
    while(q.size()!=1){
        int a1=q.top();q.pop();
        int a2=q.top();q.pop();
        sum+=a1+a2;q.push(a1+a2);
    }
    cout<<sum<<endl;
    return 0;
}