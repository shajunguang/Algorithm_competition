//在2048基础上,错排上乘上组合情况
//F[n]=(n-1)*(F[n-1]+F[n-2])错排情况
//C(m,n)=C(m-1,n)+C(m-1,n-1)
#include <stdio.h>

long long f[25] = {0, 0, 1};
long long a[25][25];
int fun()
{
    for(int i = 3; i <= 20; i++)
        f[i] = (i - 1)*(f[i - 1] + f[i - 2]);
}

int sum()
{
    for(int i = 0; i <= 20; i++)
        a[i][0] = a[i][i] = 1;
    for(int i = 2; i <= 20; i++)
        for(int j = 1; j < i; j++)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
}
int main()
{
    fun();
    sum();
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%lld\n", a[n][m]*f[m]);
    }
    return 0;
}