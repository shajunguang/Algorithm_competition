//
// Created by liu on 19-10-19.
//

//#include <bits/stdc++.h>
//#define local
//using namespace std;
//
//const int MAXN=100005;
//int A[MAXN],S[MAXN];
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    int n,m;
//    cin>>n>>m;
//    for(int i=0;i<n;i++)
//        cin>>A[i];
//    for(int j=0;j<m;j++)
//        cin>>S[j];
//    sort(S,S+m);
////    for(auto i:S)   cout<<i<<" ";
////    cout<<endl;
//    int pos=0;
//    for(int i=0;i<m;i++)
//    {
//        int flag=1;
//        for(int j=pos;j<n;j++)
//        {
//            if(A[j]>=S[i])
//            {
//                flag=0;
//                cout<<S[i]<<" ";
//                pos=j;
//                break;
//            }
//            else
//                cout<<A[j]<<" ";
//            pos=j+1;
//        }
//        if(flag)    cout<<S[i]<<" ";
//    }
//    for(int i=pos;i<n;i++)
//        cout<<A[i]<<" ";
//    return 0;
//}