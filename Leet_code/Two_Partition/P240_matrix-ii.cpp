//
// Created by liu on 19-9-24.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//
//        //二分查找
////        if(matrix.empty() || matrix[0].empty()) return false;
////        int m = matrix.size(), n = matrix[0].size();
////        int l=0, r=m-1;
////        while(l<r){
////            int mid = l+r>>1;
////            if(matrix[mid][0]>=target)  r=mid;
////            else l=mid+1;
////        }
////        if(matrix[r][0]==target)    return true;
////        else{
////            for(int i=0;i<=r;i++){
////                int ll=0,rr=n-1;
////                while(ll<rr){
////                    int mid = ll+rr>>1;
////                    if(matrix[i][mid]>=target)  rr=mid;
////                    else ll=mid+1;
////                }
////                if(matrix[i][rr]==target)   return true;
////            }
////            return false;
////        }
//
//        // O(m+n)
//        if(matrix.empty() || matrix[0].empty()) return false;
//        int m = matrix.size(), n = matrix[0].size();
//        int r=m-1, c=0;
//        while(r>=0 && c<n){
//            if(matrix[r][c]>target) r--;
//            else if(matrix[r][c]<target)    c++;
//            else    return true;
//        }
//        return false;
//    }
//};
//
//int main()
//{
//    Solution ans;
//    vector<int> list;
//    vector<vector<int>> m;
//    list.push_back(-1),list.push_back(2);
//    m.push_back(list);
//    if(ans.searchMatrix(m,3))   cout<<"true";
//    else    cout<<"false";
//}