////
//// Created by liu on 19-8-30.
////
//
//#include <iostream>
//#define LOCAL
//using namespace std;
//
//int main()
//{
//#ifdef LOCAL
//    freopen("in.txt","r",stdin);
//#endif
//    int t,n,p,s[25],sum;
//    cin>>t;
//    while(t--){
//        int flag=1;
//        cin>>n>>p;
//        for(int i=0;i<p;i++)    cin>>s[i];
//        for(int i=0;i<(1<<p);i++){
//            sum=0;
//            for(int j=0;j<p;j++)
//                if(i & (1<<j))
//                    sum += s[j];
//            if(sum==n)  { printf("YES\n"); flag=0; break; }
//        }
//        if(flag)    printf("NO\n");
//    }
//}