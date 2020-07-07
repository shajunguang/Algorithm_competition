#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++){
        string t;
        while (i < s.size() && s[i] != ';') t += s[i++];
        if (t.empty() || t.size() > 3) {
            i++;
            continue;
        }
        else {
            char c = t[0];
            if (c != 'A' && c != 'D' && c != 'W' && c != 'S') continue;
            int f = 1, step = 0;
            for (int j = 1; j < t.size(); j++) {
                if (!isdigit(t[j])) {
                    f = 0;
                    break;
                }
                else step = step * 10 + t[j] - '0';
            }
            if (f) {
                switch (c) {
                    case 'A':
                        x -= step;
                        break;
                    case 'D':
                        x += step;
                        break;
                    case 'W':
                        y += step;
                        break;
                    case 'S':
                        y -= step;
                }
            }
        }
    }
    cout << x << "," << y;
    return 0;
}