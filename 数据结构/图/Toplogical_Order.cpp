#include<bits/stdc++.h>
using namespace std;

bool Toplogical_Order(vector<vector<int> >G,int indegree[],int n){
    stack<int> st;

    //初始化栈,入度为0入栈
    for(int i=0;i<n;i++) if(!indegree[i]) st.push(i);

    int count=0;//记录处理的点数

    while(!st.empty()){
        int tmp=st.top();st.pop();
        cout<<tmp<<" ";count++;

        for(int nx : G[tmp]){
            indegree[nx]--;
            if(!indegree[nx]) st.push(nx);
        }
    }
    return count >= n;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> >Graph(100);
    int indegree[100];
    memset(indegree,0,sizeof indegree);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        Graph[a].emplace_back(b);
        indegree[b]++;
    }

    if(!Toplogical_Order(Graph,indegree,n)) cout<<"There is Loop!";

    return 0;
}