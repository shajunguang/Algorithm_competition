//多重背包问题的优化--二进制优化
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
int dp[MAXN];

int main()
{
    int N,V;
    cin>>N>>V;
    for(int i=0;i<N;i++){
        int v,w,s;
        cin>>v>>w>>s;
        //将s二进制化,下面是二进制思路
        for(int j=1;j<=s;j*=2){
            for(int k=V;k>=j*v;k--) //将该物品进行选择
                dp[k]=max(dp[k],dp[k-j*v]+j*w);
            s-=j;
        }
        if(s>0){
            for(int k=V;k>=s*v;k--)
                dp[k]=max(dp[k],dp[k-s*v]+s*w);
        }
    }
    cout<<dp[V];
    return 0;
}