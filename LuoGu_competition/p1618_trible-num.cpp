//
// Created by liu on 19-10-10.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int vis[10];
//
//int main()
//{
//    int A,B,C,abc,def,ghi,ff=1;
//    cin>>A>>B>>C;
//    for(abc=123;abc<987;abc++){
//        memset(vis,0,sizeof vis);
//        vis[abc/100]=vis[abc/10%10]=vis[abc%10]=1;
//        if(abc*B % A==0)    def=abc*B/A;
//        else continue;
//        vis[def/100]=vis[def/10%10]=vis[def%10]=1;
//        if(abc*C % A==0)    ghi=abc*C/A;
//        else continue;
//        vis[ghi/100]=vis[ghi/10%10]=vis[ghi%10]=1;
//        int flag=1;
//        for(int i=1;i<=9;i++){
//            if(!vis[i]){
//                flag=0;
//                break;
//            }
//        }
//        if(flag)    { ff=0;cout<<abc<<" "<<def<<" "<<ghi<<endl;}
//    }
//    if(ff)  cout<<"No!!!";
//    return 0;
//}