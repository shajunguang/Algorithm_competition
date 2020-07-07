//得出规律时A(n,n)*C(n),这里数太大需要用到大整数，依然打表
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int C[305][2005] = {0}; //第二维表示大整数

int main()
{
    C[1][0] = 1;
    for (int i = 2 ; i < 301 ; ++ i) {
        for (int j = 0 ; j < 2000 ; ++ j)
            C[i][j] += C[i-1][j]*(4*i-2);
        for (int j = 0 ; j < 2000 ; ++ j) {
            C[i][j+1] += C[i][j]/10;
            C[i][j] %= 10;
        }
        for (int j = 1999 ; j >= 0 ; -- j) {
            C[i][j-1] += C[i][j]%(i+1)*10;
            C[i][j] /= (i+1);
        }

        for (int j = 0 ; j < 2000 ; ++ j)
            C[i][j] *= i;
        for (int j = 0 ; j < 2000 ; ++ j) {
            C[i][j+1] += C[i][j]/10;
            C[i][j] %= 10;
        }
    }

    int n;
    while (cin >> n && n) {
        int end = 1999;
        while (!C[n][end]) -- end; //去掉前置0
        while (end >= 0) printf("%d",C[n][end --]); //按位输出
        printf("\n");
    }
    return 0;
}
