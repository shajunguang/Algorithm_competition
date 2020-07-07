//途中源点到终点最短路径
#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f

//单源算法,边权不能为负
int Dijsktra(vector<vector<int>> G,int v0,int vend,int n){
    vector<int> D(n,0); //表示最短距离
    vector<int> p(n,0); //表示最短路径的前驱节点
    vector<int> final(n,0); //表示源点到该点是否已存在最短路径

    final[v0]=1; //源点0到0为0
    int k=v0; //当前源点

    for(int i=0;i<n;i++) D[i]=G[v0][i]; //初始化其他点到源点的距离

    for(int i=1;i<n;i++){
        int min=INF;
        for(int j=0;j<n;j++)
            if(!final[j] && D[j]<min){
                k=j;
                min=D[j];
            }

        final[k]=1;

        //修正D,p数组

        for(int j=0;j<n;j++){
            if(!final[j] && min+G[k][j]<D[j]){
                D[j]=min+G[k][j];
                p[j]=k;
            }
        }
    }

    //借助前驱p输出最短路径
    cout<<vend<<"->";
    int v=p[vend];
    while(v!=v0){
        cout<<v<<"->";
        v=p[v];
    }
    cout<<v0<<endl;

    return D[vend]==INF?-1:D[vend];
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
    int ans=Dijsktra(Graph,0,n-1,n);

    cout<<ans<<endl;
    return 0;
}