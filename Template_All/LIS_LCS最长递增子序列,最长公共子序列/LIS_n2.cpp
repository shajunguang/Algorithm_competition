//最长递增子序列
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int Lis[MAXN];

int main()
{
    int q[6]={1,-1,2,-1,4,5};
    Lis[0]=1;
    for(int i=1;i<6;i++) {
        for (int j = i; j >= 0; j--) {
            Lis[i] = 1;
            if (q[j] < q[i]) Lis[i] = max(Lis[i], Lis[j] + 1);
        }
    }
    printf("%d",Lis[5]);
    return 0;
}