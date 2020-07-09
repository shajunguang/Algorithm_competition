/*
 编写一个函数来查找字符串数组中的最长公共前缀。
 思路：寻找公共长度即可 O(mn),也可以用字典树，字典树建树时间是O(mn)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int pref_len=strs[0].size();
        for(int i=1;i<strs.size();i++){
            int m_len=0;
            for(int j=0;j<strs[i].size();j++,m_len++)
                if(strs[i][j]!=strs[0][j]) break;
            if(!m_len) return "";
            pref_len=min(pref_len,m_len);
        }
        return strs[0].substr(0,pref_len);
    }
};