//二维费用问题,增加重量一维,本身可以和01背包,完全背包,多重背包相结合
//转移方程f[i][j]=max(f[i][j],f[i-v][j-m]+w) 体积为i,重量为j时的最大价值
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, V, M;
int f[N][N];

int main() {

    cin >> n >> V >> M;

    for (int i = 0; i < n; i ++) {
        int v, m, w;
        cin >> v >> m >> w;

        for (int j = V; j >= v; j --)
            for (int k = M; k >= m; k --)
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
    }

    cout << f[V][M] << endl;
    return 0;
}