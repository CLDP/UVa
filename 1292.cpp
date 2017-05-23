#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1510;

vector<int> X[MAXN];
int f[MAXN][2];

int dp(int a, int b, int fa) {
    if (f[a][b] != -1) return f[a][b];
    f[a][b] = b;
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i] == fa) continue;
        if (b == 1) {
            f[a][b] += min(dp(X[a][i], 0, a), dp(X[a][i], 1, a));
        } else {
            f[a][b] += dp(X[a][i], 1, a);
        }
    }
    return f[a][b];
}

int main() {
    int N;
    while (cin >> N) {
        for (int i = 0; i < N; ++i) X[i].clear();
        for (int i = 0; i < N; ++i) {
            int a, b, M;
            char c;
            cin >> a >> c >> c >> M >> c;
            for (int j = 0; j < M; ++j) {
                cin >> b;
                X[a].push_back(b);
                X[b].push_back(a);
            }
        }
        memset(f, -1, sizeof(f));
        cout << min(dp(0, 0, -1), dp(0, 1, -1)) << endl;
    }
    return 0;
}
