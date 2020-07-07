//
// Created by liu on 19-10-16.
//

//#include <bits/stdc++.h>
//using n                                amespace std;
//
//int main()
//{
//    string s="ADOBECODEBANC";
//    string t="ABC";
//    unordered_map<char,int> hash; //这里表示还缺多少
//    for(auto c:t)   hash[c]++;
//    int cnt=hash.size();
//
//    string res;
//    for(int i=0,j=0,c=0;i<s.size();i++)
//    {
//        if(hash[s[i]]==1) c++;
//        hash[s[i]]--;
//        while(hash[s[j]]<0) hash[s[j++]]++;
//        if(c==cnt)
//            if(res.empty() || res.size()>i-j+1) res = s.substr(j,i-j+1);
//    }
//    cout<<res;
//}