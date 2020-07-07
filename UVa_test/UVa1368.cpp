////
//// Created by liu on 19-6-15.
////
//#include <stdio.h>
//#include <string.h>
//#define local
//int T,m,n;
//char s[55][1010];
//char nul[4]={'A','C','G','T'},str[1010];
//int cmp[5],ham;
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//#endif
//    scanf("%d",&T);
//    while (T--) {
//        ham=0;
//        scanf("%d%d",&m,&n);
//        for (int i=0;i<m;i++) {
//            scanf("%s",s[i]);
//        }
//        for (int i=0;i<n;i++) {
//            memset(cmp,0,sizeof(cmp));
//            for (int j=0;j<m;j++) {
//                for (int k=0;k<4;k++) {
//                    if (nul[k]==s[j][i]) {
//                        cmp[k]+=1;
//                        continue;
//                    }
//                }
//            }
//            int max=0,pos;
//            for (int p=3;p>=0;p--) {
//                if (cmp[p]>=max) {
//                    max=cmp[p];
//                    pos=p;
//                }
//            }
//            ham+=m-max;
//            str[i]=nul[pos];
//        }
//        for (int i=0;i<n;i++) printf("%c",str[i]);
//        printf("\n%d\n",ham);
//    }
//    return 0;
//}