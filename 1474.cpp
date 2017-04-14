#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 4010;
const long long INF = 1LL * 1000000000 * 1000000000;

pair<int, int> X[MAXN], Y[MAXN];
long long f[MAXN][MAXN];
int g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N) {
        for (int i = 1; i <= N; ++i) {
            cin >> X[i].first;
            X[i].second = i;
        }
        cin >> M;
        for (int i = 1; i <= M; ++i) {
            cin >> Y[i].first;
            Y[i].second = i;
        }
        sort(X + 1, X + N + 1);
        sort(Y + 1, Y + M + 1);
        for (int i = 0; i <= N + 1; ++i) {
            for (int j = 0; j <= M + 1; ++j) f[i][j] = INF;
        }
        f[0][0] = 0;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= min(i, M); ++j) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + abs(X[i].first - Y[j].first);
            }

        }
        cout << f[N][M] << endl;
        int A = N, B = M;
        while (A > 0) {
            if (f[A][B] == f[A - 1][B] + abs(X[A].first - Y[B].first)) {
                g[A--] = B;
                continue;
            }
            if (f[A][B] == f[A - 1][B - 1] + abs(X[A].first - Y[B].first)) {
                g[A--] = B--;
                continue;
            }
        }
        vector<pair<int, int> > ans;
        for (int i = 1; i <= N; ++i) {
            ans.push_back(make_pair(X[i].second, Y[g[i]].second));
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i) cout << ans[i].second << " ";
        cout << endl;
    }
    return 0;
}
