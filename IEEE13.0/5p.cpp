//
// Created by liu on 19-10-19.
//

//#include <bits/stdc++.h>
//#define local
//using namespace std;
//
//map<int,vector<int>> price;
//int se[15],se_l[15],res=0,n;
//vector<int> nums;
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    int t,te,b;
//    cin>>t;
//    while(t--)
//    {
//        //memset(vis,0,sizeof vis);
//        cin>>b>>n;
//        for(int i=0;i<n;i++)
//        {
//            cin>>se[i];
//        }
//        se_l[0]=0;se_l[1]=se[0];
//        for(int i=2;i<=n;i++)
//            se_l[i]=se_l[i-1]+se[i-1];
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<se[i];j++)
//            {
//                cin>>te;
//                nums.push_back(te);
//                price[i].push_back(te);
//            }
//            sort(price[i].begin(),price[i].end());
//            //vis[i][0]=1;
//            res += price[i][0];
//        }
//        //cout<<res;
//        if(res>b)   cout<<"0";
//        else if(res==b) cout<<res;
//        else
//        {
//            cout<<res;
//        }
//        return 0;
//    }
//}