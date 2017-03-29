#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 1010;
const int MAXN = 5010;
const int INF = 2100000000;

int x[MAXN], w[MAXN];
int f[MAXM][MAXN];


int DP(const int a, const int b) {
    if (f[a][b] != -1) return f[a][b];
    if (b < 3 * a) {
        f[a][b] = INF;
        return INF;
    } 
    if (a == 0) {
        f[a][b] = 0;
        return 0;
    }
    f[a][b] = min(DP(a, b - 1), DP(a - 1, b - 2) + w[b]);
    return f[a][b];
}

int main() {
    int tt, m, n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d%d", &m, &n);
        m += 8;
        for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
        for (int i = 1; i <= n / 2; ++i) swap(x[i], x[n - i + 1]);
        for (int i = 2; i <= n; ++i) w[i] = (x[i] - x[i - 1]) * (x[i] - x[i - 1]);
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) f[i][j] = -1;
        }
        printf("%d\n", DP(m, n));
    }
    return 0;
}
