//求01背包问题的方案数,方案数注意一点初始化都为1
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const int MOD=1e9+7;
int dp[MAXN],f[MAXN];

int main()
{
    int N,V;
    cin>>N>>V;
    for(int i=0;i<=V;i++) dp[i]=1;
    while(N--){
        int v,w;
        cin>>v>>w;
        for(int j=V;j>=v;j--){
            int value=f[j-v]+w;
            if(f[j]<value) dp[j]=dp[j-v],f[j]=value;
            else if(f[j]==value) dp[j]=(dp[j]+dp[j-v])%MOD;
        }
    }
    cout<<dp[V];
    return 0;
}