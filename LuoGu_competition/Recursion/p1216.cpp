//金字塔寻找最短路径dfs
/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int nums[MAXN][MAXN];
int ans=0,r;
void dfs(int x,int y,int cur){
    if(x==r-1){
        if(cur>ans) ans=cur;
        return;
    }

    dfs(x+1,y,cur+nums[x+1][y]);
    if(y<=x) dfs(x+1,y+1,cur+nums[x+1][y+1]);
}
int main()
{
    cin>>r;
    for(int i=0;i<r;i++)
        for(int j=0;j<=i;j++)
            cin>>nums[i][j];
    dfs(0,0,nums[0][0]);
    cout<<ans<<endl;
    return 0;
}
 */
//dp
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int nums[MAXN][MAXN],f[MAXN][MAXN];
int main()
{
    int r;cin>>r;
    memset(f,0,sizeof f);
    for(int i=0;i<r;i++)
        for(int j=0;j<=i;j++) {
            cin >> nums[i][j];
            if(!i && !j) f[i][j]=nums[i][j];
            if(i && !j) f[i][j]=nums[i][j]+f[i-1][j];
            if(i) f[i][i]=nums[i][i]+f[i-1][i-1];
        }
    for(int i=2;i<r;i++)
        for(int j=1;j<i;j++)
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+nums[i][j];
    int ans=0;
    for(int i=0;i<r;i++) if(f[r-1][i]>ans) ans=f[r-1][i];
    cout<<ans<<endl;
    return 0;
}
