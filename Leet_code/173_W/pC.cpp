#include <bits/stdc++.h>
using namespace std;
struct city{
    int id;
    int num;
}c[105];
bool cmp(const city&a ,const city&b){
    if(a.num==b.num) return a.id>b.id;
    return a.num<b.num;
}
class Solution {
public:
    int n,num;
    int graph[105][105];
    int vis[105];
    void dfs(int x,int cur,int dis){
        if(cur>dis) return;
        for(int i=0;i<n;i++)
            if(!vis[i] && graph[i][x]){
                vis[i]=1;
                if(cur+graph[i][x]<=dis)num++;
                dfs(i,cur+graph[i][x],dis);
            }
    }
    int findTheCity(int _n, vector<vector<int>>& edges, int dis) {
        n=_n;
        memset(graph,0,sizeof graph);
        for(auto e:edges)
            graph[e[0]][e[1]]=graph[e[1]][e[0]]=e[2];
        for(int i=0;i<n;i++) {
            memset(vis,0,sizeof vis);
            num=0,vis[i]=1,c[i].id=i,dfs(i,0,dis),c[i].num=num,cout<<c[i].num<<endl;
        }
        sort(c,c+n,cmp);
        return c[0].id;
    }
};
int main()
{
    vector<vector<int>> edges={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    Solution res;
    cout<<res.findTheCity(4,edges,4);
    return 0;
}