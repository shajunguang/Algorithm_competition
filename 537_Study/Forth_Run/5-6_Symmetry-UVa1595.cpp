////
//// Created by liu on 19-10-16.
////
//
//#include <bits/stdc++.h>
//#define local
//using namespace std;
//
//vector<pair<double,double>> xy;  //学习pair的用法和排序
//vector<pair<double,double>> xl;  //mid左边数组
//vector<pair<double,double>> xr;  //mid右边数组(一开始只用了一个xy,发现x都相同的时候过不了,坑啊）
//
////重载pair的排序比较
//bool cmp(pair<double,double> &a,pair<double,double> &b){
//    if(a.first==b.first)
//        return a.second<b.second;
//    return a.first<b.first;
//}
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    int T,N,k=0;
//    double x,y;
//    cin>>T;
//    while(T--)
//    {
//        cin>>N;
//        double sum=0;
//        for(int i=0;i<N;i++)
//        {
//            cin>>x>>y;
//            xy.emplace_back(x,y);
//            sum += x;
//        }
//        if(k++) cout<<endl;
//        double mid =sum/N;
//        int lcout=0,rcout=0; //左右个数计数
//        for(int i=0;i<N;i++){
//            if(xy[i].first<mid){
//                xl.emplace_back(make_pair(mid-xy[i].first,xy[i].second));
//                lcout++;
//            }
//            if(xy[i].first>mid){
//                xr.emplace_back(make_pair(xy[i].first-mid,xy[i].second));
//                rcout++;
//            }
//        }
//        int flag=0;
//        if(lcout==rcout)
//        {
//            sort(xl.begin(),xl.end(),cmp);
//            sort(xr.begin(),xr.end(),cmp);
//            flag=1;
//            for(int i=0;i<lcout;i++)
//                if(xl[i].first!=xr[i].first || xl[i].second!=xr[i].second)
//                {
//                    flag=0;
//                    break;
//                }
//        }
//        if(flag)    cout<<"YES";
//        else    cout<<"NO";
//        xy.clear();
//        xr.clear();
//        xl.clear();
//    }
//    return 0;
//}