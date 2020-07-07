//
// Created by liu on 19-9-26.
//

//#include <bits/stdc++.h>
//#define local
//using namespace std;
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//#endif
//    char s[90];
//    int T;
//    scanf("%d",&T);
//    while(T--)
//    {
//        int m=0, ans=0;
//        scanf("%s",s);
//        for(int i=0;i<strlen(s);i++)
//        {
//            if(i==0 && s[0]=='O')
//            {
//                m=1;
//                ans += m;
//            }
//            if(i>0 && s[i]=='O' && s[i-1]=='X')
//            {
//                m=1;
//                ans +=m;
//            }
//            if(i>0 && s[i]=='O' && s[i-1]=='O')
//            {
//                m++;
//                ans += m;
//            }
//            if(s[i]=='X')   m=0;
//            //printf("m= %d, ans= %d\n", m, ans);
//        }
//        printf("%d\n",ans);
//    }
//}