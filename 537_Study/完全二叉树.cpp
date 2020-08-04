#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int tol = pow(2, n);
    vector<int> nodes(tol);
    for(int i = 1; i < nodes.size(); ++i) {
        nodes[i] = i;
    }
    int l1 = 2 * m, l2 = l1, r1 = 2 * m + 1, r2 = r1;
    while(r2 < tol) {
        for(int i = 0; i <= l2 - l1; ++i) {
            int tmp = nodes[l1 + i];
            nodes[l1 + i] = nodes[r1 + i];
            nodes[r1 + i] = tmp;
        }
        l2 = 2 * l2 + 1;
        l1 = 2 * l1;

        r2 = 2 * r2 + 1;
        r1 = 2 * r1;
    }
    for(int i = 1; i < tol; ++i) {
        cout << nodes[i] << endl;
    }
    return 0;
}