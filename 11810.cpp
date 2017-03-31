#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 16;
const int INF = 1000000007;

struct node {
    int ans;
    int x[MAXN][MAXN];
};

int N, M, K;
int x[MAXN][MAXN];
bool y[MAXN];
int z[MAXN];
node f[1 << 16];

void update(int S, int k, int OS) {
    for (int i = 0; i < N; ++i) {
        if ((S & (1 << i)) == 0 || x[i][k] == INF) continue;
        int temp = f[S].ans;
        for (int j = 0; j < K; ++j) {
            if ((S & (1 << z[j])) == 0) continue;
            temp += f[S].x[z[j]][i] + x[i][k];
        }
        if (temp > f[OS].ans) continue;
        if (y[k]) {
            for (int j = 0; j < N; ++j) {
                if ((S & (1 << j)) == 0) continue;
                temp += f[S].x[j][i] + x[i][k];
            }
        }
        if (temp < f[OS].ans) {
            memcpy(&f[OS], &f[S], sizeof(f[S]));
            f[OS].ans = temp;
            for (int j = 0; j < N; ++j) {
                if ((S & (1 << j)) == 0) continue;
                f[OS].x[j][k] = f[OS].x[k][j] = f[S].x[j][i] + x[i][k];
            }
            f[OS].x[k][k] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        cin >> N >> M >> K;
        memset(y, 0, sizeof(y));
        for (int i = 0; i < K; ++i) {
            cin >> z[i];
            y[z[i]] = true;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) x[i][j] = 0; else x[i][j] = INF;
            }
        }
        for (int i = 0; i < M; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            x[a][b] = x[b][a] = min(x[a][b], c);
        }
        for (int i = 1; i < (1 << N); ++i) {
            f[i].ans = INF;
            if ((i & (i - 1)) == 0) {
                f[i].ans = 0;
                memset(f[i].x, 0, sizeof(f[i].x));
                continue;
            }
            for (int j = 0; j < N; ++j) { 
                if ((i & (1 << j)) == 0 || f[i ^ (1 << j)].ans == INF) continue;
                update(i ^ (1 << j), j, i);
            }
        }
        cout << "Case " << times << ": " << f[(1 << N) - 1].ans << endl;
    }
    return 0;
}
