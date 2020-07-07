#include<bits/stdc++.h>
using namespace std;
#define lf(root) 2*root+1
//#define rt(root) 2*root+2
template <typename comparable>
// 堆排序辅助函数
// v是存储堆的数组，i是要下沉的节点，n代表当前堆的大小
void siftDown(vector<comparable> &a,int i,int n){
    int child;
    auto tmp=a[i];
    while(lf(i)<n){
        child=lf(i); //左子节点
        //寻找最大子节点
        if(child!=n-1 && a[child]<a[child+1]) child++;
        if(tmp<a[child]) {//子节点上移
            a[i]=a[child];
            i=child;
        }else break;
    }
    a[i]=tmp; //下沉到正确位置
}
template <typename comparable>
void Heapsort(vector<comparable> &a){
    //建堆，从n/2开始，因为叶子节点不需要下沉，O(n)时间
    for(int i=a.size()/2-1;i>=0;i--) siftDown(a,i,a.size());

    for(int i=a.size()-1;i>0;i--){
        swap(a[i],a[0]); //交换根节点与最右子节点
        siftDown(a,0,i); //下沉根节点
    }
}