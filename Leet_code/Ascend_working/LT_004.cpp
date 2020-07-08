/*
 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 思路：合并排序，时间复杂度O(m+n),空间复杂度O(m+n)
 */
#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        //cout<<m<<n;
        vector<int> a(m+n,0);
        int i=0,j=0,t=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]) a[t++]=nums1[i++];
            else a[t++]=nums2[j++];
        }
        while(i<m) a[t++]=nums1[i++];
        while(j<n) a[t++]=nums2[j++];
        if(t%2) return a[t/2];
        return (a[t/2]+a[t/2-1])/2.0;
    }
};
 */
//二分递归思路
class Solution {
public:
    int find_k(vector<int>&nums1,int i,vector<int>&nums2,int j,int k){
        //cout<<nums1.size()<<" "<<i<<" "<<nums2.size()<<" "<<j<<" "<<k<<endl;
        if(nums1.size()-i>nums2.size()-j) return find_k(nums2,j,nums1,i,k);
        if(k==1){
            cout<<nums1.size()<<endl;
            if(nums1.empty()) return nums2[j];
            else{
                return min(nums1[i],nums2[j]);
            }
        }
        if(i==(int)nums1.size()) return nums2[j+k-1];
        int si=min((int)nums1.size(),i+k/2),sj=j+k-k/2;
        if(nums1[si-1]>nums2[sj-1])
            return find_k(nums1,i,nums2,sj,k-(sj-j));
        else return find_k(nums1,si,nums2,j,k-(si-i));
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot=nums1.size()+nums2.size();
        if(tot%2==0){
            int left=find_k(nums1,0,nums2,0,tot/2);
            int right=find_k(nums1,0,nums2,0,tot/2+1);
            return (left+right)/2.0;
        }else
            return find_k(nums1,0,nums2,0,tot/2+1);
    }
};
int main()
{
    vector<int>nums1={2};vector<int>nums2;
    Solution res;
    cout<<res.findMedianSortedArrays(nums1,nums2);
    return 0;
}