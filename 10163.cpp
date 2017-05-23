#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int MAXM = 32;
const int INF = 1000000000;

int x[MAXM];
int f[MAXN][MAXM], g[MAXN][MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N >> M) {
        if (N + M == 0) break;
        for (int i = 0; i < M; ++i) cin >> x[i];
        memset(f, 0, sizeof(f));
        f[0][0] = INF;
        for (int i = 1; i <= N; ++i) f[i][0] = x[0] / i;
        for (int i = 1; i < M; ++i) {
            f[0][i] = INF;
            for (int j = 1; j <= N; ++j) {
                f[j][i] = f[j][i - 1];
                for (int k = 0; k < j; ++k) {
                    f[j][i] = max(f[j][i], min(f[k][i - 1], x[i] / (j - k)));
                }
            }
        }
        int ans = f[N][M - 1];
        memset(g, 0, sizeof(g));
        g[0][0] = 0;
        for (int i = 1; i <= N; ++i) {
            if (f[i][0] >= ans) g[i][0] = x[0]; else g[i][0] = INF;
        }
        for (int i = 1; i < M; ++i) {
            g[0][i] = 0;
            for (int j = 1; j <= N; ++j) {
                g[j][i] = INF;
                if (f[j][i] < ans) continue;
                if (f[j][i - 1] >= ans) g[j][i] = min(g[j][i], g[j][i - 1]);
                for (int k = 0; k < j; ++k) {
                    if (min(f[k][i - 1], x[i] / (j - k)) >= ans) g[j][i] = min(g[j][i], g[k][i - 1] + x[i]);
                }
            }
        }
        if (f[N][M - 1] == 0) g[N][M - 1] = 0;

        cout << f[N][M - 1] << " " << g[N][M - 1] << endl;
    }

    return 0;
}
