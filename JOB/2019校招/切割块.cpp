#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z,k,s[3];
    cin>>x>>y>>z>>k;
    s[0]=x,s[1]=y,s[2]=z;
    sort(s,s+3);
    x=s[0],y=s[1],z=s[2];
    long long x1=min(x,k/3+1);
    long long y1=min(y,k/3+1);
    long long z1=min(z,k/3+1);
    s[0]=x1,s[1]=y1,s[2]=z1;
    sort(s,s+3);
    x1=s[0],y1=s[1],z1=s[2];
    int t=x1+y1+z1-3,a1,b1,c1;
    if(t<k) {  //这里利用了3*x*y*z<=(x^2+y^2+z^2)柯西不等式，要取到最大值时，x=y=z
        int h=k-t;
        if(x>k/3+1) a1=min(x-k/3-1,h/3),x1+=a1>0?a1:0,h-=h/3>a1?a1:h/3; //第一次三等分
        if(y>k/3+1) b1=min(y-k/3-1,h/2),y1+=b1>0?b1:0,h-=h/2>b1?b1:h/2; //剩余二等分
        if(z>k/3+1) c1=min(z-k/3-1,h),z1+=c1>0?c1:0,h-=h>c1?c1:h;  //剩余给最长的
    }
    cout<<x1*y1*z1<<endl;
    return 0;
}
//已知x+y+z的，如何使得x*y*z最大，目标就是x=y=z
/*
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[5],k;
    long long int maxd,maxk,m=104909296875;
    scanf("%d%d%d%d",&a[1],&a[2],&a[3],&k);
    //刀数
    maxd=(long long int)(a[1]-1)+(a[2]-1)+(a[3]-1);
    //块数
    maxk=(long long int)a[1]*a[2]*a[3];
    //k超过刀数
    if(k>=maxd)
    {
        printf("%lld\n",maxk);
        return 0;
    }
    else while(maxd!=k)
        {
            //找最长的那条边
            sort(a+1,a+4);
            //最长边减1
            a[3]--;
            //新的刀数和块数
            maxd=(long long int)(a[1]-1)+(a[2]-1)+(a[3]-1);
        }
    maxk=(long long int)a[1]*a[2]*a[3];
    printf("%lld",maxk);
    return 0;
}
 */