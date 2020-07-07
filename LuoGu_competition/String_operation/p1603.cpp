#include<bits/stdc++.h>
using namespace std;
const string numbers[20]={"one","two","three","four","five","six","seven","eight","nine",
                    "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
                    "seventeen","eighteen","nineteen","twenty"};
map<string,int> a_num;

int main()
{
    for(int i=0;i<20;i++) a_num[numbers[i]]=i+1;
    a_num["a"]=a_num["another"]=a_num["first"]=1;
    a_num["both"]=a_num["second"]=2;
    a_num["third"]=3;
    string s;
    vector<int> num_1;
    vector<int> num_10;
    while(cin>>s && s!=".")
        if(a_num[s]>0 && a_num[s]<21){
            if(a_num[s]*a_num[s]<10) num_1.emplace_back(a_num[s]*a_num[s]);
            else num_10.emplace_back(a_num[s]*a_num[s]%100);
        }
    sort(num_1.begin(),num_1.end());sort(num_10.begin(),num_10.end());
    for(int i=0;i<num_1.size();i++){
        if(i) cout<<"0";
        cout<<num_1[i];
    }
    for(auto num:num_10)cout<<num;
    if(num_1.empty() && num_10.empty()) cout<<"0";
    return 0;
}