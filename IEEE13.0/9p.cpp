////
//// Created by liu on 19-10-20.
////
//
//#include <bits/stdc++.h>
//using namespace std;
//
//int gcd(int m, int n)
//{
//    return n == 0 ? m : gcd(n, m % n);
//}
//
//vector<int> nums;
//
//int main()
//{
//    int N,K,num;
//    cin>>N>>K;
//    set<int> q;
//    for(int i=0;i<N;i++)
//    {
//        cin>>num;
//        nums.push_back(num);
//        q.insert(num);
//    }
//    for(int i=2;i<=K;i++)
//    {
//        int s_n=q.size();
//        for(auto c:nums)
//            for(auto d: q)
//            {
//                int temp=gcd(c,d);
//                q.insert(temp);
//            }
//        if(s_n==q.size())   break;
//    }
//    cout<<q.size();
//    return 0;
//}