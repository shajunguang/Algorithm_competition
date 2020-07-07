//
// Created by liu on 19-9-25.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//    int hIndex(vector<int>& citations) {
//        if(citations.empty())   return 0;
//        int n = citations.size();
//        int l=0,r=n-1;
//        while(l<r){
//            int mid = l+r+1>>1;
//            if(citations[mid]<=n-mid)   l=mid;
//            else r=mid-1;
//        }
//        if(!r){
//            if(citations[r]>0)  return 1;
//            else return 0;
//        }
//        if(citations[r])
//            return n-r;
//        else return 0;
//    }
//};
//
//int main()
//{
//    Solution a;
//    vector<int> nums;
//    nums.push_back(0),nums.push_back(0);
//    cout<<a.hIndex(nums);
//}