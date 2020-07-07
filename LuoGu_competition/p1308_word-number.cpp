//
// Created by liu on 19-10-8.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    string obj,art;
//    cin>>obj;
//    for(int i=0;i<obj.size();i++)
//        if(obj[i]>='A' && obj[i]<='Z')
//            obj[i] += 32;
//    cin.ignore();
//    getline(cin,art);
//    int res=-1,f=0;
//    for(int i=0;i<art.size();i++){
//        string temp;
//        while(i<art.size() && art[i]!=' '){
//            if(art[i]>= 'A' && art[i]<='Z')
//                temp += art[i]+32;
//            else    temp += art[i];
//            i++;
//        }
//        if(temp==obj){
//            if(!f)  res = i-obj.size();
//            f++;
//        }
//    }
//    if(f)   cout<<f<<" "<<res;
//    else    cout<<"-1";
//    return 0;
//}