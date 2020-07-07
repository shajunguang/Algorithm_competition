//
// Created by liu on 19-10-19.
//

//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN=605;
//int vis[MAXN],num_s[MAXN];
//vector<int> id;
//
//int main()
//{
//    memset(vis,0,sizeof vis);
//    memset(num_s,0,sizeof num_s);
//    int N,nums=0,k,ff=0;
//    cin>>N;
//    for(int i=1;i<=2*N;i++)
//        id.push_back(i);
//    srand(time(0));
//    while(1)
//    {
//        int f=1;
//        for(int i=0;i<2*N;i++)
//            if(!vis[i])
//            {
//                f=0;
//                break;
//            }
//        if(f)   { cout<<"-1"<<endl;break;}
//        if(nums==5)
//        {
//            cout<<"-1"<<endl;
//            break;
//        }
//        for(int i = 0;i<2 && id.size()>2;i++) {
//            k = random()%(id.size()-i)+i;
//            int t = id[i];id[i] = id[k];id[k] = t;
//        }
//        for(int i=1;i<=2*N;i++)
//            for(int j=i+1;j<=2*N;j++)
//                if(num_s[j] && num_s[j]==num_s[i])
//                {
//                    id[0]=i;id[1]=j;
//                    vis[id[0]]=vis[id[1]]=0;
//                    break;
//                }
//        if(!vis[id[0]] && !vis[id[1]])
//        {
//            vis[id[0]]=vis[id[1]]=1;
//            cout<<id[0]<<" "<<id[1]<<endl;
//            cout.flush();
//            if(!ff++)  cin.ignore();
//            string str;
//            getline(cin,str);
//            if(str=="match")
//            {
//                //vis[id[0]]=vis[id[1]]=1;
//                nums++;
//                int d1=id[0],d2=id[1];
//                num_s[d1]=num_s[d2]=0;
//                for(auto c=id.begin();c!=id.end();)
//                {
//                    if(*c==d1 || *c==d2)
//                        c=id.erase(c);
//                    else    c++;
//                }
//            }
//            else if(str=="-1")
//            {
//                break;
//            }
//            else {
//                num_s[id[0]]=str[0]-'0';
//                num_s[id[1]]=str[2]-'0';
//            }
//        }
//    }
//    return 0;
//}