#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAXN = 2010;

double f[MAXN][MAXN];
double x[MAXN], y[MAXN];

double dist(int a, int b) {
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}


int main() {
    int N;
    while (cin >> N) {
        for (int i = 1; i <= N; ++i) cin >> x[i] >> y[i];
        f[1][1] = 0;
        for (int i = 2; i <= N; ++i) {
            f[1][i] = f[i][1] = f[1][i - 1] + dist(i - 1, i);
        }
        for (int i = 2; i <= N; ++i) {
            f[i][i] = 1e10;
            f[i][i + 1] = 1e10;
            for (int j = 1; j < i; ++j) f[i][i + 1] = min(f[i][i + 1], f[j][i] + dist(j, i + 1));
            f[i + 1][i] = f[i][i + 1];
            for (int j = i + 2; j <= N; ++j) f[i][j] = f[j][i] = f[i][j - 1] + dist(j - 1, j);
        }

        double ans = 1e10;
        for (int i = 1; i <= N; ++i) ans = min(ans, f[i][N] + dist(i, N));
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}
