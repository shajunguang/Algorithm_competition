////
//// Created by liu on 19-8-30.
////
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int maxn=20000+10;
//int sz[maxn][3];
//int killed[1024][1024];
//
//int main()
//{
//    int t,d,n;
//    cin>>t;
//    while(t--)
//    {
//        memset(killed,0, sizeof(killed));
//        int max=0,ti,tj;
//        cin>>d>>n;
//        for(int i=0;i<n;i++)    cin>>sz[i][0]>>sz[i][1]>>sz[i][2];
//        for(int k=0;k<n;k++)
//            for(int i=0;i<1024;i++)
//                if(abs(sz[k][0]-i)<=d)
//                    for(int j=0;j<1024;j++)
//                        if(abs(sz[k][1]-j)<=d)
//                            killed[i][j] +=sz[k][2];
//        for(int i=0;i<1024;i++)
//            for(int j=0;j<1024;j++)
//                if(killed[i][j]>=max)
//                    { max=killed[i][j];ti=i;tj=j; }
//        printf("%d %d %d\n",ti,tj,max);
//    }
//
//}