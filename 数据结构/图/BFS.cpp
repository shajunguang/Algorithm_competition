#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3;
vector<vector<int> > Graph(MAXN);
int flag[MAXN];
void bfs(int x){
    queue<int> q;
    q.push(x);
    flag[x]=1;
    while(!q.empty()){
        int t=q.front();q.pop();
        cout<<t<<" ";//访问顺序
        for(int i=0;i<(int)Graph[t].size();i++){
            int nx=Graph[t][i];
            if(flag[nx]) continue;
            flag[nx]=1;
            q.push(nx);
        }
    }
}

int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a-=1,b-=1;
        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
    }
    int ans=0;
    for(int i=0;i<n;i++)
        if(!flag[i]) ans++,bfs(i);
    cout<<endl;
    cout<<"connected component "<<ans<<endl;

    return 0;
}