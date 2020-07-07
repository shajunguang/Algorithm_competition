#include<bits/stdc++.h>
using namespace std;
int st[26],vis[26];
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        if(m>n) return{};
        for(auto c:p) {st[c-'a']++;vis[c-'a']=1;}
        vector<int> ans;
        int i=0;
        while(i<n){
            int tmp[26];
            memcpy(tmp,st,sizeof tmp);
            int t=0,f=1,start=i;
            while(t<m && i<n){
                int val=--tmp[s[i]-'a'];
                if(val<0) {f=0;break;}
                t++,i++;
            }
            if(f) {ans.push_back(start);i=start+1;}
            else{
                if(!vis[s[i]-'a']) i++;
            }
        }

        return ans;
    }
};

int main()
{
    string s="abab",p="ab";
    Solution res;
    res.findAnagrams(s,p);

    return 0;
}
