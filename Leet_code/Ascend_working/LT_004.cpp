/*
 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 思路：合并排序，时间复杂度O(m+n),空间复杂度O(m+n)
 */
#include<bits/stdc++.h>
using namespace std;
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