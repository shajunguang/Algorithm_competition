/*
 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 思路，注意特殊情况，前面字符值比后面小，减，其他加即可
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<int,int>hash={
                {'I',1},{'V',5},{'X',10},
                {'L',50},{'C',100},{'D',500},
                {'M',1000}
        };
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && hash[s[i]]<hash[s[i+1]])
                ans-=hash[s[i]];
            else ans+=hash[s[i]];
        }
        return ans;
    }
};