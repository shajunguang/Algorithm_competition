//bfs获得level层好友
//使用map<string,int>统计频率
//使用multimap<int,string>转换为按照频率升序及字典序
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level){
        unordered_set<int> friend_set;
        friend_set.insert(id);
        vector<int> friend_vector={id};

        for(int i=0;i<level;i++){ //计算次数
            vector<int> temp;
            for(auto n:friend_vector)
                for(auto cur:friends[n]){
                    if(friend_set.count(cur)!=0)continue;
                    friend_set.insert(cur);
                    temp.push_back(cur);
                }
            friend_vector=temp;
        }
        map<string,int> freq; //观看频率
        for(auto n:friend_vector)
            for(auto v:watchedVideos[n]) freq[v]++;
        multimap<int,string> videos; //可以重复的
        for(auto n:freq) videos.insert({n.second,n.first});
        vector<string> ans;
        for(auto m:videos) ans.push_back(m.second);
        return ans;
    }
};