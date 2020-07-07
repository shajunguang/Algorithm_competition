//
// Created by liu on 19-10-13.
//

//#include <bits/stdc++.h>
////#define local
//using namespace std;
//
//const int MAXN=1005;
//int kl[MAXN],ll[MAXN],vis[MAXN]; //kl表示行能解救的个数,ll列能解救个数
//vector<int> k_ans,l_ans;
//
//int max_i(int *a,int n){
//    int MAX=INT_MIN,j=0;
//    for(int i=1;i<n;i++)
//        if(a[i]>MAX && !vis[i])
//            {j=i;MAX=a[i];}
//    vis[j]=1;
//    return j;
//}
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    memset(kl,0,sizeof kl);
//    memset(ll,0,sizeof ll);
//    int M,N,K,L,D,x,y,p,q;
//    cin>>M>>N>>K>>L>>D;
//    for(int i=0;i<D;i++){
//        cin>>x>>y>>p>>q;
//        if(x==p)    ll[min(y,q)]++;
//        else    kl[min(x,p)]++;
//    }
//    memset(vis,0,sizeof vis);
//    for(int i=0;i<K;i++){
//        k_ans.push_back(max_i(kl,M));
//    }
//    sort(k_ans.begin(),k_ans.end()); //后面发现排序可以省掉
//    int ii=0;
//    for(auto i:k_ans){
//        if(ii++)    cout<<" ";
//        cout<<i;
//    }
//    cout<<endl;
//    memset(vis,0,sizeof vis);
//    for(int i=0;i<L;i++){
//        l_ans.push_back(max_i(ll,N));
//    }
//    sort(l_ans.begin(),l_ans.end());
//    int ij=0;
//    for(auto i:l_ans){
//        if(ij++)    cout<<" ";
//        cout<<i;
//    }
//    return 0;
//}