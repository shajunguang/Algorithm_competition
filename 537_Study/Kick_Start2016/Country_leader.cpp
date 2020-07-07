#include<bits/stdc++.h>
using namespace std;
int al[26];

int main()
{
    int T,ca=1;
    cin>>T;
    for(;ca<=T;ca++){
        int n;
        cin>>n;
        getchar();
        string ans;
        int t=0;
        memset(al,0,sizeof al);
        for(int i=1;i<=n;i++){
            string s;
            int count=0;
            getline(cin,s);
            for(auto c:s)
                if(c!=' ' && al[c-'A']!=i){
                    al[c-'A']=i;
                    count++;
                }
            if(count>t){
                t=count;
                ans=s;
            }else if(count==t)ans=min(ans,s);
        }
        cout<<"Case #"<<ca<<": "<<ans<<endl;
    }

    return 0;
}