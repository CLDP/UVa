#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int tt, x[110][110], f[110][110], n, m;
bool z[110][110];


int DP(int a, int b) {
    if (z[a][b]) return f[a][b];
    z[a][b] = true;
    f[a][b] = 1;
    if (a > 0     && x[a - 1][b] < x[a][b]) f[a][b] = max(f[a][b], DP(a - 1, b) + 1);
    if (a < n - 1 && x[a + 1][b] < x[a][b]) f[a][b] = max(f[a][b], DP(a + 1, b) + 1);
    if (b > 0     && x[a][b - 1] < x[a][b]) f[a][b] = max(f[a][b], DP(a, b - 1) + 1);
    if (b < m - 1 && x[a][b + 1] < x[a][b]) f[a][b] = max(f[a][b], DP(a, b + 1) + 1);
    return f[a][b];
}


int main() {
    string p;
    scanf("%d", &tt);
    while (tt--) {
        cin >> p >> n >> m;
        memset(f, 0, sizeof(f));
        memset(z, 0, sizeof(z));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) scanf("%d", &x[i][j]);
        }
        cout << p << ": ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) DP(i, j);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) ans = max(ans, f[i][j]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
