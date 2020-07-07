//质因子只有235的第N个数,后面的丑数是由前面丑数乘以2,3,5得到的
#include<bits/stdc++.h>
using namespace std;
int GetUglyNumber_Solution(int index) {
    if (index < 7)return index;
    vector<int> res(index);
    res[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0, i;
    for (i = 1; i < index; ++i)
    {
        res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
        if (res[i] == res[t2] * 2)t2++;
        if (res[i] == res[t3] * 3)t3++;
        if (res[i] == res[t5] * 5)t5++;
    }
    return res[index - 1];
}
int main()
{
    cout<<GetUglyNumber_Solution(1000);
    return 0;
}