#include<bits/stdc++.h>
using namespace std;
char code[26],vis[26],vis1[26]; //vis1用来说明字母是否在原信息出现

int main()
{
    string s1,s2,s;
    cin>>s1>>s2>>s;
    memset(code,0,sizeof code);
    memset(vis,0,sizeof vis);
    if(s1.size()!=s2.size()) cout<<"Failed";
    else{
        for(int i=0;i<s1.size();i++){
            if(!isalpha(code[s1[i]-'A']) && !vis[s1[i]-'A'])
                code[s1[i]-'A']=s2[i],vis[s1[i]-'A']=1,vis1[s2[i]-'A']=1;
            else if(code[s1[i]-'A']==s2[i]) continue;
            else { cout<<"Failed";return 0;}
        }
        for(auto str:s1) if(!vis1[str-'A']) {cout<<"Failed";return 0;}
        for(auto str:code) if(!isalpha(str)) {cout<<"Failed";return 0;}
        string ans;
        int flag=1;
        for(char i : s){
            if(isalpha(code[i-'A'])) ans+=code[i-'A'];
            else {flag=0;cout<<"Failed";break;}
        }
        if(flag) cout<<ans;
    }
    return 0;
}