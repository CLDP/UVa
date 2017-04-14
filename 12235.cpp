#include <iostream>
using namespace std;

const int MAXN = 105;
const int INF = 1000000000;

int x[MAXN];
int f[MAXN][MAXN][1 << 8][9];

int count(int a) {
    int ans = 0;
    while (a > 0) {
        ans += a % 2; 
        a /= 2;
    }
    return ans;
}

int main() {
    int N, K, times = 0;
    while (cin >> N >> K) {
        if (N + K == 0) break;
        for (int i = 1; i <= N; ++i) {
            cin >> x[i];
            x[i] -= 25;
        }
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= K; ++j) {
                for (int k = 0; k < (1 << 8); ++k) {
                    for (int l = 0; l < 8; ++l) f[i][j][k][l] = INF;
                }
            }
        }

        for (int i = 0; i < 8; ++i) f[0][0][0][i] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= min(K, N); ++j) {
                for (int k = 0; k < (1 << 8); ++k) {
                    for (int l = 0; l < 8; ++l) {
                        if (f[i][j][k][l] == INF) continue;
                        int c = x[i + 1];
                        int nk = k | (1 << c);
                        f[i + 1][j + 1][k][l] = min(f[i + 1][j + 1][k][l], f[i][j][k][l]);
                        f[i + 1][j][nk][c] = min(f[i + 1][j][nk][c], f[i][j][k][l] + (c != l));
                    }
                }
            }
        }

        int all = 0;
        for (int i = 1; i <= N; ++i) all |= (1 << x[i]);

        int ans = INF;
        for (int i = 0; i < (1 << 8); ++i) {
            for (int j = 0; j < 8; ++j) {
                ans = min(ans, f[N][K][i][j] + count(all ^ i) + (i != 0));
            }
        }
        cout << "Case " << ++times << ": " << ans << endl << endl;
    }

    return 0;
}
