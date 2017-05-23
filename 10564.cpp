#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 22;
const int MAXS = 502;

int x[MAXN + MAXN][MAXN];
long long f[MAXN + MAXN][MAXN][MAXS];

int main() {
    ios_base::sync_with_stdio(false);
    int N, S;
    while (cin >> N >> S) {
        if (N + S == 0) break;
        memset(x, 0, sizeof(x));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N - i; ++j) cin >> x[i][j];
        }
        for (int i = N; i < N + N - 1; ++i) {
            for (int j = 0; j < i - N + 2; ++j) cin >> x[i][j];
        }
        memset(f, 0, sizeof(f));
        for (int j = 0; j < N; ++j) f[N + N - 2][j][x[N + N - 2][j]] = 1;

        for (int i = N + N - 3; i >= N - 1; --i) {
            for (int j = 0; j < i - N + 2; ++j) {
                for (int k = x[i][j]; k <= S; ++k) {
                    f[i][j][k] = f[i + 1][j][k - x[i][j]] + f[i + 1][j + 1][k - x[i][j]];
                }
            }
        }

        for (int i = N - 2; i >= 0; --i) {
            for (int j = 0; j < N - i; ++j) {
                for (int k = x[i][j]; k <= S; ++k) {
                    f[i][j][k] = f[i + 1][j][k - x[i][j]];
                    if (j > 0) f[i][j][k] += f[i + 1][j - 1][k - x[i][j]];
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < N; ++i) ans += f[0][i][S];
        cout << ans << endl;
        if (ans == 0) {
            cout << endl;
            continue;
        }
        int a = 0, b = 0;
        for (int i = 0; i < N; ++i) {
            if (f[0][i][S]) {
                b = i;
                break;
            }
        }
        S -= x[0][b];
        cout << b << " ";
        for (int i = 0; i < N - 1; ++i) {
            if (b > 0 && f[a + 1][b - 1][S]) {
                cout << "L";
                ++a;
                --b;
                S -= x[a][b];
            } else {
                cout << "R";
                ++a;
                S -= x[a][b];
            }
        }

        for (int i = N - 1; i < N + N - 2; ++i) {
            if (f[a + 1][b][S]) {
                cout << "L";
                ++a;
                S -= x[a][b];
            } else {
                cout << "R";
                ++a;
                ++b;
                S -= x[a][b];
            }
        }
        cout << endl;
    }
    return 0;
}
