#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 66;

int N, D, A;
int X[MAXN];
unsigned long long f[MAXN][MAXN];
unsigned long long g[MAXN][MAXN], h[MAXN][MAXN];

bool check(int a, int b, bool one) {
    if (b > A || a - b > N - A) return false;
    int c = a - b;
    if (one) {
        int p = -1, q = MAXN;
        for (int i = 0; i < N; ++i) {
            if (X[i] == 1) {
                --b;
                if (b == 0) p = i; else continue;
            } else {
                if (c > 0) {
                    --c;
                } else
                if (c == 0) {
                    q = i;
                    c = -1;
                }
            }
        }
        if (c > 0) return false;
        if (c == 0) return true;
        return q + D >= p;
    } else {
        int p = MAXN, q = -1;
        for (int i = 0; i < N; ++i) {
            if (X[i] == 0) {
                --c;
                if (c == 0) q = i; else continue;
            } else {
                if (b > 0) {
                    --b;
                } else 
                if (b == 0) {
                    p = i;
                    b = -1;
                }
            }
        }
        if (b > 0) return false;
        if (b == 0) return true;
        return p + D >= q;
    }
    return false;
}

int main() {
    int times = 0;
    unsigned long long K;
    while (cin >> N) {
        if (N == 0) break;
        cin >> D >> K;
        A = 0;
        for (int i = 0; i < N; ++i) {
            X[i] = K % 2;
            A += X[i];
            K /= 2;
        }
        reverse(X, X + N);
        memset(f, 0, sizeof(f));
        f[0][0] = 1;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (f[i][j] == 0) continue;
                if (check(i + 1, j + 1, true)) {
                    if (f[i + 1][j + 1] == 0) {
                        g[i + 1][j + 1] = (g[i][j] << 1) | 1;
                        h[i + 1][j + 1] = (h[i][j] << 1) | 1;
                    } else {
                        g[i + 1][j + 1] = min((g[i][j] << 1) | 1, g[i + 1][j + 1]);
                        h[i + 1][j + 1] = max((h[i][j] << 1) | 1, h[i + 1][j + 1]);
                    }
                    f[i + 1][j + 1] += f[i][j];
                }
                if (check(i + 1, j, false)) {
                    if (f[i + 1][j] == 0) {
                        g[i + 1][j] = (g[i][j] << 1);
                        h[i + 1][j] = (h[i][j] << 1);
                    } else {
                        g[i + 1][j] = min((g[i][j] << 1), g[i + 1][j]);
                        h[i + 1][j] = max((h[i][j] << 1), h[i + 1][j]);
                    }
                    f[i + 1][j] += f[i][j];
                }
            }
        }

        cout << "Case " << ++times << ": " << f[N][A] << " " << g[N][A] << " " << h[N][A] << endl;
    }
    return 0;
}
