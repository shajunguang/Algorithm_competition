//记忆化搜索加递归
#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int Map[MAXN][MAXN],dp[MAXN][MAXN];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0},ans=0,r,c;
int dfs(int x,int y){
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y]=1;//初始化为1
    for(int i=0;i<4;i++){
        int tx=x+dx[i],ty=y+dy[i];
        if(tx>=0 && tx<r && ty>=0 && ty<c && Map[tx][ty]<Map[x][y]){
            dfs(tx,ty);
            //计算好tx,ty的下滑最大距离，记得状态转移.
            dp[x][y]=max(dp[x][y],dp[tx][ty]+1);
        }
    }
    return dp[x][y];
}

int main()
{
    cin>>r>>c;
    memset(Map,0,sizeof Map);
    memset(dp,-1,sizeof dp);
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>Map[i][j];
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)ans=max(ans,dfs(i,j));
    cout<<ans;
    return 0;
}