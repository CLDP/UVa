#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 105;
const long long INF = 1LL * 100000000 * 100000000;
const double EPS = 1e-6;

int N;
long long f[MAXN][MAXN];
long long x[MAXN], y[MAXN];

long long area(int a, int b, int c) {
    long long A = x[b] - x[a], B = y[b] - y[a];
    long long C = x[c] - x[a], D = y[c] - y[a];
    return abs(A * D - B * C);
}

bool check(int a, int b, int c) {
    for (int i = 0; i < N; ++i) {
        if (i == a || i == b || i == c) continue;
        long long ans = 0;
        ans += area(i, a, b);
        ans += area(i, b, c);
        ans += area(i, c, a);
        if (ans == area(a, b, c)) return false;
    }
    return true;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i];
            x[i + N] = x[i];
            y[i + N] = y[i];
        }

        for (int i = 0; i + 2 < N + N; ++i) f[i][i + 2] = area(i, i + 1, i + 2);
        for (int l = 3; l < N; ++l) {
            for (int i = 0; i + l < N + N; ++i) {
                int j = i + l;
                f[i][j] = INF;
                for (int k = i + 1; k < j; ++k) {
                    if (check(i, k, j)) {
                        f[i][j] = min(f[i][j], max(max(f[i][k], f[k][j]), area(i, k, j)));
                    }
                }
            }
        }
        long long ans = INF;
        for (int i = 0; i < N; ++i) ans = min(ans, f[i][i + N - 1]);
        if (ans & 1) {
            cout << ans / 2 << ".5" << endl;
        } else {
            cout << ans / 2 << ".0" << endl;
        }
    }
    return 0;
}
