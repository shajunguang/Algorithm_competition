//
// Created by liu on 19-10-9.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int num[10] = {6,2,5,5,4,5,6,3,7,6};
//
//int main()
//{
//    int n,res=0,a[2001]={6},i,j;
//    cin>>n;
//    for(i=1;i<=2000;i++){
//        j=i;
//        while(j>=1)
//        {
//            a[i]=a[i]+num[j%10];
//            j = j/10;
//        }
//    }
//    for(i=0;i<=1000;i++)
//    {
//        for(j=0;j<=1000;j++)
//            if(a[i]+a[j]+a[i+j]+4==n)   res++;
//    }
//    cout<<res;
//}

//回溯方法（弱子自己没写出来的）
//#include <iostream>
//using namespace std;
//int x[1001] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, b[4];//初始定义0~9火柴棒个数， b数组存放每次可能的等式
//int n, tot = 0;
//void search(int l)//搜索
//{
//    int i;
//    for(i = 0; i <= 999; ++i)
//    {
//        if(n - x[i] >= 0)//火柴棍还够
//        {
//            b[l] = i;//火柴棒数放入数组
//            n = n - x[i];//在总数中减去火柴棒
//            if(l == 3)
//            {
//                if(b[1] + b[2] == b[3] && n == 0) tot++;//满足等式且火柴棒用完
//            }
//            else search(l + 1);//回溯
//            n = n + x[i];//保存之前状态
//        }
//    }
//}
//int main()
//{
//    int i;
//    cin >> n;
//    n = n - 4;
//    for(i = 10; i <= 999; ++i)
//        x[i] = x[i / 10] + x[i % 10];//把2位数火柴棒， 3位数火柴棒放入数组， 理论上可达到11111111，但因为数据弱四位就过了
//    search(1);
//    cout << tot;
//    return 0;
//}