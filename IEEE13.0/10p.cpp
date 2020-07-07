//
// Created by liu on 19-10-20.
//

//#include <bits/stdc++.h>
//#define local
//using namespace std;
//const int MAXN=105;
//int pos[MAXN][MAXN],vis[MAXN][MAXN],sum=0,M,N,t_i,t_j,num=0;
//int idx[6]={0,-1,-1,0,1,1};
//int idy[6]={-1,0,1,1,1,0};
//typedef pair<int,int> PIRR;
////vector<PIRR> red;
//queue<PIRR> stk;
//
//void bfs(int u,int v)
//{
//    stk.push(make_pair(u,v));
//    //red.push_back(make_pair(u,v));
//    vis[u][v]=1;
//    sum +=6;
//    while(!stk.empty())
//    {
//        auto t=stk.front();
//        stk.pop();
//        int flag=1;
//        for(int i=0;i<6;i++)
//        {
//            int x=t.first+idx[i],y=t.second+idy[i];
//            if(!vis[x][y] && x>0 && x<=N && y>0 && y<=M && pos[x][y])
//            {
//                flag=0;
//                vis[x][y]=1;
//                sum +=4;
//                stk.push(make_pair(x,y));
//                //red.push_back(make_pair(x,y));
//                num++;
//            }
//        }
//        if(flag)    return;
//    }
//}
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    int Q;
//    cin>>N>>M;
//    for(int i=1;i<=N;i++)
//    {
//        if(i%2){
//            for(int j=1;j<=M;j++)
//                cin>>pos[i][j];
//        }
//        else{
//            for(int j=1;j<M;j++)
//                cin>>pos[i][j];
//        }
//    }
//    cin>>Q;
//    char c;int si,sj;
//    for(int i=0;i<Q;i++)
//    {
//        sum=0;
//        memset(vis,0,sizeof vis);
//        cin>>c>>si>>sj;
//        if(c=='a')  pos[si][sj]=1;
//        else if(c=='k'){
//            if(!pos[si][sj])    cout<<"0"<<endl;
//            else{
//                t_i=si,t_j=sj;
//                bfs(si,sj);
//                cout<<sum-num<<endl;
//            }
//        }
//    }
//    return 0;
//}