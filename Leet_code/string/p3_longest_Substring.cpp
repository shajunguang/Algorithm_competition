//
// Created by liu on 19-10-8.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        if(s.empty())   return 0;
//        int res=1;
//        for(int i=0;i<s.size();i++){
//            for(int j=i+1;j<s.size();j++){
//                string temp=s.substr(i,j-i);
//                //cout<<temp<<endl;
//                int pos = temp.find(s[j]);
//                if(pos==s.npos) {
//                    if(j-i+1>res)   res=j-i+1;
//                }
//                else    break;
//            }
//        }
//        return res;
//    }
//
//    int lengthOfLongestSubstring1(string s) {
//        unordered_map<char,int> hash;
//        int res=0;
//        for(int i=0,j=0;i<s.size();i++)
//        {
//            hash[s[i]]++;
//            while(hash[s[i]]>1) hash[s[j++]]--;
//            res = max(res,i-j+1);
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    string s("pwwkew");
//    Solution ans;
//    cout<<ans.lengthOfLongestSubstring1(s)<<endl;
//}