#include<bits/stdc++.h>

#define HASHSIZE 12
#define  NULLKEY -32768

typedef struct{
    int *elem;  //数据元素的基址.动态分配数组
    int count;
}HashTable;

int InitHashTable(HashTable *H){
    H->count = HASHSIZE;
    H->elem = (int *)malloc(HASHSIZE*sizeof(int));

    if(!H->elem) return -1;
    for(int i=0;i<HASHSIZE;i++) H->elem[i]=NULLKEY;

    return 0;
}

//使用除留余数法
int Hash(int key){
    return key%HASHSIZE;
}

void InsertHash(HashTable *H,int key){
    int addr;

    addr = Hash(key);

    //冲突解决,开放寻址线性解决
    while(H->elem[addr] !=NULLKEY)
        addr=(addr+1)%HASHSIZE;

    H->elem[addr]=key;
}

//散列表查找关键字
int SearchHash(HashTable H,int key,int* addr){
    *addr = Hash(key);

    while(H.elem[*addr]!=key){
        *addr=(*addr+1)%HASHSIZE;
        if(H.elem[*addr]==NULLKEY || *addr == Hash(key)) return -1;
    }

    return 0;
}

int main()
{
    HashTable H;
    InitHashTable(&H);
    int a[4]={1,2,3,13};
    for(int i=0;i<4;i++) InsertHash(&H,a[i]);

    int addr;
    SearchHash(H,13,&addr);

    return 0;
}