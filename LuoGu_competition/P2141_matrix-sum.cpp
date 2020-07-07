//
// Created by liu on 19-10-8.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 105;
//int num[MAXN];
//
//int main()
//{
//    int n,res=0;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        cin>>num[i];
//    }
//    //暴力枚举
//    sort(num,num+n);
//    for(int k=2;k<n ;k++){
//        int flag=1;
//        //这里加flag的原因,一开始理解为有多少对数满足相加等于集合中的数了
//        //其实题目求集合有多个整数刚好被集合另外两数相加，找到满足条件不仅内部
//        //需要break出去，外部也要break出去，不然就是重复的了
//        for(int i=0;i<k-1 && flag;i++)
//            for (int j = i + 1; j < k;j++) {
//                if (num[i] + num[j] > num[k])   break;
//                if (num[i] + num[j] == num[k]) { res++;flag=0;break;}
//            }
//    }
//     /*
//    //双指针（单调性）这里内部只有一个循环，因此break出去正好
//    for(int k=2;k<n;k++){
//        int i=0,j=k-1;
//        while(i<j){
//            if(num[i]+num[j]==num[k])   { res++;break;}
//            else if(num[i]+num[j]>num[k])   j--;
//            else    i++;
//        }
//    }
//     */
//    cout<<res;
//    return 0;
//}

//大佬解法
//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int M=20005;//20005由于最大值是10000+10000=20000，const int是静态定义，定义后该值（即M)无法修改。
//int t[M],g[M];//t是桶，t[i]表示值为i的数在集合中两两相加出现了几次，g[i]表示值为i的数是否在原集合中，1为在，0为不在
//int n,a[105],ans,maxn;//a数组开105是由于总共最多100个数
//int main(){
//    cin>>n;
//    for (int i=1;i<=n;i++){
//        cin>>a[i];//读入
//        g[a[i]]=1;//在集合中赋值为1
//    }
//    for (int i=1;i<n;i++){//暴力枚举求出可以加出的数
//        for (int j=i+1;j<=n;j++){
//            t[a[i]+a[j]]++;//a[i]+a[j]这个数被加出来了
//            maxn=max(maxn,a[i]+a[j]);//求求出数中最大值
//        }
//    }
//    for (int i=1;i<=maxn;i++){//只需要枚举到最大值即可
//        if (t[i]>0&&g[i]) ans++;//判断是否满足，满足就ans++
//    }
//    cout<<ans<<endl;
//    return 0;
//}