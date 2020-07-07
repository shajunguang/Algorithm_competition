//这段程序解决拼接数字最小
#include<bits/stdc++.h>
using namespace std;
static bool cmp(const string &s1, const string &s2){
    return s1+s2<s2+s1;
}
string PrintMinNumber(vector<int> nums) {
    string res;
    sort(nums.begin(),nums.end());
    vector<string> tmp;
    for(auto i:nums) tmp.push_back(to_string(i));
    sort(tmp.begin(),tmp.end(),cmp); //惊了，这里cmp必须得定义为static
    for(auto t:tmp) res+=t;
    return res;
}
int main()
{
    vector<int> nums={32,32,321};
    string res=PrintMinNumber(nums);
    cout<<res;
    return 0;
}