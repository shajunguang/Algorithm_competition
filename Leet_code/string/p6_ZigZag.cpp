//
// Created by liu on 19-10-8.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//    string convert(string s, int numRows) {
//        if(numRows==1)  return s;
//        int n = s.size(), m=2*numRows-2;
//        string res;
//        for(int i=0;i<numRows;i++){
//            int j=i;
//            while(j<n){
//                res += s[j];
//                if(i>0 && i<numRows-1 && j+m-i*2<n)
//                    res += s[j+m-i*2];
//                j += m;
//            }
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    string s("LEETCODEISHIRING");
//    Solution ans;
//    cout<<ans.convert(s,3)<<endl;
//}