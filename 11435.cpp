#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 1000000007;

struct node {
    int ID, s, t, l;
    int pos, ipos;
    bool operator < (const node &B) const {
        return s < B.s;
    }
};

int N, M;
int f[MAXN][MAXN][2];
bool z[MAXN][MAXN][2];

int s[MAXN];
node X[MAXN], XX[MAXN];
vector<int> Y[MAXN];
// Required prefix sum for each message, real prefix sum
int rpre[MAXN][MAXN], pre[MAXN][MAXN];
// Prefix sum, Finished prefix sum
int sum[MAXN], fsum[MAXN];

int dp(int a, int b, bool c) {
    if (z[a][b][c]) return f[a][b][c];
    z[a][b][c] = true;
    if (b == M + 1) {
        if (a == M) return f[a][b][c] = 0;
        return f[a][b][c] = INF;
    }
    int &ans = f[a][b][c];
    ans = INF;
    if (c == 0) {
        if (X[b].ipos == 0 || Y[X[b].ID][X[b].ipos - 1] <= a) ans = min(ans, dp(a, b, 1));
        ans = min(ans, dp(a, b + 1, 0));
    } else {
        ans = sum[b] - fsum[a] - pre[X[b].ID][X[b].ipos] + rpre[X[b].ID][X[b].ipos];
        if (X[b].ipos + 1 == Y[X[b].ID].size()) {
            ans = max(ans, dp(b, b + 1, 0));
        } else {
            ans = max(ans, dp(a, Y[X[b].ID][X[b].ipos + 1], 1));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int times = 0;
    while (cin >> N >> M) {
        if (N + M == 0) break;
        for (int i = 1; i <= N; ++i) {
            cin >> s[i];
            Y[i].clear();
        }
        for (int i = 1; i <= M; ++i) {
            cin >> X[i].ID >> X[i].s >> X[i].t;
            X[i].l = X[i].t - X[i].s + 1;
            X[i].pos = i;
            Y[X[i].ID].push_back(i);
            X[i].ipos = Y[X[i].ID].size() - 1;
            sum[i] = sum[i - 1] + X[i].l;
        }

        int temp = 0;
        for (int i = 1; i <= M; ++i) {
            if (X[i].ipos + 1 == Y[X[i].ID].size()) temp += s[X[i].ID];
            fsum[i] = temp;
        }

        for (int i = 1; i <= N; ++i) {
            int K = Y[i].size();
            temp = 0;
            for (int j = 0; j < K; ++j) {
                temp += X[Y[i][j]].l;
                pre[i][j] = temp;
                XX[j] = X[Y[i][j]];
            }
            sort(XX, XX + K);
            int p = 0, q = 0;
            temp = 0;
            while (p < K && q < K) {
                if (Y[i][p] < XX[q].pos) {
                    temp += X[Y[i][p]].l;
                    rpre[i][p] = temp;
                    ++p;
                } else
                if (Y[i][p] > XX[q].pos) {
                    temp -= XX[q].l;
                    ++q;
                } else {
                    rpre[i][p] = temp;
                    ++p;
                    ++q;
                }
            }
        }

        memset(z, 0, sizeof(z));
        cout << "Case " << ++times << ": " << dp(0, 1, 0) << endl << endl;
    }
    return 0;
}
