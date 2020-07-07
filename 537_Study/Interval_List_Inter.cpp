#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty() || B.empty()) return{{}};
        int m=A.size(),n=B.size();
        if(A[0][0]>B[n-1][1] || B[0][0]>A[m-1][1]) return {{}};
        vector<vector<int>> ans;

        int j=0;
        for(int i=0;i<n;i++)
            for(;j<m;j++){
                int start=max(A[j][0],B[i][0]),end=min(A[j][1],B[i][1]);
                if(end>=start) ans.push_back({start,end});
                if(B[i][1]<A[j][1]) break;
            }

        return ans;

    }
};
int main()
{
    vector<vector<int>> A={{0,2},{5,10}};
    vector<vector<int>> B={{1,5},{8,12}};
    Solution res;
    res.intervalIntersection(A,B);
    return 0;
}