#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string ans="I hate ";
    for (int i = 1; i < n; i++) {
            if(i%2) ans+="that I love ";
            else ans+="that I hate ";
        }
    ans+="it";
    cout<<ans<<endl;
    return 0;
}