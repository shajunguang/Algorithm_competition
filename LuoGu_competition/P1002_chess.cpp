//
// Created by liu on 19-9-10.
//

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int ch[25][25];
//long long dp[25][25];
//
//int main()
//{
//    int n,m,hn,hm;
//    cin>>n>>m>>hn>>hm;
//    memset(ch,0, sizeof(ch));
//    ch[hn][hm]=ch[hn-1][hm+2]=ch[hn-1][hm-2]=ch[hn+1][hm+2]=ch[hn+1][hm-2]
//            =ch[hn+2][hm-1]=ch[hn-2][hm-1]=ch[hn+2][hm+1]=ch[hn-2][hm+1]=-1;
//    for(int i=0;i<=n;i++)
//        dp[i][0]=1;
//    for(int j=1;j<=m;j++)
//        dp[0][j]=1;
//    for(int i=0;i<=n;i++)
//        for(int j=0;j<=m;j++)
//        {
//            if(ch[i][j]==-1)
//                dp[i][j]=0;
//            else if(i*j)
//                dp[i][j] =dp[i-1][j]+dp[i][j-1];
//        }
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<=m;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<dp[n][m]<<endl;
//    return 0;
//}

/*
#include <bits/stdc++.h>
using namespace std;
int Const[2][9]={{0,-2,-2,-1,-1,1,1,2,2},{0,1,-1,2,-2,2,-2,1,-1}};
long long dp[21][21]={1};
int b[21][21];
int main(){
  int m,n,hx,hy;
  cin>>n>>m>>hx>>hy;
  for(int i=0;i<=8;i++){
  if(hx+Const[0][i]>=0 &&hx+Const[0][i]<=n && hy+Const[1][i]>=0 &&hy+Const[1][i]<=m)
    b[hx+Const[0][i]][hy+Const[1][i]]=1;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++){
            if(i) dp[i][j]+=dp[i-1][j];
            if(j) dp[i][j]+=dp[i][j-1]; dp[i][j]*=!b[i][j];
}
    cout<<dp[n][m];

}
 * */