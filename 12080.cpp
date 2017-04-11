#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 50010;
const int INF = 1000000000;

vector<int> X[MAXN];
bool Z[MAXN];
int f[MAXN][3];

int dp(int a, int fa) {
    if (!Z[a]) return f[a][0] = 0;
    if (X[a].size() == 1 && a != 1) {
        f[a][1] = f[a][2] = 0;
        return f[a][0] = 1;
    }
    f[a][0] = 0;
    while (fa != -1 && X[a][X[a].size() - 1] != fa) {
        int temp = X[a][0];
        for (int i = 0; i + 1 < X[a].size(); ++i) X[a][i] = X[a][i + 1];
        X[a][X[a].size() - 1] = temp;
    }
    if (a != 1) X[a].pop_back();
    for (int i = 0; i < X[a].size(); ++i) f[a][0] += dp(X[a][i], a);

    if (X[a].size() == 1) {
        f[a][1] = f[X[a][0]][1];
        f[a][2] = f[X[a][0]][2];
    } else {
        int b = X[a][0], c = X[a][1];
        f[a][1] = min(INF, f[b][1] + f[c][1]);
        f[a][2] = min(INF, min(min(f[b][0], f[b][2]) + f[c][1], min(f[c][0], f[c][2]) + f[b][1]));
    }
    f[a][0] = min(f[a][0], min(f[a][1], f[a][2]) + 1);
    return f[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N >> M) {
        if (N + M == 0) break;
        for (int i = 1; i <= N; ++i) {
            X[i].clear();
            Z[i] = true;
            f[i][0] = f[i][1] = f[i][2] = INF;
            int K, a;
            cin >> K;
            while (K--) {
                cin >> a;
                X[i].push_back(a);
            }
        }
        for (int i = 0; i < M; ++i) {
            int a;
            cin >> a;
            Z[a] = false;
        }
        cout << dp(1, -1) << endl;
    }
    return 0;
}
