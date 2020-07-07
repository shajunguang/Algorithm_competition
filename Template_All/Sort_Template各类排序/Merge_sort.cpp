#include<bits/stdc++.h>
using namespace std;

template <typename comparable>
void merge(vector<comparable> &a,vector<comparable> &tmp,int left,int right,int end){
    int tmpPos = left;
    int leftEnd = right-1;
    int num = end-left+1;
    //O(n)合并两个子数组直到一个子数组遍历完
    while(left<=leftEnd && right<=end){
        if(a[left]<=a[right]) tmp[tmpPos++]=a[left++];
        else tmp[tmpPos++]=a[right++];
    }
    //处理剩余数
    while(left<=leftEnd) tmp[tmpPos++]=a[left++];
    while(right<=end) tmp[tmpPos++]=a[right++];
    //结果返回给原数组
    while(num--) a[end]=tmp[end],end--;
}
//下面是不停二分数组，递归调用环节O(lgn)
template <typename comparable>
void Mergesort(vector<comparable> &a,vector<comparable> &tmp,int left,int right){
    if(left<right){
        int mid = left+right>>1;
        Mergesort(a,tmp,left,mid);
        Mergesort(a,tmp,mid+1,right);
        merge(a,tmp,left,mid+1,right);
    }
}
//简单写法
void merge_sort(int nums[], int left, int right){
    if(left>=right)return ;
    int mid=left+right>>1; //l+(r-l)>>1
    merge_sort(nums,left,mid);
    merge_sort(nums,mid+1,right);

    //合并过程
    int k=left,l=left,r=mid+1; //两边起始位置
    while(k<=right){
        if(r>right || (l<=mid && nums[l]<=nums[r])) tmp[k++]=nums[l++];
        else tmp[k++]=nums[r++]; //小的放进外界数组
    }
    for(int i=left;i<=right;i++) nums[i]=tmp[i]; //填回去
}
//朴素写法
void merge_sort(int q[], int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    //合并过程
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] < q[j]) tmp[k++] = q[i++]; //借助外界数组，记得外面定义
        else tmp[k++] = q[j++];

    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}