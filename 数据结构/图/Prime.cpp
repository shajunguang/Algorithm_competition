//首先的明白最小生成树的定义是,经过所有顶点,并且不能有圈
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f;
int Prime(vector<vector<int>> G,int n,int s){
    vector<int> d(n,INF);
    vector<bool> vis(n,false);
    d[s]=0; //初始点自己到自己的距离
    int sum=0;//最小生成树的边权和
    //最小生成树
    for(int i=0;i<n;i++){//n个顶点
        int u=-1;
        int min=INF;//寻找最小相邻点
        for(int j=0;j<n;j++)
            if(!vis[j] && d[j]<min){
                min=d[j];
                u=j;
            }
        if(u==-1) return -1; //图不连通
        vis[u]=true;
        if(u!=s) printf("%d\n",u);
        sum+=d[u];
        //由于d一直是处于更新状态,因此这一步是将与未处理的点与处理的点的权值取到最小以备用
        for(int j=0;j<n;j++)
            if(!vis[j] && G[u][j]!=INF && G[u][j]<d[j]) d[j]=G[u][j];
    }
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> Graph(n,vector<int>(n,INF));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Graph[a][b]=Graph[b][a]=c;
    }
    cout<<Prime(Graph,n,0);
    return 0;
}