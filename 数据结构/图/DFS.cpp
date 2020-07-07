#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3;
vector<vector<int>> gra(MAXN);
int flag[MAXN];
void dfs(int u){
    flag[u]=1;
    for(int i=0;i<(int)gra[u].size();i++){
        int nx=gra[u][i];
        if(flag[nx])continue;
        dfs(nx);
    }
}
void bipa_check(int u,int level){ //二分图 顶点两个集合,内部不连通,可以标记为01
    flag[u]=level%2;
    for(int i=0;i<(int)gra[u].size();i++){
        int nx=gra[u][i];
        if(flag[nx]==flag[u]){
            cout<<"not bipartite graph"<<endl;
            exit(0);
        }else if(flag[nx]==-1){bipa_check(nx,level+1);
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a-=1;b-=1;
        gra[a].emplace_back(b);
        gra[b].emplace_back(a);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(!flag[i]){ans++;
            dfs(i);
        }
    }
    cout<<"connected component "<<ans<<endl;
    //bipartite graph check
    memset(flag,-1,sizeof(flag));
    for(int i=0;i<n;i++){
        if(flag[i]==-1){
            bipa_check(i,0);
        }
    }
    cout<<"bipartite graph"<<endl;
    return 0;
}