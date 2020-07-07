/*
典型的错排题目
首先求出错排的情况，然后求出错排的所有情况n!，以前者除以后者就是百分比
现在求对应的错排情况。容易知道，f(1)=0,f(2)=1
然后，对于N个人，有n-1个人拿错票和n-2个人拿错票的情况
当有n-1个拿错票时，在加入一个人，只要第n个人和前面任意的n-1个人其中一个调换票就可以了，
所以有f(n-1)*(n-1)。当有n-2个拿错票时，只能是没拿错的那个人与第n个交换票，
而那个人可能是前面n-1个的任意一个，所以又有f(n-2)*(n-1)
所以错排结果为(n-1)*(f(n-1)+f(n-2))。
 */
#include<bits/stdc++.h>
using namespace std;
long long f[25];

int main()
{
    int c,n;
    f[1]=0,f[2]=1;
    for(int i=3;i<25;i++) f[i]=(i-1)*f[i-1]+(i-1)*f[i-2];
    cin>>c;
    while(c--){
        long long s=1;
        cin>>n;
        for(int i=1;i<=n;i++) s*=i;
        //cout<<s<<endl;
        printf("%.2lf%%\n",(f[n]+0.0)/s*100);
    }

    return 0;
}