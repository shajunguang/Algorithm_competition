#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> str[1000];
    for(int i=0;i<n;i++){
       string s;
       cin>>s;
       str[s.size()].push_back(s);
    }
    for(auto s:str) sort(s.begin(),s.end());
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        int sz=s.size(),f=1;
        int pos=lower_bound(str[sz].begin(),str[sz].end(),s)-str[sz].begin();
        for(int j=max(0,pos-2);j<min(pos+3,(int)str[sz].size());j++){
            int count=0;
            for(int h=0;h<sz;h++) if(s[h]!=str[sz][j][h]) count++;
            if(count==1) {cout<<"YES"<<endl;f=0;break;}
        }
        if(f) cout<<"NO"<<endl;
    }
    return 0;
}