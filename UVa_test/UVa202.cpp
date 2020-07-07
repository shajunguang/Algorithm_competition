////
//// Created by liu on 19-6-16.
////
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <cstdio>
//#define local
//
//using namespace std;
//
//int r[3003],u[3003],s[3003];
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//#endif
//    int n,m,t;
//    while (cin >> n >> m) {
//        t = n;
//        memset(r, 0, sizeof(r));
//        memset(u, 0, sizeof(u));
//        int count = 0;
//        r[count ++] = n/m;
//        n = n%m;
//        while (!u[n] && n) {
//            u[n] = count;
//            s[count] = n;
//            r[count ++] = 10*n/m;
//            n = 10*n%m;
//        }
//        printf("%d/%d = %d",t,m,r[0]);
//        printf(".");
//        for (int i = 1 ; i < count && i <= 50 ; ++ i) {
//            if (n && s[i] == n) printf("(");
//            printf("%d",r[i]);
//        }
//        if (!n) printf("(0");
//        if (count > 50) printf("...");
//        printf(")\n");
//        printf("   %d = number of digits in repeating cycle\n\n",!n?1:count-u[n]);
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//const int N=3005;
//int a[N],v[N];
//int main()
//{
//    int n,m,cnt;
//    while(scanf("%d%d",&n,&m)==2)
//    {
//        cnt=0;
//        memset(v,0,sizeof(v));
//        printf("%d/%d = %d.",n,m,n/m);
//        n=n%m;
//        while(!v[n])
//        {
//            a[++cnt]=(n*10)/m;
//            v[n]=cnt;
//            n = n*10%m;
//        }
//        for(int i=1;i<=cnt && i<51;i++)
//        {
//            if(i==v[n]) {printf("(");}
//            printf("%d",a[i]);
//            if(i==50)   printf("...");
//        }
//        printf(")\n%4d = number of digits in repeating cycle\n\n",cnt-v[n]+1);
//    }
//    return 0;
//}