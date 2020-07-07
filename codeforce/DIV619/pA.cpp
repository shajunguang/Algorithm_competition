#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;
        int flag=1;
        for(int i=0;i<(int)a.size();i++)
            if(c[i]!=a[i] && c[i]!=b[i]){
                flag=0;
                break;
            }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}