//这里是01背包问题的模板，状态表示什么，怎么转移，从哪儿转移过来都非常关键
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int dp[MAXN],V[MAXN],W[MAXN]; //dp[i][j]表示前i个物品，当前体积为j的最大价值 一维dp[j]表示体积小于等于j的最大价值

int main()
{
    freopen("in.txt","r",stdin);
    int N,v;
    cin>>N>>v;
    for(int i=1;i<=N;i++) cin>>V[i]>>W[i];
    //dp[0]=0;for(int i=1;i<=v;i++)dp[i]=INT_MIN; //这个作是表示当恰好为v时的最大价值，只能从0转移过来
    for(int i=1;i<=N;i++)
        //这里一维递减是超级关键的点，因为以前二维是和i-1的状态比较最大值，这里递减，刚好就是前一个状态了，因此可以省略
        //for(int j=v;j>=V[i];j--) //这里循环反过来就是可以用无限次-就是完全背包了，神奇
          for(int j=V[i];j<=v;j++) //完全背包
            dp[j]=max(dp[j],dp[j-V[i]]+W[i]);
    cout<<dp[v]<<endl;
    return 0;
}