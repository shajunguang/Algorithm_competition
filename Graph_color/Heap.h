//
// Created by liu on 19-9-9.
//

#ifndef ALGORITHM_COMPETITION_HEAP_H
#define ALGORITHM_COMPETITION_HEAP_H

#include <iostream>
#include <stdio.h>
using namespace std;

#define PARENT(i)   (i)>>1
#define LEFT(i) (i)<<1
#define RIGHT(i)    ((i)<<1)+1

int length = 0; //数组中的个数
int heap_size = 0; //初始队中的元素个数

//最大堆的维护
void Max_Heapify(int *A, int i){
    int l = LEFT(i), r=RIGHT(i),largest;
    if(l<=heap_size && A[l]>A[i])
        largest =l;
    else largest = i;
    if(r<heap_size && A[r]>A[largest])
        largest = r;
    if(largest !=i)
    {
        int t=A[i];
        A[i]=A[largest];
        A[largest]=t;
        Max_Heapify(A,largest);
    }
}

//优先队列处理函数
void Heap_Increase_Key(int *A, int i, int key){
    if(key<A[i])
    {
        cout<<"New key is smaller than current key."<<endl;
        exit(0);
    }
    A[i]=key;
    while(A[PARENT(i)] > 0 && A[PARENT(i)]<A[i]){
        int t=A[PARENT(i)];
        A[PARENT(i)]=A[i];
        A[i]=t;
        i = PARENT(i);
    }
}

//把key插入到集合A中
void Max_Heap_Insert(int *A, int key){
    if(heap_size==99)
    {
        cout<<"Heap is full."<<endl;
        exit(0);
    }
    heap_size++;length++;
    A[heap_size] = -0x7fffffff;
    Heap_Increase_Key(A, heap_size, key);
}

int Heap_Maximum(int *A){
    return A[1];
}

//返回A中的最大关键字，时间O(lgn)
int Heap_Extract_Max(int *A){
    if(heap_size<1)
    {
        cout<<"Heap underflow"<<endl;
        exit(0);
    }
    int max = A[1];
    A[1] = A[heap_size];
    heap_size--;
    Max_Heapify(A,1);
    return max;
}

//删除堆中的第i个元素
void Heap_Delete(int *A,int i){
    if(i>heap_size)
    {
        cout<<"There is no node i"<<endl;
        exit(0);
    }
    int key = A[heap_size];
    heap_size--;
    if(key>A[i])
        Heap_Increase_Key(A,i,key);
    else{
        A[i]=key;
        Max_Heapify(A,i);
    }

}

#endif //ALGORITHM_COMPETITION_HEAP_H
