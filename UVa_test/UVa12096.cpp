//
// Created by liu on 19-8-18.
//

//#include <iostream>
//#include <string>
//#include <cctype>
//#include <map>
//#include <vector>
//#include <set>
//#include <algorithm>
//#include <stack>
////#define local
//#define ALL(x)  x.begin(),x.end()
//#define  INS(x) inserter(x,x.begin())
//using namespace std;
//
//typedef set<int> Set;  //将集合定义为类
//map<Set,int> IDcache;  //把集合映射成ID
//vector<Set> Setcache;  //根据ID取集合
//
////查找给定集合x的ID.如果找不到,分配一个新ID
//int ID (Set x){
//    if(IDcache.count(x)) return IDcache[x];
//    Setcache.push_back(x);
//    return IDcache[x] = Setcache.size()-1;
//}
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//#endif
//    stack<int> s;
//    int m,n;
//    cin>>m;
//    while(m--){
//        cin>>n;
//        for(int i=0;i<n;i++){
//            string op;
//            cin>>op;
//            if(op[0]=='P')  s.push(ID(Set()));
//            else if(op[0]=='D') s.push(s.top());
//            else{
//                Set x1 = Setcache[s.top()];s.pop();
//                Set x2 = Setcache[s.top()];s.pop();
//                Set x;
//                if(op[0]=='U')  set_union(ALL(x1), ALL(x2), INS(x));
//                if(op[0]=='I')  set_intersection(ALL(x1), ALL(x2), INS(x));
//                if(op[0]=='A')  { x=x2;x.insert(ID(x1)); }
//                s.push(ID(x));
//            }
//            cout<<Setcache[s.top()].size()<<endl;
//        }
//        cout<<"***"<<endl;
//    }
//    return 0;
//}

//另一个版本
//#include <bits/stdc++.h>
//using namespace std;
//typedef set<int> Set;
//map<Set,int> id;
//vector<Set> vs;
//stack<int> st;
//int ID(const Set &x)
//{
//    if(id.find(x)!=id.end())
//        return id[x];
//    vs.push_back(x);
//    return id[x]=vs.size()-1;
//}
//int main ()
//{
//    ios::sync_with_stdio(false);
//    int t,n;
//    cin>>t;
//    while(t--)
//    {
//        vs.clear();
//        id.clear();
//        while(!st.empty())
//            st.pop();
//        cin>>n;
//        string s;
//        for(int i=0;i<n;i++)
//        {
//            cin>>s;
//            if(s=="PUSH")
//            {
//                st.push(ID(Set()));
//            }
//            else
//            {
//                if(s=="DUP")
//                {
//                    st.push(st.top());
//                }
//                else
//                {
//                    Set s1=vs[st.top()];
//                    st.pop();
//                    Set s2=vs[st.top()];
//                    st.pop();
//                    Set tmp;
//                    if(s=="UNION")
//                    {
//                        set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(tmp,tmp.begin()));
//                    }
//                    if(s=="INTERSECT")
//                    {
//                        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(tmp,tmp.begin()));
//                    }
//                    if(s=="ADD")
//                    {
//                        tmp=s2;
//                        tmp.insert(ID(s1));
//                    }
//                    st.push(ID(tmp));
//                }
//            }
//
//            cout<<vs[st.top()].size()<<endl;
//        }
//        cout<<"***"<<endl;
//    }
//    return 0;
//}
