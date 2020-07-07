#include<bits/stdc++.h>
//gcd(a,b)=gcd(b,a mod b) 辗转相除 gcd(a,0)=a
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}