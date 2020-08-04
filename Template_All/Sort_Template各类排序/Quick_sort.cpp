#include<bits/stdc++.h>
using namespace std;
class Base{
public:
    int print(int a,int b){
        return 1;
    }
};
class C:public Base{
public:
    double print(int a,int b){
        return 2.0;
    }
};
template <typename comparable>
//选择快排主元，一半都小于，一半都大于
const comparable& median(vector<comparable> &a,int left,int right){
    int mid = left+right>>1;
    if(a[mid]<a[left]) swap(a[mid],a[left]);
    if(a[left]>a[right]) swap(a[left],a[right]);
    if(a[mid]>a[right]) swap(a[mid],a[right]);
    // left位置的值小于等于pivot，right位置的值一定大于等于pivot，
    // 要分割的数组变成left+1到right-1
    swap(a[mid],a[right-1]); //将pivot放到right-1位置处
    return a[right-1];
}
template <typename comparable>
void Quicksort(vector<comparable> &a,int left,int right){
    if(left+1<right){
        auto pivot = median(a,left,right);
        int i=left,j=right-1;
        while(1){
            while(a[++i]<pivot){}
            while(a[--j]>pivot){}
            if(i<j) swap(a[i],a[j]);
            else break;
        }
        swap(a[i],a[right-1]);
        //对子数组递归
        Quicksort(a,left,i-1);
        Quicksort(a,i+1,right);
    }else if(left<right) if(a[left]>a[right]) swap(a[left],a[right]); //只有两个元素特殊情况
}
//另一种简单写法
void quick_sort(vector<int>&q,int l,int r){
    if(l>=r) return;

    int i=l-1,j=r+1, x=q[l+r>>1]; //每次取中间数为主元
    while(i<j){ //调整主元两边序列分别小于和大于
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    for(auto n:q) cout<<n<<" ";
    cout<<endl;
    quick_sort(q,l,j),quick_sort(q,j+1,r);
}

void quickSort(vector<int>& nums,int l,int r){
    if(l>=r) return;
    int i=l,j=r;
    int base=nums[l];
    while(i<j){
        while(i<j && nums[j]>=base) j--;
        while(i<j && nums[i]<=base) i++;
        if(i<j) swap(nums[i],nums[j]);
    }
    nums[l]=nums[i];
    nums[i]=base;
    for(auto n:nums) cout<<n<<" ";
    cout<<endl;
    quickSort(nums,l,i-1);
    quickSort(nums,i+1,r);
}
int main()
{
    vector<int>nums={4,3,2,5,1};
    //quickSort(nums,0,nums.size()-1);
    C* ptr= new C();
    cout<<ptr->print(0,0);
    return 0;
}