/*
 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 思路：使用临时temp存取中间结果，然后更新答案即可
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string chars[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty())  return vector<string>();

        vector<string> state(1,"");
        for(auto u: digits)
        {
            vector<string> now;
            for(auto c: chars[u-'2'])
                for(auto s:state)
                    now.push_back(s+c);
            state = now;
        }

        return state;
    }
};