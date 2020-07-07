//Kruskal最小生成树,针对边查找的,稀疏图优势大
#include <bits/stdc++.h>
using namespace std;
const int MAXN=100;

struct edges{
    int begin;
    int end;
    int w;
}eg[MAXN];

bool cmp(edges &a,edges &b){
    return a.w<b.w;
}

int Find(vector<int> p,int n){

    while(p[n]>0) n=p[n]; //寻找祖先节点,如果两个相邻的节点找到一样的祖先节点,说明存在环
    return n;
}

int Kruskal(int m){ //m是边的数量
    vector<int> parent(m,0);//初始化每个点最短路径的终点,可用来判断是否存在环
    int sum=0;

    for(int i=0;i<m;i++){
        int a=Find(parent,eg[i].begin);
        int b=Find(parent,eg[i].end);

        if(a!=b){
          parent[a]=b;
          printf("%d %d %d\n",eg[i].begin,eg[i].end,eg[i].w);
          sum+=eg[i].w;
        }
    }
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    if(m<n+1){
        cout<<"Graph is not unicom!";
    }
    for(int i=0;i<m;i++){
        cin>>eg[i].begin>>eg[i].end>>eg[i].w;
    }
    sort(eg,eg+m,cmp);

    int sum=Kruskal(m);
    cout<<sum;
    return 0;
}
