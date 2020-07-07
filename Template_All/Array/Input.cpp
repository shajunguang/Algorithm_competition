#include<bits/stdc++.h>
using namespace std;
vector<int> printMatrix(vector<vector<int> > mt) {
    int m=mt.size(),n=mt[0].size();
    vector<int> vis(m*n,0);
    vector<int> ans;
    int i=0,j=0;
    while(i<m && j<n && !vis[i*n+j]){
        while(i<m && j<n && !vis[i*n+j] && j<n) vis[i*n+j]=1,ans.push_back(mt[i][j++]);
        i++,j--;
        while(i<m && j<n && !vis[i*n+j] && i<m) vis[i*n+j]=1,ans.push_back(mt[i++][j]);
        i--,j--;
        while(i<m && j<n && !vis[i*n+j] && j>=0) vis[i*n+j]=1,ans.push_back(mt[i][j--]);
        j++,i--;
        while(i<m && j<n && !vis[i*n+j] && i>=0) vis[i*n+j]=1,ans.push_back(mt[i--][j]);
        i++,j++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> mt={{1,2,3}};
    vector<int> ans=printMatrix(mt);
    return 0;
}