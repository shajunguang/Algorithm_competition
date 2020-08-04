/*
 给定一个数组 candidates 和一个目标数 target ，
 找出 candidates 中所有可以使数字和为 target 的组合。
 candidates 中的每个数字在每个组合中只能使用一次。
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(vector<int>&c,int i,int target){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        for(int j=i;j<c.size()&&c[j]<=target;j++){
            tmp.push_back(c[j]);
            dfs(c,j+1,target-c[j]);
            tmp.pop_back();
            while(j+1<c.size() && c[j]==c[j+1])j++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target);
        //sort(begin(ans),end(ans));
        //ans.erase(unique(begin(ans),end(ans)),end(ans));
        return ans;
    }
};
int main()
{
    vector<int> c={2,2,2};
    Solution res;
    res.combinationSum2(c,2);
    for(auto &i:res.ans) {
        for (auto &j:i) cout << j << " ";
        cout<<endl;
    }
    return 0;
}