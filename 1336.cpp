#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const double INF = 1e20;
const double EPS = 1e-6;

struct node {
    int x, c, d;
    node() {}
    node(int _x, int _c, int _d): x(_x), c(_c), d(_d) {}
    bool operator < (const node &B) const {
        return x < B.x;
    }
};

int N, V, xs;
node X[MAXN];
int sum[MAXN];
double f[MAXN][MAXN][2];

double cost(int D, int V, int S) {
    return 1.0 * D / V * S;
}

void update(int a, int b, int c, int p, int q, int r, double add) {
    f[a][b][c] = min(f[a][b][c], f[p][q][r] + add);
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> N >> V >> xs) {
        if (N == 0) break;
        for (int i = 0; i < N; ++i) cin >> X[i].x >> X[i].c >> X[i].d;
        X[N++] = node(xs, 0, 0);
        sort(X, X + N);
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) f[i][j][0] = f[i][j][1] = INF;
        }
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + X[i].d;
        xs = lower_bound(X, X + N, node(xs, 0, 0)) - X;
        f[xs][xs][0] = 0;

        for (int l = 0; l < N - 1; ++l) {
            for (int i = 0; i + l < N; ++i) {
                int j = i + l, sumN = sum[N] - (sum[j + 1] - sum[i]);
                if (f[i][j][0] < INF) {
                    if (i > 0) update(i - 1, j, 0, i, j, 0, cost(X[i].x - X[i - 1].x, V, sumN) + X[i - 1].c);
                    if (j < N - 1) update(i, j + 1, 1, i, j, 0, cost(X[j + 1].x - X[i].x, V, sumN) + X[j + 1].c);
                }
                if (f[i][j][1] < INF) {
                    if (i > 0) update(i - 1, j, 0, i, j, 1, cost(X[j].x - X[i - 1].x, V, sumN) + X[i - 1].c);
                    if (j < N - 1) update(i, j + 1, 1, i, j, 1, cost(X[j + 1].x - X[j].x, V, sumN) + X[j + 1].c);
                }
            }
        }
        cout << (int)(min(f[0][N - 1][0], f[0][N - 1][1]) + EPS) << endl;
    }
    return 0;
}
