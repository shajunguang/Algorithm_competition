//
// Created by liu on 19-10-11.
//

//#include <bits/stdc++.h>
//#define local
//using namespace std;
//
//int H[20][20],V[20][20],n;
//
//int is_square(int len){
//    int sum=0;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            if(H[i][j]==H[i+len][j] && H[i][j]==1 && V[j][i]==V[j+len][i] && V[j][i]==1){
//                int k=j+1,k1=i+1,flag=1;
//                while(k<=len){
//                    if(H[i][k]!=1 || H[i+len][k]!=1)
//                    {
//                        flag=0;
//                        break;
//                    }
//                    k++;
//                }
//                while(k1<=len){
//                    if(V[j][k1]!=1 || V[j+len][k1]!=1)
//                    {
//                        flag=0;
//                        break;
//                    }
//                    k1++;
//                }
//                if(flag)    sum++;
//            }
//        }
//    }
//    return sum;
//}
//
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    int m,a,b,p_no=0;
//    char c;
//    while(cin>>n>>m){
//        memset(H,0,sizeof H);
//        memset(V,0,sizeof V);
//        while(m--){
//            cin>>c>>a>>b;
//            if(c=='H') H[a][b]=1;
//            else    V[a][b]=1;
//        }
//        if(p_no++)    cout<<"\n**********************************\n\n";
//        cout<<"Problem #"<<p_no+1<<endl<<endl;
//        int ff=1;
//        for(int i=1;i<=n;i++)
//        {
//            if(is_square(i)){
//                ff=0;
//                cout<<is_square(i)<<" square (s) of size "<<i<<endl;
//            }
//        }
//        if(ff)  cout<<"No completed squares can be found."<<endl;
//    }
//    return 0;
//}