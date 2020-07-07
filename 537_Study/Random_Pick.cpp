#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> f;
    int sum=0;
    Solution(vector<int>& w) {
        int t=0;
        for(auto c:w) {
            sum+=c;
            f.push_back({t,sum-1});
            t=sum;
        }

        srand((int)time(0));

    }

    int pickIndex() {

        int t=rand()%sum;
        int i=0;
        for(auto c:f){
            if(t>=c[0] && t<=c[1]) return i;
            i++;
        }
        return 0;
    }
};

int main()
{
    vector<int> w={9,2,8,7,10,7,7,6,7,4,9,7,10,7,4};
    Solution s(w);
    for(int i=0;i<10;i++) cout<<s.pickIndex()<<" ";
    return 0;
}