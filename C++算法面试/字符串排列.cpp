#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty()) return{};
        int len=str.size();
        sort(begin(str),end(str));
        vector<string>ans;
        ans.push_back(str);
        while(1){
            int r=len-1;
            int l;
            while(r>=1 && str[r-1]>=str[r]) r--;
            if(r==0) break; //完全倒序，最后一个
            l=r;
            while(l<len&&str[l]>str[r-1]) l++;
            swap(str[l-1],str[r-1]);
            reverse(str.begin()+r,str.end());
            ans.push_back(str);
        }
        return ans;
    }
};
int main()
{
    string str="abc";
    Solution res;
    res.Permutation(str);
    return 0;
}