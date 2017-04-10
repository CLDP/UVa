#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 22;
const int MAXK = 1020;
const int INF = 10007;
const int MX[4] = {-1, 1, 0, 0};
const int MY[4] = {0, 0, -1, 1};


int N, M, K;
int X[MAXN][MAXN];
bool Z[MAXN][MAXN];
int f[2][MAXK], g[MAXK], h[MAXK];
vector<int> B, W;

void dfs(int a, int b) {
    if (a < 1 || a > N || b < 1 || b > M || Z[a][b] || X[a][b] == -1) return ;
    if ((a + b) % 2 == 0) {
        B.push_back(X[a][b]);
    } else {
        W.push_back(X[a][b]);
    }
    Z[a][b] = true;
    for (int i = 0; i < 4; ++i) dfs(a + MX[i], b + MY[i]);
}

int cal(vector<int> &B, int *g) {
    int L = 0, ans = 0;
    for (int i = 0; i < B.size(); ++i) L += B[i];
    ans = L;
    for (int i = 0; i <= K; ++i) g[i] = 0;
    L = min(L, K);
    g[0] = 1;
    int R = 0;
    for (int i = 0; i < B.size(); ++i) {
        for (int k = R; k >= 0; --k) {
            for (int j = 1; j <= B[i]; ++j) g[k + j] = (g[k + j] + g[k]) % INF;
        }
        R += B[i];
        R = min(R, L);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int cnt = 0;
        cin >> N >> M >> K;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cin >> X[i][j];
                Z[i][j] = false;
            }
        }

        int cur = 1;
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (Z[i][j] || X[i][j] == -1) continue;
                B.clear();
                W.clear();
                dfs(i, j);

                int a = cal(B, g);
                int b = cal(W, h);
                int c = a, d = b;
                if (a > b) {
                    a -= b; 
                    b = 0;
                } else {
                    b -= a;
                    a = 0;
                }

                for (int k = 0; k <= K; ++k) f[cur][k] = 0;

                for (int k = 0; a + k <= c && b + k <= d && a + b + k + k <= K; ++k) {
                    for (int l = 0; l + a + b + k + k <= K; ++l) {
                        if (f[!cur][l] == 0) continue;
                        f[cur][l + a + b + k + k] += ((f[!cur][l] * g[a + k]) % INF) * h[b + k] % INF;
                        f[cur][l + a + b + k + k] %= INF;
                    }
                }
                cur = !cur;
            }
        }
        int ans = 0;
        for (int i = 0; i <= K; ++i) ans = (ans + f[!cur][i]) % INF;
        cout << ans << endl;
    }

    return 0;
}
