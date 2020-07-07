#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp;
    map<int, int> mm{{INT_MIN, -1}};
    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        arr[i] = tmp;
        if(i > 0) {
            auto up = mm.upper_bound(tmp);
            if(up == mm.end()) {
                --up;
                cout << abs(up->first - tmp) << " " << (up->second) + 1<<endl;
                mm[tmp] = i;
                continue;
            }
            int v1 = (up->second) + 1, dif1 = abs(up->first - tmp);
            --up;
            if(up->first == INT_MIN) {
                cout << dif1 << " " << v1<<endl;
                mm[tmp] = i;
                continue;
            }
            int v2 = (up->second) + 1, dif2 = abs(up->first - tmp);
//            cout << dif2 << " " << v2 << ";" << dif1 << " " << v1;
//            cout << endl;
            if(dif1 == dif2)
                cout << dif1 << " " << (arr[v1-1] < arr[v2-1] ? v1 : v2);
            else if(dif1 > dif2)
                cout << dif2 << " " << v2;
            else
                cout << dif1 << " " << v1;

            cout << endl;
        }
        mm[tmp] = i;
    }
    return 0;
}