#include <cstdio>
#include <cstring>

const int MAXN = 32;
const int MAXM = 12;
int n, m, ans, dd;
int x[MAXN][MAXM];
int f[MAXN], d[MAXN];

int small(const int a, const int b) {
    for (int i = 0; i < m; ++i) {
        if (x[a][i] >= x[b][i]) return false;
    }
    return true;
}

int max(const int a, const int b) {
    if (a > b) return a; else return b;
}

int swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) scanf("%d", &x[i][j]);
            for (int j = 0; j < m - 1; ++j) {
                for (int k = 1; k < m - j; ++k) {
                    if (x[i][k - 1] > x[i][k]) swap(x[i][k - 1], x[i][k]);
                }
            }
        }
        memset(f, 0, sizeof(f));
        memset(d, 0, sizeof(d));
        ans = 0;
        for (int k = 0; k < n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j)
                    if (small(j, i)) {
                        if (f[i] + 1 > f[j]) {
                            f[j] = f[i] + 1;
                            d[j] = i;
                            if (f[j] > ans) {
                                ans = f[j];
                                dd = j;
                            }
                    }
                }
            }
        }
        ++ans;
        printf("%d\n", ans);
        while (ans) {
            printf("%d", dd);
            dd = d[dd];
            --ans;
            if (ans) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
