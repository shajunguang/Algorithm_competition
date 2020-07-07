//M个苹果放在N个盘子上
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int dg(int m,int n)//m个苹果放到n个盘子里
{
    if(m==1 || m==0 || n==1) return 1;//判断只有一个方法放苹果的情况
    else if(m<n) return dg(m,m);
        //否则判断苹果数是否少于盘子数，如果少，那么肯定有n-m个空盘子
        //所以只要做把m个苹果放到m个盘子里
    else return dg(m-n,n)+dg(m,n-1);
    //否则m-n个盘子起码有一个苹果，即只要把m-n个苹果放到n个盘子里
    //还要加上这个盘子不放的情况
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        cout<<dg(m,n)<<endl;
    }

    return 0;
}
