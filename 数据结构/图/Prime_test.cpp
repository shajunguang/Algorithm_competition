#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f

int Prime(vector<vector<int>> Graph,int s,int n){
    vector<int> d(n,INF);//初始化距离数组,表示未处理节点到所有处理节点最短距离
    vector<int> vis(n,0);//访问标记数组
    d[s]=0;
    int sum=0;

    for(int i=0;i<n;i++){
        int u=-1;
        int min=INF;
        for(int j=0;j<n;j++)
            if(!vis[j] && d[j]<min){
                min=d[j];
                u=j;
            }

        if(u==-1) return -1; //图不联通,不存在最小生成树
        vis[u]=1;
        sum+=d[u];

        for(int j=0;j<n;j++)
            if(!vis[j] && Graph[u][j]<d[j]) d[j]=Graph[u][j];
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
    int ans=Prime(Graph,0,n);
    cout<<ans;
    return 0;
}