#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int MAXM = 210;
const int INF = 1000000000;

bool x[MAXN][MAXN];
int f[MAXM], g[MAXM];


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) x[i][j] = false;
            x[i][i] = true;
        }
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            x[a][b] = x[b][a] = true;
        }
        cin >> M;
        for (int i = 1; i <= N; ++i) f[i] = 0;
        for (int i = 0; i < M; ++i) {
            int a;
            cin >> a;
            for (int j = 1; j <= N; ++j) g[j] = INF;
            for (int j = 1; j <= N; ++j) {
                if (f[j] == INF) continue;
                for (int k = 1; k <= N; ++k) {
                    if (!x[j][k]) continue;
                    g[k] = min(g[k], f[j] + (k != a));
                }
            }
            for (int j = 1; j <= N; ++j) f[j] = g[j];
        }
        int ans = INF;
        for (int i = 1; i <= N; ++i) ans = min(ans, f[i]);
        cout << ans << endl;
    }
    return 0;
}
