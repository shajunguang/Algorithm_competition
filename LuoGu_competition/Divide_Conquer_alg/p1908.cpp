#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int nums[MAXN],tmp[MAXN];
long long ans=0;
//合并排序
void merge_sort(int left, int right){
    if(left>=right)return ;
    int mid=left+right>>1; //l+(r-l)>>1
    merge_sort(left,mid); //左排序
    merge_sort(mid+1,right); //右排序

    //合并过程
    int k=left,l=left,r=mid+1;
    while(k<=right){
        if(r>right || (l<=mid && nums[l]<=nums[r])) tmp[k++]=nums[l++];
        else tmp[k++]=nums[r++],ans+=mid-l+1; //小的放进外界数组
        //这里若nums[l]>nums[r]就是逆序对,由于左边已经排好序,因此逆序对个数是mid-r+1
    }
    for(int i=left;i<=right;i++) nums[i]=tmp[i]; //填回去
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>nums[i];
    merge_sort(0,n-1);
    cout<<ans;
    return 0;
}