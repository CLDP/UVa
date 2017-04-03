#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;
const int MAXM = 100010;

int X[MAXM], Y[MAXM];
int f[MAXM], g[MAXM], h[MAXM];
bool z[4][MAXN][MAXN][MAXN][4];

void newt(int a, int b, int c, int d) {
    if (d == 0) {
        z[3][a][b][c][0] = z[3][a][b][c][3] = true;

        z[2][a][b][0][0] = z[2][a][b][0][3] = true;
        z[2][a][c][0][0] = z[2][a][c][0][3] = true;
        z[2][b][c][0][0] = z[2][b][c][0][3] = true;

        z[1][a][0][0][0] = z[1][a][0][0][3] = true;
        z[1][b][0][0][0] = z[1][b][0][0][3] = true;
        z[1][c][0][0][0] = z[1][c][0][0][3] = true;
    } else 
    if (d == 1) {
        z[3][a][b][c][1] = true;

        z[2][a][b][0][1] = z[2][a][c][0][1] = true;
        z[2][b][c][0][0] = true;

        z[1][a][0][0][1] = true;
        z[1][b][0][0][0] = z[1][c][0][0][0] = true;
    } else {
        z[3][a][b][c][2] = true;

        z[2][a][b][0][2] = true;
        z[2][a][c][0][1] = z[2][b][c][0][1] = true;

        z[1][a][0][0][1] = z[1][b][0][0][1] = true;
        z[1][c][0][0][0] = true;
    }
}

// delta a, delta g, new h
void update(int a, int da, int dg, int nh) {
    if ((f[a] > f[a - da] + 1) || (f[a] == f[a - da] + 1 && g[a] > g[a - da] + dg) 
        || (f[a] == f[a - da] + 1 && g[a] == g[a - da] + dg && h[a] < nh)) {
        f[a] = f[a - da] + 1;
        g[a] = g[a - da] + dg;
        h[a] = nh;
    }
}

void dp(int a, int b) {
    // h[i] = j is after j, not before j
    if (b == 1) {
        if (z[1][X[a]][0][0][3] && Y[a] <= h[a - 1]) {
            update(a, 1, 0, h[a - 1]);
        }
        if (z[1][X[a]][0][0][0]) {
            update(a, 1, 1, a - 1);
        }
        if (z[1][X[a]][0][0][1] && Y[a] <= h[a - 1]) {
            update(a, 1, 1, a);
        }
        if (z[1][X[a]][0][0][1]) {
            update(a, 1, 2, a);
        }
    } else 
    if (b == 2) {
        if (z[2][X[a - 1]][X[a]][0][3] && Y[a - 1] <= h[a - 2] && Y[a] <= h[a - 2]) {
            update(a, 2, 0, h[a - 2]);
        }
        if (z[2][X[a - 1]][X[a]][0][0] && Y[a] <= a - 2) {
            update(a, 2, 1, a - 2);
        }
        if (z[2][X[a - 1]][X[a]][0][1] && Y[a - 1] <= h[a - 2]) {
            update(a, 2, 1, a - 1);
        }
        if (z[2][X[a - 1]][X[a]][0][1]) {
            update(a, 2, 2, a - 1);
        }
        if (z[2][X[a - 1]][X[a]][0][2] && Y[a - 1] <= h[a - 2] && Y[a] <= h[a - 2]) {
            update(a, 2, 1, a);
        }
        if (z[2][X[a - 1]][X[a]][0][2] && Y[a] <= a - 2) {
            update(a, 2, 2, a);
        }
    } else {
        if (z[3][X[a - 2]][X[a - 1]][X[a]][3] && Y[a - 2] <= h[a - 3] && Y[a - 1] <= h[a - 3] && Y[a] <= h[a - 3]) {
            update(a, 3, 0, h[a - 3]);
        }
        if (z[3][X[a - 2]][X[a - 1]][X[a]][0] && Y[a - 1] <= a - 3 && Y[a] <= a - 3) {
            update(a, 3, 1, a - 3);
        }
        if (z[3][X[a - 2]][X[a - 1]][X[a]][1] && Y[a - 2] <= h[a - 3] && Y[a] <= a - 2) {
            update(a, 3, 1, a - 2);
        }
        if (z[3][X[a - 2]][X[a - 1]][X[a]][1] && Y[a] <= a - 2) {
            update(a, 3, 2, a - 2);
        }
        if (z[3][X[a - 2]][X[a - 1]][X[a]][2] && Y[a - 2] <= h[a - 3] && Y[a - 1] <= h[a - 3]) {
            update(a, 3, 1, a - 1);
        }
        if (z[3][X[a - 2]][X[a - 1]][X[a]][2] && Y[a - 1] <= a - 3) {
            update(a, 3, 2, a - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N, M;
        cin >> N >> M;
        memset(z, 0, sizeof(z));
        for (int i = 1; i <= N; ++i) {
            string P;
            int d;
            cin >> P >> d;
            newt(P[0] - 'A', P[1] - 'A', P[2] - 'A', d);
        }
        for (int i = 1; i <= M; ++i) {
            char C;
            cin >> C >> Y[i];
            X[i] = C - 'A';
            f[i] = g[i] = M + 1;
            h[i] = 0;
        }

        dp(1, 1);
        if (M > 1) {
            dp(2, 1);
            dp(2, 2);
        }
        for (int i = 3; i <= M; ++i) {
           for (int j = 1; j <= 3; ++j) dp(i, j);
        }

        if (times > 1) cout << endl;
        cout << f[M] << " " << g[M] << endl;
    }

    return 0;
}
