#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=0;
void dfs(int pos,int sum,int cur){
    if(cur==k){
        if(sum==n) cnt++;
        return;
    }
    for(int i=pos;sum+i<=n;i++) dfs(i,sum+i,cur+1); //sum保证数量递增，不重复，牛
    //这里可以剪枝的地方是sum+i*(k-cur)<=n
}

int main()
{
    cin>>n>>k;
    dfs(1,0,0);
    cout<<cnt;
    return 0;
}