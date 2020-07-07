#include<bits/stdc++.h>
using namespace std;

void heapAdjust(int q[],int s,int n){
    int i,key;

    key=q[s];

    for(i=2*s+1;i<n;i*=2){
        if(i!=n-1 && q[i]<q[i+1]) i++; //找到孩子中最大的一个,等待交换

        if(key>q[i]) break; //无需交换

        q[s]=q[i];
        s=i; //切换下一个待交换的节点
    }
    q[s]=key; //下沉到合适位置
}

void heapsort(int q[],int n){
    int i;

    //构建大顶堆,由于是完全二叉树,n/2后的都是叶子节点,没有孩子,不需要调整
    for(i=n/2-1;i>=0;i--) heapAdjust(q,i,n);

    //交换根节点

    for(i=n-1;i>0;i--){
        swap(q[i],q[0]);
        heapAdjust(q,0,i);
    }
}

int main()
{
    int i,a[10]={5,2,6,0,3,9,1,7,4,8};

    heapsort(a, 10);

    printf("After sorted: \n");

    for(i=0;i<10;i++) cout<<a[i]<<" ";

    return 0;
}