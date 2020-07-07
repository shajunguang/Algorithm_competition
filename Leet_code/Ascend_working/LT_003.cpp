/*
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 思路：使用hash保证字符串元素不同，双指针并不断记录答案
 出现一样元素，将头指针移到相同元素前面位置，同时删除移掉的元素
 O(n) O(n)
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int res=0;
        for(int i=0,j=0;i<s.size();i++)
        {
            hash[s[i]]++;
            while(hash[s[i]]>1) hash[s[j++]]--;
            res = max(res,i-j+1);
        }
        return res;
    }
};