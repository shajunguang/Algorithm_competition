#ifndef ALGORITHM_COMPETITION_LINEARARRAY_H
#define ALGORITHM_COMPETITION_LINEARARRAY_H
//线性表的顺序存储，插入和删除都是O(n)操作
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Elemtype;
typedef struct {
    Elemtype num[MAXN];
    int length;
}sqlist;

//插入元素*e到i前面
Status InsertList(sqlist *L,Status i,Elemtype e){
    if(L->length==MAXN) return ERROR;
    if(i<0 || i>=L->length) return ERROR;
    int k;
    for(k=L->length-1;k>=i;k--)
        L->num[k+1]=L->num[k];
    L->num[i]=e;
    L->length++;

    return OK;
}

//删除第i位置的元素
Status ListDelete(sqlist *L,Status i){
    if(L->length==0) return ERROR;
    if(i<0 && i>=L->length) return ERROR;
    int k;
    for(k=i+1;k<L->length;k++) L->num[k-1]=L->num[k];
    L->length--;

    return OK;
}

//打印元素
Status ListPrint(sqlist *L){
    if(L->length==0){
        cout<<"ERROR!";
        return ERROR;
    }
    int i;
    for(i=0;i<L->length;i++) cout<<L->num[i]<<" ";
    cout<<endl;

    return OK;
}
#endif //ALGORITHM_COMPETITION_LINEARARRAY_H
