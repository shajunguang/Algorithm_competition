//
// Created by liu on 19-9-23.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN=100;
//const char mp[]="ABCDEF";  //用于16制出现的字母处理
//int N;  //表示进制
//
//struct By{
//    char A[MAXN];
//    By(){
//        memset(A,0,sizeof A); // 初始化要处理的数组,其实写完看来不需要结构体也行
//    }
//};
//
//By operator + (By &a,By &b){  //重载+运算符
//    By c; int t,t1,t2;
//    int len=strlen(b.A);
//    if(N==16){                //16进制特殊情况
//        for(int i=0;i<len;i++){
//            t1=0,t2=0;
//            if(c.A[i] !='1')    c.A[i]='0';  //初始化为‘0’很关键,为了计算求和数的大小
//            for(int j=0;j<6;j++){
//                if(a.A[i]==mp[j])  t1=10+j;  //找到字母对应的数字大小
//                if(b.A[i]==mp[j])  t2=10+j;
//            }
//            if(t1 && !t2)   { t=c.A[i]-'0'+t1+b.A[i]-'0';}  //进行16进制数之间的运算
//            if(!t1 && t2)   { t=t=c.A[i]-'0'+a.A[i]-'0'+t2;}
//            else { t=c.A[i]-'0'+a.A[i]-'0'+b.A[i]-'0';}
//            if(t>=10 && t<16)   c.A[i]=mp[t-10];  //如果数落在字母范围,直接用字母表示
//            else    sprintf(c.A+i,"%d",t%N);      //或者将数字写进字符串中
//            if(t/N) sprintf(c.A+i+1,"%d",1);      //如果超过N,就进一位
//        }
//    } else{  //其他进制处理,同16进制
//        for(int i=0;i<len;i++){
//            if(c.A[i] !='1')    c.A[i]='0';
//            t=c.A[i]-'0'+a.A[i]-'0'+b.A[i]-'0';
//            sprintf(c.A+i,"%d",t%N);
//            if(t/N) sprintf(c.A+i+1,"%d",1);
//        }
//    }
//    return c;
//}
//
//By reverse(By &a){  // 字符串反转
//    By b;
//    int len=strlen(a.A);
//    for(int i=0;i<len;i++)
//        b.A[i]=a.A[len-i-1];
//    return b;
//}
//
//bool verification(By &a){  //确认是否是回文数
//    int len=strlen(a.A);
//    for(int i=0;i<len/2;i++)
//        if(a.A[i] != a.A[len-1-i])
//            return false;
//     return true;
//}
//
//int main()
//{
//    By a,b;
//    int flag=1; //是否能够加出回文来
//    cin>>N>>a.A;
//    for(int i=1;i<31;i++){  // 最多30轮
//        b=reverse(a); //反转
//        b=b+a;        //相加
//        if(verification(b)){  //确认是否为回文
//            printf("STEP=%d",i);
//            flag=0;
//            break;
//        }
//        a=b;
//    }
//    if(flag)    printf("Impossible!");
//}