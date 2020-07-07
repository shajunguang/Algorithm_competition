//
// Created by liu on 19-9-9.
//

//#include <iostream>
//#include <algorithm>
//#include "Heap.h"
//using namespace std;
//
//const int N=11;
//
//struct node{
//    int id;
//    int start;
//    int finish;
//} A[N+1];
//
//bool cmp(node a,node b){
//    return a.finish < b.finish;
//}
//
////最大堆
//int H[N+1];
//
//
//void Greedy()
//{
//    sort(A+1, A+N+1, cmp);
//    int i, ret = 0;
//    for(i = N;i>=1;i--)
//    {
//        int temp = Heap_Maximum(H);
//        if(temp < A[i].finish)
//        {
//            ret++;
//            Max_Heap_Insert(H, A[i].start);
//        }
//        else
//        {
//            Heap_Extract_Max(H);
//            Max_Heap_Insert(H,A[i].start);
//        }
//
//    }
//    cout<<ret<<endl;
//}
//
///*
//1 4
//3 5
//0 6
//5 7
//3 8
//5 9
//6 10
//8 11
//8 12
//2 13
//12 14
//*/
//int main()
//{
//    int i;
//    //输入测试数据
//    for(i = 1; i <= N; i++)
//    {
//        A[i].id = i;
//        cin>>A[i].start>>A[i].finish;
//    }
//    //贪心算法
//    Greedy();
//    return 0;
//}
