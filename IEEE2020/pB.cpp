#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt","r",stdin);
    map<int, int> vist;
    map<int, int> count;
    map<pair<int,int>,int> v;
    queue<int> q;
    map<int, vector<int>> lklist;
    int N;
    cin >> N;
    int parent, child, cnt = 0, n = N;
    for(int i=0;i<n;i++) {
        scanf("%d,%d", &parent, &child);
        if(v.count({parent,child})!=0) continue;
        if (vist[child] == 1) {
            cout << "Not a tree\n";
            return 0;
        }
        ++count[parent];
        ++count[child];
        vist[child] = 1;
        v[{parent,child}]=1;
        lklist[parent].push_back(child);
    }
    for(auto &l : lklist) {
        if(vist[l.first] == 0) {
            ++cnt;
            q.push(l.first);
        }
    }
    if(cnt != 1) {
        cout << "Not a tree\n";
        return 0;
    }
    cnt = 0;
    vector<int> res;
    n = count.size();
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        res.push_back(t);
        for(auto k : lklist[t]) {
            q.push(k);
        }
        ++cnt;
    }
//    cout << cnt << " " << n << endl;
    if(cnt != n)
        cout << "Not a tree\n";
    else {
        int i;
        for(i = 0; i < res.size() - 1; ++i)
            cout << res[i] << " ";
        cout << res[i];
    }
    return 0;
}