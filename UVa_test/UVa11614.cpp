#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        long long n;cin>>n;
        long long glta=sqrt(1+8*n);
        cout<<(glta-1)/2<<endl;
    }
    return 0;
}