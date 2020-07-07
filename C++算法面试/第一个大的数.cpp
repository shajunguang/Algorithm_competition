#include<bits/stdc++.h>
using namespace std;
vector<int> findMax(vector<int>&num){
    if(num.empty()) return num;
    vector<int> ans(num.size(),INT_MAX);
    int i=0;
    stack<int> s;
    while(i<num.size()){
        if(s.empty() || num[s.top()]>=num[i])
            s.push(i++);
        else{
            ans[s.top()]=num[i];
            s.pop();
        }
    }
    for(auto i:ans) cout<<i<<" ";
    return ans;
}
int main()
{
    vector<int> num={1,2,1,3,2};
    findMax(num);
    return 0;
}