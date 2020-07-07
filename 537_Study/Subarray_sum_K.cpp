#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        map<int,vector<int>> hash;
        vector<int> sum(begin(nums),end(nums));
        hash[sum[0]].push_back(0);
        for(int i=1;i<n;i++) sum[i]+=sum[i-1],hash[sum[i]].push_back(i);
        int bound=(hash.rbegin())->first;
        for(auto i:hash){
            if(i.first==k) ans+=i.second.size();
            int t=i.first+k;
            if(!hash.count(t)) continue;
            for(auto j:hash[t])
                for(auto h:i.second)
                    if(j>h) ans++;
        }

        return ans;
    }
};

int main()
{
    vector<int> nums={28,54,7,-70,22,65,-6};
    Solution res;
    cout<<res.subarraySum(nums,100);

    return 0;
}