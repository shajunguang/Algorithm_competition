/*
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
 使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组
 思路：排序后改为两数求和，注意答案要不同，因此前后一样可以跳过，同样内存循环也可跳过
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty())return{};
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2 && nums[i]<=0;i++){
            if(i && nums[i]==nums[i-1]) continue;
            int target=-nums[i];
            int l=i+1,r=n-1;
            while(l<r){
                int tmp=nums[l]+nums[r];
                if(l>i+1 && nums[l]==nums[l-1]) {l++;continue;}
                //cout<<tmp<<" "<<target<<endl;
                if(tmp==target) {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(tmp<target) l++;
                else r--;
            }
        }
        return ans;
    }
};