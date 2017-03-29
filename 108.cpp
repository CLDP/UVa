#include <cstdio>

const int MAXN = 111;
const int inf = 2100000000;

int x[MAXN][MAXN], y[MAXN][MAXN], z[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) scanf("%d", &x[i][j]);
    }
     
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) y[i][j] = y[i - 1][j] + x[i][j];
    }
     
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) y[i][j] = y[i][j - 1] + y[i][j];
    }
     
    int ans = -inf;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = i; k <= n; ++k) {
                for (int l = j; l <= n; ++l) {
                    if (y[k][l] - y[i - 1][l] - y[k][j - 1] + y[i - 1][j - 1] > ans)
                        ans = y[k][l] - y[i - 1][l] - y[k][j - 1] + y[i - 1][j - 1];
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
