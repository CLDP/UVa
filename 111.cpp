#include <cstdio>
#include <cstring>

const int MAXN = 22;
int ans, w[MAXN], x[MAXN], y[MAXN], z[MAXN];
int f[MAXN][MAXN];
bool ff[MAXN][MAXN];

int max(const int a, const int b) {
    if (a > b) return a; else return b;
}

int DP(const int a, const int b) {
    if (ff[a][b]) return f[a][b];
    if (a == 0 || b == 0) return 0;
    ff[a][b] = true;
    f[a][b] = max(DP(a, b - 1), DP(a - 1, b));
    if (x[a] == y[b]) f[a][b] = max(f[a][b], DP(a - 1, b - 1) + 1);
    ans = max(ans, f[a][b]);
    return f[a][b];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
        x[w[i]] = i;
    }
    while (scanf("%d", &z[1]) != EOF) {
        for (int j = 2; j <= n; ++j) scanf("%d", &z[j]);
        for (int j = 1; j <= n; ++j) y[z[j]] = j;
        memset(ff,0,sizeof(ff));
        ans = 0;
        DP(n, n);
        printf("%d\n", ans);
    }
    return 0;
}
