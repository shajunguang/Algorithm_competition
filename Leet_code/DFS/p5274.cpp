//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN=1e9+7;
//long long ans=0;
//int len,steps,cur=0,dx[3]={-1,0,1};
//void dfs(int u){
//    if(cur==steps) {
//        if(!u) ans++;
//        return;
//    }
//    for(int i=0;i<3;i++){
//        int tx=u+dx[i];
//        if(tx>=0 && tx<len) {
//            cur++;
//            dfs(tx);
//            cur--;
//        }
//    }
//}
//int main()
//{
//    cin>>steps>>len;
//    dfs(0);
//    cout<<ans%MAXN<<endl;
//    return 0;
//}
//
