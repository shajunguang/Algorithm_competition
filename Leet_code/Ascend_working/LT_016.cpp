/*
 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
 找出 nums 中的三个整数，使得它们的和与 target 最接近。
 返回这三个数的和。假定每组输入只存在唯一答案。
 思路：一样，排序双指针，这次统计的答案是更加接近
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size(),ans=INT_MAX,res;
        for(int i=0;i<n-2 && nums[i]<target/3;i++){
            if(i &&nums[i]==nums[i-1]) continue;
            int sum=nums[i];
            int l=i+1,r=n-1;
            while(l<r){
                if(l>i+1 && nums[l]==nums[l-1]) {l++;continue;}
                int tmp=sum+nums[l]+nums[r];
                if(abs(tmp-target)<ans) ans=abs(tmp-target),res=tmp;
                //cout<<res<<endl;
                if(tmp==target) return tmp;
                else if(tmp<target) l++;
                else r--;
            }
        }
        return res;
    }
};