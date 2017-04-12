#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAXN = 105;
const int MAXM = 1010;
const double INF = 1e8;

struct Point {
    int a, b;
};

int N, M;
double f[MAXN][MAXN];
Point X[MAXN];
Point Y[MAXM];

bool check(int a, int b) {
    int A = X[b].a - X[a].a;
    int B = X[b].b - X[a].b;
    for (int i = 0; i < M; ++i) {
        int C = Y[i].a - X[a].a;
        int D = Y[i].b - X[a].b;
        if (A * D - B * C >= 0) return false;
    }
    return true;
}

bool area(int a, int b, int c) {
    int A = X[a].a - X[b].a;
    int B = X[a].b - X[b].b;
    int C = X[c].a - X[b].a;
    int D = X[c].b - X[b].b;
    return A * D - B * C != 0;
}

double dist(int a, int b) {
    return sqrt((X[a].a - X[b].a) * (X[a].a - X[b].a) + (X[a].b - X[b].b) * (X[a].b - X[b].b));
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> N >> M) {
        for (int i = 0; i < N; ++i) {
            cin >> X[i].a >> X[i].b;
            X[i + N] = X[i];
        }
        for (int i = 0; i < M; ++i) cin >> Y[i].a >> Y[i].b;

        if (M == 0) {
            double ans = INF;
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    for (int k = j + 1; k < N; ++k) {
                        if (!area(i, j, k)) continue;
                        ans = min(ans, dist(i, j) + dist(j, k) + dist(i, k));
                    }
                }
            }
            cout << fixed << setprecision(2) << ans << endl;
            continue;
        }

        for (int i = 0; i + 1 < N + N; ++i) f[i][i + 1] = dist(i, i + 1);

        for (int l = 2; l <= N; ++l) {
            for (int i = 0; i + l < N + N; ++i) {
                int j = i + l;
                f[i][j] = INF;
                if (check(i, j)) {
                    f[i][j] = dist(i, j);
                } else {
                    for (int k = i + 1; k < j; ++k) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        double ans = INF;
        for (int i = 0; i < N; ++i) ans = min(ans, f[i][i + N]);
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}
