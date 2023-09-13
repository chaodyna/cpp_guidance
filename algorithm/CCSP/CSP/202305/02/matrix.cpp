#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10010, D = 30;
LL tmp[D][D], ans[N][N];
int n, d;
int Q[N][D], K[N][D], V[N][D], W[N];
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= d; j ++)
            cin >> Q[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= d; j ++)
            cin >> K[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= d; j ++)
            cin >> V[i][j];
    for (int i = 1; i <= n; i ++) cin >> W[i];

	// 计算 K的转置 * V = tmp
    for (int i = 1; i <= d; i ++)
        for (int j = 1; j <= d; j ++)
            for (int k = 1; k <= n; k ++)
                tmp[i][j] += K[k][i] * V[k][j];

    // 计算 Q * tmp = ans
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= d; j ++)
        {
            for (int k = 1; k <= d; k ++)
                ans[i][j] += Q[i][k] * tmp[k][j];
            ans[i][j] *= (LL) W[i];
        }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= d; j ++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}