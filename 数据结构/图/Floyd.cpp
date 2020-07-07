//该算法能求出所有节点直接的最短距离
//而且非常简洁,利用的传递式是D1[i][j]=min(D0[i][j],D0[i][k]+D0[k][j]) //贪心思想
//简单证明就是,i到j的最短路径必定是经过k,或不经过k中选一个
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f

int Floyd(vector<vector<int>> G,int n){
    vector<vector<int>> D(n,vector<int>(n,0)); //表示i到j的最短路径
    vector<vector<int>> p(n,vector<int>(n,0)); //表示i到j的下一个节点

    //初始化D,P
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            D[i][j]=G[i][j];
            p[i][j]=j;
        }

    for(int k=0;k<n;k++) //第一层循环的意思借助k这个点,路径是否会变短
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(D[i][k]+D[k][j]<D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    p[i][j]=p[i][k]; //这个前驱有点东西的!
                }
    cout<<D[0][5]<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> Graph(n,vector<int>(n,INF));
    for(int i=0;i<n;i++) Graph[i][i]=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Graph[a][b]=Graph[b][a]=c;
    }

    Floyd(Graph,n);
    return 0;
}