//方案f[n][m]=f[n-1][m-v[i]]+w[i]
//说明第n个物品选择了,但这样输出的顺序是字典序不一定是最小的
//因此可以反过来思路,将f[i][j]表示为第i个物品到n个物品体积为j时价值
//转移方程就变为了f[i][j]=max(f[i+1][j],f[i+1][j-v[i]]+w[i])
//分别表示第i个物品不选,第i个物品选择,因此求解时就需要倒过来了,因为要保证上一层是最优解了
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int f[N][N];
int v[N],w[N];
int n,m;
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> v[i] >> w[i];
    for(int i = n ; i >= 1 ; i --)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            f[i][j] = f[i + 1][j];
            if(j >= v[i])
                f[i][j] = max(f[i][j],f[i + 1][j - v[i]] + w[i]);
        }
    }
    int cur_v = m;
    for(int i = 1 ; i <= n ; i++)
    {   //如果是最后一个元素，特判一下，防止越界即可
        if(i == n && cur_v >= v[i])
        {
            printf("%d ",i);
            break;
        }
        if(cur_v <= 0)
            break;
        //判断下标是否越界
        if(cur_v - v[i]>=0 && f[i][cur_v] == f[i + 1][cur_v - v[i]] + w[i]){
            printf("%d ",i);
            cur_v = cur_v - v[i];//选了第i个物品，剩余容量就要减小。
        }
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int dp[MAXN][MAXN],w[MAXN],v[MAXN];

int main()
{
    int N,V;
    cin>>N>>V;
    for(int i=1;i<=N;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=N;i++)
        for(int j=0;j<=V;j++) {
            dp[i][j]=dp[i-1][j]; //注意这里,不选择的情况
            if(j>=v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }

    int vol=V;
    vector<int> ans;
    for(int i=N;i>=1;i--)
        if(dp[i][vol]==dp[i-1][vol-v[i]]+w[i]){
            ans.push_back(i);
            vol-=v[i];
        }
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    return 0;
}
*/