#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 502;
const int INF = 1000000000;

int f[MAXN][MAXN][2];
vector<pair<int, int> > X[MAXN];

int dp(int a, int fa) {
    int sa = 1;
    f[a][1][0] = f[a][1][1] = 0;
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i].first == fa) continue;
        int b = X[a][i].first, c = X[a][i].second;
        int sb = dp(b, a);
        for (int i = sa + 1; i <= sa + sb; ++i) f[a][i][0] = f[a][i][1] = INF;
        sa += sb;
        for (int i = sa; i > 1; --i) {
            for (int j = 0; j <= i && j <= sb; ++j) {
                f[a][i][0] = min(f[a][i][0], f[a][i - j][1] + f[b][j][0] + c);
                f[a][i][0] = min(f[a][i][0], f[a][i - j][0] + f[b][j][1] + c + c);
                f[a][i][1] = min(f[a][i][1], f[a][i - j][1] + f[b][j][1] + c + c);
            }
        }
    }
    return sa;
}


int main() {
    ios_base::sync_with_stdio(false);
    int N, M, K, times = 0;
    while (cin >> N) {
        if (N == 0) break;
        for (int i = 0; i <= N; ++i) X[i].clear();
        for (int i = 0; i < N - 1; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            X[a].push_back(make_pair(b, c));
            X[b].push_back(make_pair(a, c));
        }
        dp(0, -1);

        cout << "Case " << ++times << ":" << endl;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            cin >> K;
            for (int j = N; j >= 1; --j) {
                if (f[0][j][0] <= K) {
                    cout << j << endl;
                    break;
                } 
            }
        }
    }
    return 0;
}
