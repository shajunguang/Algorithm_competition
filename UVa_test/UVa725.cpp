////
//// Created by liu on 19-8-29.
////
//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int main()
//{
//    int B[10];
//    int N,fghij,abcde,tmp1,tmp2,kase=0;
//    while(cin>>N && N)
//    {
//        int f=1;
//        if(kase)    printf("\n"); else kase++;
//        for(fghij=1234;fghij<=98765/N;fghij++){
//            memset(B, 0, sizeof(B));
//            int flag=1;
//            abcde=fghij*N;
//            tmp1=abcde;
//            for(int i=0;i<5;i++){
//                B[tmp1%10]=1;
//                tmp1 /=10;
//            }
//            tmp2=fghij;
//            for(int i=0;i<5;i++){
//                B[tmp2%10]=1;
//                tmp2 /=10;
//            }
//            for(int i=0;i<10;i++){
//                if(B[i]==0){
//                    flag=0;
//                    break;
//                }
//            }
//            if(flag)    { printf("%0.5d / %0.5d = %d\n",abcde,fghij,N); f=0; }
//        }
//        if(f)   printf("There are no solutions for %d.\n",N);
//    }
//}