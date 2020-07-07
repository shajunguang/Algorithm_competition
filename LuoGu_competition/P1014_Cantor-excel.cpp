//
// Created by liu on 19-9-23.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    long long  N;
//    int f1=1,f=0; //f1用于判断到达边界,f用于是到的行还是列
//    int i=1;      //i计数器
//    int r=1;      //r表示到达的行数
//    int c=1;      //c表示到达的列数
//    cin>>N;
//    while(i!=N){
//        if(f1){
//            if(r==1){
//                c++;i++;f=1;f1=0;  //到达第一行,往前走，并跳出判断i是否到达N
//                continue;
//            }
//            else if(c==1){
//                r++;i++;f=0;f1=0;  //到达第一列,往下走，并跳出判断i是否到达N
//                continue;
//            }
//        }
//        if(f){  //若起始在第一行，开始回溯到第一列
//            while(c!=1) {
//                r++;c--;i++;
//                if(i==N)    break;  //判断i是否到达N,很关键
//            }
//        }else{  //若起始在第一列，开始回溯到第一行
//            while(r!=1) {
//                c++;r--;i++;
//                if(i==N)    break;  //判断i是否到达N,很关键
//            }
//        }
//        f1=1;  //将状态回到第一行或者第一列,因为前面回溯到第一行或第一列
//    }
//    printf("%d/%d",r,c);
//    return 0;
//}