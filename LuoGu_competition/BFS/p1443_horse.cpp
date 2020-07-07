#include<bits/stdc++.h>
using namespace std;
const int MAXN=405;
int ans[MAXN][MAXN];
typedef pair<int,int> PII;
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
queue<PII> q;
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    q.push(make_pair(a,b));
    memset(ans,-1,sizeof ans);
    ans[a][b]=0;
    int nm=max(n,m);
    while(!q.empty()){
        auto f=q.front();q.pop();
        int x=f.first,y=f.second;
        for(int i=0;i<8;i++){
            int tx=x+dx[i],ty=y+dy[i];
            if(tx>0 && tx<=n && ty>0 && ty<=m && ans[tx][ty]==-1 && ans[x][y]<=nm){
                q.push(make_pair(tx,ty));
                ans[tx][ty]=ans[x][y]+1;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}