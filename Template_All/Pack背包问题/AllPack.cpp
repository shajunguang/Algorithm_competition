#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
int dp[MAXN];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int v,w;
        cin>>v>>w;
        for(int j=v;j<=m;j++)
            dp[j]=max(dp[j],dp[j-v]+w);
    }
    cout<<dp[m];
    return 0;
}