#include<bits/stdc++.h>
using namespace std;
int pow_mod(int a,int n,int m){
    if(n==0)return 1%m;
    int x=pow_mod(a,n/2,m);
    long long ans = (long long)x*x%m;
    if(n%2==1) ans=ans*a%m;
    return (int)ans;
}
//非递归版本
long pow2(long x,int n){
    long pw=1;
    while(n>0){
        if(n&1) pw*=x;
        x*=x;
        n>>=1;
    }
    return pw;
}
double Power(double x, int n) {
    double ans=1.0;
    int p=abs(n);
    while(p>0){
        if(p&1) ans*=x;
        x=x*x;
        p>>=1;
    }
    return n<0?1/ans:ans;
}
int main()
{
    cout<<Power(2.0,-3);
    return 0;
}