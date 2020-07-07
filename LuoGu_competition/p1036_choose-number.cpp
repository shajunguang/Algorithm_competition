//
// Created by liu on 19-10-9.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int x[25],color[25],n,k;
//long long res=0;
//
//bool is_prime(int n){
//    int m=sqrt(n+0.5);
//    for(int i=2;i<=m;i++)
//        if(n%i==0)  return false;
//    return true;
//}
//
//void dfs(int m,int sum,int startx){
//    if(m==k){
//        if(is_prime(sum))   res++;
//        return;
//    }
//    for(int i=startx;i<n;i++)
//    {
//        if(color[i])
//            continue;
//        color[i]=1;
//        dfs(m+1,sum+x[i],i+1);
//        color[i]=0;
//    }
//    return;
//}
//
//int main()
//{
//    cin>>n>>k;
//    for(int i=0;i<n;i++)
//        cin>>x[i];
//    memset(color,0,sizeof color);
//    dfs(0,0,0);
//    cout<<res;
//    return 0;
//}