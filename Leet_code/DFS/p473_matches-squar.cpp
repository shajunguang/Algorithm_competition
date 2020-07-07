//
// Created by liu on 19-10-16.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution{
//public:
//
//    vector<bool> st;
//
//    bool makesquare(vector<int>& nums){
//        int sum=0;
//        for(auto u: nums)   sum += u;
//
//        if(!sum || sum %4)  return false;
//
//        sort(nums.begin(),nums.end());
//        reverse(nums.begin(),nums.end());
//
//        st=vector<bool>(nums.size());
//        return dfs(nums,0,0,sum/4);
//    }
//
//    bool dfs(vector<int> & nums, int u,int cur, int length)
//    {
//        if(cur==length) u++,cur=0;
//        if(u==4)    return true;
//
//        for(int i=0;i<nums.size();i++)
//            if(!st[i] && cur + nums[i]<=length)
//            {
//                st[i]=true;
//                if(dfs(nums,u,cur+nums[i],length))  return true;
//                st[i]=false;
//                //剪枝部分
//                if(!cur)    return false;
//                if(cur+nums[i]==length) return false;
//                while(i+1<nums.size() && nums[i+1]==nums[i])    i++;
//            }
//        return false;
//    }
//};
//
//int main()
//{
//    vector<int> nums={1,1,2,2,2};
//    Solution ans;
//    if(ans.makesquare(nums))    cout<<"true";
//    else    cout<<"false";
//    return 0;
//}