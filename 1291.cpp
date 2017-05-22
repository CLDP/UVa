#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int f[5][5], g[5][5];

int dist(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return 2;
    if (a == 1 && b == 3) return 4;
    if (a == 2 && b == 4) return 4;
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    int a;
    while (cin >> a) {
        if (a == 0) break;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) f[i][j] = INF;
        }
        f[0][0] = 0;

        while (a != 0) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) g[i][j] = INF;
            }
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (f[i][j] == INF) continue;
                    if (i == a || j == a) {
                        g[i][j] = min(g[i][j], f[i][j] + 1);
                        continue;
                    }
                    g[a][j] = min(g[a][j], f[i][j] + dist(i, a));
                    g[i][a] = min(g[i][a], f[i][j] + dist(a, j));
                }
            }
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) f[i][j] = g[i][j];
            }
            cin >> a;
        }

        int ans = 1000000000;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) ans = min(ans, f[i][j]);
        }
        cout << ans << endl;
    }

    return 0;
}
