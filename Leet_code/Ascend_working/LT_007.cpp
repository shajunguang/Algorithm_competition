/*
 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 思路：字符串法，利用stringstream读入数字，读出字符串，反转答案，再读回结果，两次之间
 一定一定要清空流
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long result; //利用long避免溢出
        if (x == INT_MIN)
        {
            return 0;
        }
        if (x < 0)
        {
            return -reverse(-x);
        }
        stringstream ss;
        ss << x;
        string tmpStr;
        ss >> tmpStr;

        int tmpStrSize = int(tmpStr.size());
        string resultStr;
        for (int index = tmpStrSize - 1; index >= 0; index--)
        {
            resultStr.push_back(tmpStr[index]);
        }
        ss.clear(); //使用前记得clear
        ss << resultStr;
        ss >> result;
        if (result > INT_MAX)
        {
            return 0;
        }
        return int(result);
    }
};
//另一种数学方法,注意中间判断溢出情况
class Solution_1 {
public:
    int reverse(int x){
        int ans=0;
        while(x) {
            if(ans>0 && ans>(INT_MAX-x%10)/10) return 0;
            if(ans<0 && ans<(INT_MIN-x%10)/10) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};