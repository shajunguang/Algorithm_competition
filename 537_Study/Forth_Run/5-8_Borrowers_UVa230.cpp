////
//// Created by liu on 19-10-16.
////
//
//#include <bits/stdc++.h>
//#define local
//using namespace std;
//typedef pair<string,string> PAIR;
//
////bool cmp(const PAIR& a, const PAIR& b){
////    if(a.second==b.second)  return a.first<b.first;
////    return a.second<b.second;
////}
//
//struct Cmp{
//    bool operator()(const PAIR& a,const PAIR& b)const{
//        if(a.second==b.second)  return a.first<b.first;
//        return a.second<b.second;
//    }
//};
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    map<pair<string,string>,int,Cmp> book; //第二个参数表示该书是否在书架上
//    string temp;
//    while(getline(cin,temp) && temp!="END")
//    {
//        string title,author;
//        int j=0;
//        for(int i=1;i<temp.size();i++)
//            if(temp[i]=='"')    { j=i;break;}
//            else    title += temp[i];
//        for(int i=j+5;i<temp.size();i++)
//            author += temp[i];
//        //cout<<title<<" "<<author<<endl;
//        book[make_pair(title,author)]=1; //一开始所有书在书架上
//    }
//    temp="";
//    string ans;
//    while(getline(cin,temp) && temp!="END")
//    {
//        string rec=temp.substr(0,6),title;
//        if(rec!="SHELVE")   title = temp.substr(8,temp.size()-9);
//        if(rec=="BORROW")
//        {
//            for(auto &c:book)
//                if(c.first.first==title)
//                    book[make_pair(c.first.first,c.first.second)]=0; //书被借走啦
//        }
//        else if(rec=="RETURN")
//        {
//            for(auto &c:book)
//                if(c.first.first==title)
//                    book[make_pair(c.first.first,c.first.second)]=2; //特殊标记,归还未放入书架
//
//        } else{
//            for(auto c=book.begin();c!=book.end();c++)
//                if(c->second==2)
//                {
//                    if(c==book.begin()) ans += "Put \""+c->first.first+"\" first\n";
//                    else{
//                        auto p=--c;
//                        c++;
//                        while(p->second==0) p--;
//                        ans +="Put \""+c->first.first+"\" after \""+p->first.first+"\"\n";
//                    }
//                    book[make_pair(c->first.first,c->first.second)]=1;
//                }
//            ans += "END\n";
//        }
//    }
//    cout<<ans;
//    return 0;
//}