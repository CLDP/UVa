#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXM = 12;
const int MAXN = 110;
const int INF = 1000000000;
int n, m, ans, d;
int x[MAXM][MAXN] ,f[MAXM][MAXN];
bool ff[MAXM][MAXN];

int min(const int a, const int b) {
    if (a < b) return a; else return b;
}

int DP(const int a, const int b) {
    if (ff[a][b]) return f[a][b];
    if (b == n - 1) {
        f[a][b] = x[a][b];
        ff[a][b] = 1;
        return f[a][b];
    }
    ff[a][b] = 1;
    f[a][b] = DP(a, b + 1);
    f[a][b] = min(f[a][b], DP((a + m - 1) % m, b + 1)); 
    f[a][b] = min(f[a][b], DP((a + 1) % m, b + 1)); 
    f[a][b] += x[a][b];
    return f[a][b];
}

bool find(const int a, const int b) {
    if (a == n) return true;
    printf("%d", b + 1);
    if (a < n - 1) printf(" ");
    if (b == 0) {
        if (f[0][a + 1] == f[b][a] - x[b][a]) return find(a + 1,0);
        if (f[1][a + 1] == f[b][a] - x[b][a]) return find(a + 1,1);
        if (f[m - 1][a + 1] == f[b][a] - x[b][a]) return find(a + 1, m - 1);
    }
    if (b == m - 1) {
        if (f[0][a + 1] == f[b][a] - x[b][a]) return find(a + 1, 0);
        if (f[m - 2][a + 1] == f[b][a] - x[b][a]) return find(a + 1, m - 2);
        if (f[m - 1][a + 1] == f[b][a] - x[b][a]) return find(a + 1, m - 1);
    }
    for (int i = b - 1; i <= b + 1; ++i) {
        if (f[i][a + 1] == f[b][a] - x[b][a]) return find(a + 1, i);
    }
}

int main() {
    while (scanf("%d", &m) != EOF) {
        scanf("%d", &n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) scanf("%d", &x[i][j]);
        }
        
        memset(ff, 0, sizeof(ff));
        memset(f, 0, sizeof(f));
        for (int i = 0; i < m; ++i) DP(i, 0);
        
        ans = INF;
        for (int i = 0; i < m; ++i) 
         if (f[i][0] < ans) {
             ans = f[i][0];
             d = i;
         }
        find(0, d);
        printf("\n%d\n", ans);
    }
    return 0;
}
