//
// Created by liu on 19-9-20.
//

//#include <bits/stdc++.h>
//#include <cstring>
//using namespace std;
//
//const int Mod = 10000;
//
//struct HP{
//    int p[505],len;
//    HP(){
//        memset(p, 0, sizeof p);
//        len=0;
//    }
//    void print(){
//        printf("%d", p[len]);
//        for(int i=len-1;i>0;i--){
//            if(p[i]==0){
//                printf("0000");
//                continue;
//            }
//            for(int k=10;k*p[i]<Mod;k *=10)
//                printf("0");
//            printf("%d",p[i]);
//        }
//    }
//    HP operator=(const char*num)
//    {
//        len=strlen(num);
//        for(int i=0;i<len;++i)
//            p[i]=num[len-i-1]-'0';
//        return *this;
//    }
//    HP operator=(const int num){
//        char a[505];
//        sprintf(a,"%d",num);
//        *this = a;
//        return *this;
//    }
//    HP (const int num){
//        *this=num;
//    }
//    HP(const char* num){
//        *this=num;
//    }
//};
//
//HP operator + (const HP &a, const HP &b) {
//    HP c; c.len = max(a.len, b.len); int x = 0;
//    for (int i = 1; i <= c.len; i++) {
//        c.p[i] = a.p[i] + b.p[i] + x;
//        x = c.p[i] / Mod;
//        c.p[i] %= Mod;
//    }
//    if (x > 0)
//        c.p[++c.len] = x;
//    return c;
//} //高精+高精
//
//HP operator * (const HP &a, const int &b) {
//    HP c; c.len = a.len; int x = 0;
//    for (int i = 1; i <= c.len; i++) {
//        c.p[i] = a.p[i] * b + x;
//        x = c.p[i] / Mod;
//        c.p[i] %= Mod;
//    }
//    while (x > 0)
//        c.p[++c.len] = x % Mod, x /= Mod;
//    return c;
//} //高精*单精
//HP s=1;
//HP fac(int n){
//    if(n==1) return s;
//    return fac(n-1)*n;
//}
//
//int main()
//{
//    int N;
//    HP ans=0;
//    cin>>N;
//    for(int i=N;i>0;i--)
//        ans = ans + fac(i);
//    ans.print();
//    return 0;
//}