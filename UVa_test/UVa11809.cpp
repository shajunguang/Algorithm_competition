////
//// Created by liu on 19-6-24.
////
//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <cstring>
//
//using namespace std;
//
//double M[11][33];	//存储对应尾数
//long long E[11][33];	//存储对应指数
//const double min_differ=1e-5;	//设置误差
//void solve(double m,long long e);
//
//int main()
//{
//    int i,j;
//    double m,t;
//    long long e;
//    char str[22];
//    for(i=0;i<=9;i++)
//        for(j=1;j<=30;j++)
//        {
//            e=(1<<j)-1;		//根据上述公式打表，每一个对应位的尾数和指数分别存储
//            m=1-1.0/(1<<(i+1));
//            t=log10(m)+e*log10(2);
//            E[i][j]=t/1;
//            M[i][j]=pow(10,t-E[i][j]);
//        }
//    while(cin>>str,strcmp(str,"0e0"))
//    {
//        *(strchr(str,'e'))=' ';		//将字符串中的e替换成空格
//        sscanf(str,"%lf %lld",&m,&e);	//运用sscanf巧妙分割尾数和指数
//        solve(m,e);
//    }
//
//    return 0;
//}
//void solve(double m,long long e)	//把匹配过程放到函数中，匹配后可以及时中断
//{
//    int i,j;
//    for(i=0;i<=9;i++)
//        for(j=1;j<=30;j++)
//            if(e==E[i][j]&&fabs(m-M[i][j])<min_differ)	//当指数等于表中所给并且尾数差值绝对值小于误差时即匹配，输出答案，跳出函数
//            {
//                cout<<i<<" "<<j<<endl;
//                return;
//            }
//}
