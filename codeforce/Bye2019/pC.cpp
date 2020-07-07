// x,y x+y y -> x+y+x+y x+y -> x+y = 2*(x+y)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--) {
        cin >> n;
        long long x=0,y=0,a;
        for (int i = 0; i < n; i++) cin >> a, x += a, y ^= a;
        if(x==(y<<1))cout<<0<<endl<<endl;
        else cout<<2<<endl<<y<<" "<<x+y<<endl;
    }
    return 0;
}