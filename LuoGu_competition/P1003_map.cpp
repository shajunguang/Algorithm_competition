//
// Created by liu on 19-9-11.
//
//这道题目在于没有必要去创建棋盘数组，这是我失误的地方！因为数据坐标很大,创建不出来那么大的数组！

//#include <bits/stdc++.h>
//#define local
//const int nmax=200+100;
//
//using namespace std;
//
//int ch[nmax][nmax]={0};
//
//
//int main()
//{
////#ifdef local
////    freopen("in.txt","r",stdin);
////#endif
//    int n,a,b,g,k,x,y;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a>>b>>g>>k;
//        for(int l=b;l<=b+k;l++)
//            for(int j=a;j<=a+g;j++)
//                ch[l][j]=i;
//    }
//    cin>>x>>y;
//    if(ch[y][x])    cout<<ch[y][x];
//    else    cout<<"-1";
//    return 0;
//}

/*
 #include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int n,a[10005],b[10005],g[10005],k[10005],x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
    scanf("%d%d",&x,&y);
    for(int i=n;i>=1;--i)
        if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i])
        {
            printf("%d\n",i);
            exit(0);
        }
    printf("-1\n");
    return 0;
}
 * */