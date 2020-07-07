//
// Created by liu on 19-10-11.
//

//#include <bits/stdc++.h>
//#define local
//using namespace std;
//
//int status[10][100000],weak[10];
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    int n,a,b,c,Case=0;
//    while(cin>>n && n){
//        for(int i=0;i<n;i++){
//            cin>>a>>b>>c;
//            weak[i]=a;
//            for(int j=a+b-c+2;j<100000;j+=a+b){
//                for(int k=j;k<j+a;k++)
//                    status[i][k]=1;  //表示听课
//                for(int kk=j+a;kk<j+a+b;kk++)
//                    status[i][kk]=0; //表示睡觉
//            }
//            for(int j=1;j<a+b-c+2;j++){
//                status[i][j]=status[i][j+a+b];
//            }
//        }
//        int j;
//        for(j=1;j<100000;j++){ //j为时间轴
//            int sum=0; //sum来表示醒着的人数
//            for(int i=0;i<n;i++){ //i为学生号
//                sum +=status[i][j];
//            }
//            if(sum==n)  break;
//            for(int i=0;i<n;i++){
//                if(status[i][j] && !status[i][j+1] && n-sum<=sum)
//                    for(int k=j+1;k<weak[i]+1+j;k++)
//                        status[i][k]=1;
//            }
//        }
//        if(j<100000)
//            cout<<"Case "<<++Case<<": "<<j<<endl;
//        else
//            cout<<"Case "<<++Case<<": "<<"-1"<<endl;
//    }
//    return 0;
//}