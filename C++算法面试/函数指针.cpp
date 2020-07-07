#include<bits/stdc++.h>
using namespace std;

char* fun(char *p){
    printf("%s",p);
}

int main()
{
    char*(*pf)(char *p);
    pf=fun;
    cout<<pf<<" "<<&fun<<endl; //计算的偏移量
    pf("Hello world!");
    return 0;
}