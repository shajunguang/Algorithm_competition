//
// Created by liu on 19-9-20.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int base_two(int n){  // 手写的计算2的阶乘,不想用pow（嗯）
//    int sum=1;
//    for(int i=0;i<n;i++)
//        sum *=2;
//    return sum;
//}
//// 递归过程,重要的是知道触底条件
//void print(int n){
//    if(n==1)
//        { printf("2(0)"); return;}
//    if(n==2)
//        { printf("2"); return; }
//    if(n==3)
//        { printf("2+2(0)"); return; }  // 萌新第一次没加这个,总是把3打印成2(2(0))+2(0)
//    int t;
//    // 这里找到最接近n的幂次,准备打印
//    for(int i=2;i<=15;i++)
//        if(base_two(i)>n){
//            printf("2("); //从左开始打印
//            t=i-1;
//            break;
//        }
//    print(t);
//    printf(")"); // 结束高阶打印
//    if(n-base_two(t)==0)    return; // 由于前面寻找的t没考虑相等情况,相等其实结束了
//    printf("+");
//    print(n-base_two(t));  //打印剩余部分
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//    print(n);
//    return 0;
//}