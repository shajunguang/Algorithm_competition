/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 思路：寻找规律，列之间的间隔都是m=2*numRows-2,中间的夹杂的，从第2列到倒数第2列的位置是
 j+m-2*i
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n=s.size(),m=2*numRows-2;
        string res;
        for(int i=0;i<numRows;i++){
            int j=i;
            while(j<n){
                res+=s[j];
                if(i>0 && i<numRows-1 && j+m-2*i<n) //夹杂的
                    res+=s[j+m-2*i];
                j+=m;
            }
        }
        return res;
    }
};
//另一种思路，模拟Z字形过程，用string数组加入min（numrows,s.size())
class Solution_1 {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};