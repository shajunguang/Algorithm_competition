//
// Created by liu on 19-10-19.
//

//#include<bits/stdc++.h>
//#define local
//using namespace std;
//const int MAXN=100005,sp_num=1000000007;
//int vis[MAXN];
//typedef pair<int,int> PAIR;
//
//struct Cmp{
//    bool operator()(const PAIR& a,const PAIR& b)const{
//        if(a.first==b.first)  return a.second<b.second;
//        return a.first<b.first;
//    }
//};
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    map<PAIR,int,Cmp> graph;
//    int N;
//    cin>>N;
//    int a,b,c;
//    for(int i=1;i<N;i++)
//    {
//        cin>>a>>b>>c;
//        graph[make_pair(a,b)]=c;
//        graph[make_pair(b,a)]=c;
//    }
//    int sum=0;
//    string str;
//    for(int i=1;i<=N;i++)
//    {
//        str += to_string(i);
//        for(auto &c:graph)
//        {
//            if(c.first.first==i)
//                sum +=c.second;
//        }
//    }
//}