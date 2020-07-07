//只是查询，前缀和即可，若存在修改可使用线段树
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> xorQueries(vector<int>&arr,vector<vector<int>>& queries){
        vector<int> data(arr.size()+1,0); //异或前缀和
        for(int i=0;i<arr.size();i++) data[i+1]=data[i]^arr[i];
        vector<int>ans;
        for(auto q:queries){
            if(!q[0])ans.push_back(data[q[1]+1]);
            else ans.push_back(data[q[0]]^data[q[1]+1]);
        }
        return ans;
    }
};
int main()
{
    Solution ret;
    vector<int> arr={1,3,4,8};vector<vector<int>> q={{0,1},{1,2},{0,3},{3,3}};
    vector<int> ans=ret.xorQueries(arr,q);
    for(auto c:ans)cout<<c<<" ";
    return 0;
}