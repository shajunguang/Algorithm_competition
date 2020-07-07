//
// Created by liu on 19-10-16.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    vector<int> sticks={1,1,2,3};
//    priority_queue<int, vector<int>, greater<int> > q; // 小根堆
//    for (auto stick : sticks) {
//        q.push(stick);
//    }
//    int res = 0;
//    int cost = 0;
//    while (!q.empty()) {
//        cost = q.top();
//        q.pop();
//        if (q.empty()) {
//            break;
//        } else {
//            cost += q.top();
//            q.pop();
//            q.push(cost);
//            res += cost;
//        }
//    }
//    cout<<res;
//}