//
// Created by liu on 19-9-30.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    string s,t;
//    int maxCost,res=0;
//    cin>>s>>t>>maxCost;
//    int n=s.length();
//    vector<int> cnt(n,0);  //使用vector好处是动态申请空间
//    cnt[0] = abs(s[0]-t[0]);
//    //计算前缀和（前缀和的好处：后面可以O(1)计算区间[i,j]的和）
//    for(int i=1;i<n;i++)    cnt[i]=cnt[i-1]+abs(s[0]-t[0]);
//    //二分法求最长连续子串
//    for(int i=0;i<n;i++){
//        if(cnt[i] > maxCost){
//            // vector自带的二分查找,lower_bound()返回区间中的大于等于该数的位置
//            auto it = lower_bound(cnt.begin(),cnt.end(),cnt[i]-maxCost);
//            int length = cnt.begin()+i-it;
//            res = max(res,length);
//        }else{
//            res = i + 1;
//        }
//    }
//    cout<<res;
//    return 0;
//}