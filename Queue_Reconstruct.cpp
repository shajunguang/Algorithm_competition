#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [] (vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        };
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans(people.size(),vector<int>());
        vector<bool>vis(people.size(),false);
        for(int i=0;i<people.size();i++){
            int t=people[i][1],count=0;
            for(int j=0;j<t;j++) if(!vis[j] ||(vis[j] && ans[j][0]>=people[i][0])) count++;
            if(count==t) {
                while(vis[t]) t++;
                vis[t]=true;ans[t]=people[i];
            }
            else{
                int t1=0,t2=t-count;
                while(t1<=t2){
                    if(!vis[t] ||(vis[t] && ans[t][0]>=people[i][0])) t1++;
                    if(t1<=t2) t++;
                }
                vis[t]=true;ans[t]=people[i];
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> p={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution res;
    p=res.reconstructQueue(p);

    return 0;
}