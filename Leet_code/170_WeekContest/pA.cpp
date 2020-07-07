#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string freqAlphabets(string s) {
        string ret;
        int i = 0;
        while (i < s.size()) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                int c = (s[i] - '0') * 10 + (s[i + 1] - '0');
                ret.push_back(char(c + 'a' - 1));
                i += 3;
            } else {
                int c = (s[i] - '0');
                ret.push_back(char(c + 'a' - 1));
                i += 1;
            }
        }
        return ret;
    }
};
int main()
{
    return 0;
}