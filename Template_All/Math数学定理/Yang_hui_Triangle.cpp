#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=60;
LL c[N][N];
void C()
{
    int i,j;
    for(i=0;i<N;i++)
        c[i][0]=c[i][i]=1;
    for(i=1;i<N;i++)
        for(j=1;j<=i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
}
int main()
{
    C();
    for(auto & i : c) {
        for (long long j : i)
            printf("%-18lld", j);
        printf("\n");
    }
    return 0;
}