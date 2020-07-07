#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int dp[MAXN];

int main()
{
    int N,V;
    cin>>N>>V;
    for(int i=0;i<N;i++){
        int v,w,s;
        cin>>v>>w>>s;
        for(int j=V;j>=v;j--) //注意这里的逆序,个数不是无限的
            for(int k=1;k<=s && k*v<=j;k++) //这个表示第i个物品去多少个
                dp[j]=max(dp[j],dp[j-k*v]+k*w);
    }
    cout<<dp[V];
    return 0;
}