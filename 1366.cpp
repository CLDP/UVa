#include <iostream>
using namespace std;

const int MAXN = 510;

int x[MAXN][MAXN], y[MAXN][MAXN];
int l[MAXN][MAXN], u[MAXN][MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N >> M) {
        if (N + M == 0) break;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) cin >> x[i][j];
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) cin >> y[i][j];
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                l[i][j] = l[i][j - 1] + x[i][j];
                u[i][j] = u[i - 1][j] + y[i][j];
            }
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                f[i][j] = max(f[i - 1][j], g[i - 1][j]) + l[i][j];
                g[i][j] = max(f[i][j - 1], g[i][j - 1]) + u[i][j];
            }
        }
        cout << max(f[N][M], g[N][M]) << endl;
    }
    return 0;
}
