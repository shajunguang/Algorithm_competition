//分组背包问题,其实就是三次循环,第三次判断组中所有背包那种更大
//多重背包就可以理解为分组背包特殊情况,因为它是把v,2*v,3*v...分在一组,只能选一个
#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int dp[MAXN];

int main()
{
    int N,V;
    cin>>N>>V;
    while(N--){
        int n;
        cin>>n;
        vector<pair<int,int> >goods;
        while(n--){
            int v,w;
            cin>>v>>w;
            goods.emplace_back(v,w);
        }
        for(int j=V;j>=0;j--)
            for(auto good:goods)
                if(j>=good.first)dp[j]=max(dp[j],dp[j-good.first]+good.second);
    }
    cout<<dp[V];
    return 0;
}