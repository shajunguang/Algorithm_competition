#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        string s,s1,s2,ans;
        cin>>s;
        int flag=0;
        int pos=0;
        for(int i=0;i<(int)s.size();i++)
            if(s[i]=='+') {pos=i;break;}
        if(pos==0 || pos==s.size()-1) {cout<<"skipped"<<endl;continue;}
        s1=s.substr(0,pos);s2=s.substr(pos+1);
        for(char i : s1)if(!isdigit(i)) {flag=1;break;}
        for(char i : s2)if(!isdigit(i)) {flag=1;break;}
        if(flag || (s1[0]=='0'&&s1.size()>1) || (s2[0]=='0'&&s2.size()>1)) cout<<"skipped"<<endl;
        else{
            string ans;
            reverse(s1.begin(),s1.end());reverse(s2.begin(),s2.end());
            if(s2.size()>s1.size()) swap(s1,s2);
            int t=0,i;
            for(i=0;i<s2.size();i++){
                t+=s1[i]-'0'+s2[i]-'0';
                ans+='0'+t%10;
                t=t/10;
            }
            if(s1.size()<=i) {if(t>0) ans+=t+'0';}
            else{
                    while(i<s1.size()) {
                        t+=s1[i]-'0';
                        ans+='0'+t%10;
                        t=t/10;
                        i++;
                    }
                    if(t) ans+='0'+t;
                }
            reverse(ans.begin(),ans.end());cout<<ans<<endl;
        }
    }
    return 0;
}