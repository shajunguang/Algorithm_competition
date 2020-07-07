/*
 给定一个整数数组 nums 和一个目标值 target，
 请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 思路：hash存储数和下标 O(n) O(n)
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            int t=target-nums[i];
            if(hash.count(t)!=0) return{i,hash[t]};
            hash[nums[i]]=i;
        }
        return {};
    }
};

int main()
{
    cout<<"hello world"<<endl;
}