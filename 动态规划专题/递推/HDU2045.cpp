//经典RPG三种颜色涂,相邻不同,首尾不同
#include <bits/stdc++.h>
using namespace std;
long long f[51];

int main()
{
    int n;
    f[1]=3,f[2]=6,f[3]=6;
    for(int i=4;i<51;i++) f[i]=f[i-1]+f[i-2]*2;
    while(cin>>n){
        cout<<f[n]<<endl;
    }

    return 0;
}