//
// Created by liu on 19-8-19.
//

//#include<iostream>
//#include<map>
//#include<string>
//#include<cstdio>
//#define local
//
//using namespace std;
//const int maxn=10000+5;
//string s[maxn][15];//存字符串
//map<string ,int>str_id;//将字符串转为id
//typedef pair<int,int>p;
//int n,m;
//
//int main()
//{
////    ios::sync_with_stdio(false);
//#ifdef local
//    freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//#endif
//    while(cin>>n>>m)
//    {
//        str_id.clear();
//        getchar();
//        //read
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)
//            {
//                s[i][j]="";
//                while(1)
//                {
//                    char c=getchar();
//                    if(c==','||c=='\n')break;
//                    s[i][j]+=c;
//                }
//                str_id[s[i][j]]=j*100000+i;//id
//            }
//        }
//        //solve
//        int flag=1;
//        for(int i=1;i<m;i++)
//        {
//            for(int j=i+1;j<=m;j++)
//            {
//                map<p,int>dx;
//                for(int k=1;k<=n;k++)
//                {
//                    int x1=str_id[s[k][i]],x2=str_id[s[k][j]];
//                    p cnt=make_pair(x1,x2);
//                    if(dx.count(cnt))
//                    {
//                        cout<<"NO"<<endl;
//                        cout<<dx[cnt]<<" "<<k<<endl;
//                        cout<<i<<" "<<j<<endl;
//                        flag=0;
//                        goto END;
//                    }
//                    dx[cnt]=k;
//                }
//            }
//        }
//        END:
//        if(flag)cout<<"YES"<<endl;
//    }
//    return 0;
//}

//另一个版本
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<map>
//using namespace std;
//int a[10010][15];
//typedef pair<int,int>two_data;
//map<string,int>data_id;
//map<two_data,int>data_r;//二元组映射。
//string s0;
//int main(){
//    int m,n;
//    while(cin>>m>>n){
//        int t=1;
//        getchar();
//        string s;
//        for(int i=0;i<m;i++){
//            int k=0;
//            getline(cin,s);
//            string x;
//            for(int j=0;j<s.length();j++){//预处理分配ID。
//                if(s[j]!=',') x+=s[j];
//                if(s[j]==','||j==s.length()-1){
//                    if(!data_id.count(x)){
//                        data_id[x]=t;
//                        t++;
//                    }
//                    a[i][k]=data_id[x];
//                    x=s0;
//                    k++;
//                }
//            }
//        }
//        for(int i=0;i<n-1;i++){
//            for(int j=i+1;j<n;j++){
//                for(int k=0;k<m;k++){
//                    int x=a[k][i],y=a[k][j];
//                    if(data_r.count(make_pair(x,y))){//遍历数据库查找相同组。
//                        cout<<"NO"<<endl;
//                        cout<<data_r[make_pair(x,y)]+1<<" "<<k+1<<endl;
//                        cout<<i+1<<" "<<j+1<<endl;
//                        goto END;
//                    }
//                    data_r[make_pair(x,y)]=k;
//                }
//                data_r.clear();
//            }
//        }
//        cout<<"YES"<<endl;
//        END:
//        data_id.clear();
//        data_r.clear();
//        memset(a,0,sizeof(a));
//    }
//    return 0;
//}
