#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
int nums[MAXN],ans=INT_MIN,n;
int tree[MAXN][MAXN],vis[MAXN];
//void dfs(int x,int cur){
//    int flag=1;
//    for(int i=1;i<=n;i++) if(tree[x][i]) {flag=0;break;}
//    if(flag){
//        if(cur>ans) ans=cur;
//        return;
//    }
//    for(int i=1;i<=n;i++)
//        if(!vis[i] && tree[x][i] && cur+nums[i]>0){
//            vis[i]=1;
//            dfs(i,cur+nums[i]);
//            vis[i]=0;
//        }
//}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>nums[i];
    memset(tree,0,sizeof tree);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a][b]=tree[b][a]=1;
    }
    //memset(vis,0,sizeof vis);
    //vis[1]=1;
    //dfs(1,nums[1]);
    cout<<ans<<endl;
    return 0;
}