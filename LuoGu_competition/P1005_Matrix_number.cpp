//
// Created by liu on 19-9-16.
//

//贪心出错

//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 100;
//int A[maxn][maxn],B[maxn][maxn];
//
//int main()
//{
//    int n,m,ans=0,k1,km;
//    cin>>n>>m;
//    for(int i=0;i<n;i++)
//        for(int j=0;j<m;j++)
//            cin>>A[i][j];
//    memset(B,0,sizeof(B));
//    for(int i=0;i<m;i++){
//        int s=0;
//        for(int j=0;j<n;j++)
//        {
//            for(int ij=0;ij<=i;ij++)
//                if(!B[j][ij])   { k1=ij;break; }
//            for(int ji=m-1;ji>=m-i-1;ji--)
//                if(!B[j][ji])   { km=ji;break; }
//            s += min(A[j][k1],A[j][km]);
//            if(A[j][k1]<A[j][km])
//                B[j][k1]=1;
//            else    B[j][km]=1;
//        }
//        ans += s*pow(2,i+1);
//    }
//    cout<<ans;
//}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int MAXN = 85, Mod = 10000;
//int n, m;
//int ar[MAXN];
//
//struct HP {
//    int p[505], len;
//    HP(){
//        memset(p, 0, sizeof p);
//        len = 0;
//    }//构造函数,用于创建一个高精度变量
//    void print(){
//        printf("%d",p[len]);
//        for(int i=len-1;i>0;i++){
//            if(p[i]==0){
//                printf("0000");
//                continue;
//            }
//            for(int k=10;k*p[i]<Mod;k *=10)
//                printf("0");
//            printf("%d",p[i]);
//        }
//    }
//} f[MAXN][MAXN],base[MAXN], ans;
//
//HP operator + (const HP &a, const HP &b){
//    HP c;c.len = max(a.len,b.len);int x=0;
//    for(int i =1;i<=c.len;i++){
//        c.p[i] = a.p[i]+b.p[i]+x;
//        x = c.p[i]/Mod;
//        c.p[i] %=Mod;
//    }
//    if(x>0)
//        c.p[++c.len] = x;
//    return c;
//}// 高精+高精
//
//HP operator * (const HP &a, const int &b){
//    HP c;c.len=a.len;int x=0;
//    for(int i=1;i<=c.len;i++){
//        c.p[i] =a.p[i] * b+x;
//        x=c.p[i]/Mod;
//        c.p[i] %= Mod;
//    }
//    while(x>0)
//        c.p[++c.len] = x%Mod, x /= Mod;
//    return c;
//} //高精*高精
//
//HP max(const HP &a, const HP &b){
//    if(a.len>b.len)
//        return a;
//    else if(a.len<b.len)
//        return b;
//    for(int i=a.len;i>0;i--)
//        if(a.p[i]>b.p[i])
//            return a;
//        else if(a.p[i]<b.p[i])
//            return b;
//    return a;
//} //max(高精,高精)
//
//void BaseTwo(){
//    base[0].p[1]=1;base[0].len=1;
//    for(int i=1;i<=m+2;i++) {
//        base[i] = base[i - 1] * 2 ;
//    }
//}
//
//int main()
//{
//    scanf("%d%d",&n,&m);
//    BaseTwo();
//    while(n--){
//        memset(f,0,sizeof f);
//        for(int i=1;i<=m;i++)
//            scanf("%d", &ar[i]);
//        for(int i=1;i<=m;i++)
//            for(int j=m;j>=i;j--){
//                f[i][j]=max(f[i][j], f[i-1][j]+base[m-j+i-1]*ar[i-1]);
//                f[i][j]=max(f[i][j],f[i][j+1]+base[m-j+i-1]*ar[j+1]);
//            }
//        HP Max;
//        for(int i=1;i<=m;i++)
//            Max=max(Max,f[i][i]+base[m]*ar[i]);
//        ans = ans + Max;
//    }
//    ans.print();
//    return 0;
//}