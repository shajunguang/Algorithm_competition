//斐波那契数列
#include<iostream>
using namespace std;
long long f[51];

int main()
{
    int n,a,b;
    cin>>n;
    f[1]=1,f[2]=1;
    for(int i=3;i<51;i++) f[i]=f[i-1]+f[i-2];
    while(n--){
        cin>>a>>b;
        cout<<f[b-a+1]<<endl;
    }

    return 0;
}