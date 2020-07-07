//
// Created by liu on 19-8-29.
//

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int fac(int n)
//{
//    if(n==1)    return 1;
//    return n*fac(n-1);
//}
//
//int main()
//{
//    int n,m,a,b,c,t1,t2,M[25][3];
//    while(cin>>n>>m && n+m !=0){
//        int p[n],ans=0;
//        if(m==0)    printf("%d\n",fac(n));
//        else{
//            for(int i=0;i<n;i++)    p[i]=i;
//            for(int i=0;i<m;i++)    cin>>M[i][0]>>M[i][1]>>M[i][2];
//                do{
//                    int flag=1;
//                    for(int i=0;i<m;i++) {
//                        a=M[i][0];
//                        b=M[i][1];
//                        c=M[i][2];
//                        for (int j = 0; j < n; j++) {
//                            if (p[j] == a) t1 = j;
//                            if (p[j] == b) t2 = j;
//                        }
//                        if (c > 0)
//                            if (abs(t2 - t1) <= c) continue;
//                            else { flag=0;break;}
//                        else
//                            if (abs(t2 - t1) >= -c) continue;
//                            else { flag=0;break;}
//                    }
//                    if(flag)    ans++;
//                }while(next_permutation(p,p+n));
//                printf("%d\n",ans);
//        }
//    }
//}