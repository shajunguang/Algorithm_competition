////
//// Created by liu on 19-6-24.
////
//#include <stdio.h>
//#include <string.h>
//char s[1000000];
//int main()
//{
//    while(~scanf("%s",s))
//    {
//        int b[10];
//        memset(b,0,sizeof(b));
//        for(int i=0;i<10000;i++)
//            b[s[i]-'0']++;
//        for(int i=0;i<9;i++)
//            printf("%d ",b[i]);
//        printf("%d\n",b[9]);
//    }
//    const char num[] = "0123456789";
//    int n,T;
//    scanf("%d",&T);
//    while(T--)
//    {
//        int k=0;
//        int ans[10];
//        memset(ans,0, sizeof(ans));
//        memset(s,0,sizeof(s));
//        scanf("%d",&n);
//        for(int i=1;i<=n;i++)
//        {
//            char s1[6];
//            sprintf(s1,"%d",i);//输出到字符串，但是会覆盖s1之前的内容
//            strcat(s,s1);
//        }
//        printf("%s\n",s);
//        for(int i=0;i<strlen(s);i++)
//            for(int j=0;j<strlen(num);j++)
//            {
//                if(s[i]==num[j])    ans[j]++;
//            }
//        for(int i=0;i<10;i++)
//        {
//            if(k) printf(" ");else  k++;
//            printf("%d",ans[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
