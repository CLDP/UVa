#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int MAXM = 21000;
const long long INF = 1LL * 100000000 * 100000000;

long long f[MAXN][MAXM];
long long X[MAXN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long M;
        cin >> N >> M;
        vector<long long> Y;
        for (int i = 0; i < N; ++i) {
            cin >> X[i];
            Y.push_back(X[i]);
            for (int j = 1; j <= N - 2; ++j) {
                Y.push_back(X[i] + M * j);
                if (X[i] - M * j >= 0) Y.push_back(X[i] - M * j);
            }
        }

        if (N == 2) {
            if (abs(X[1] - X[0]) <= M) {
                cout << 0 << endl;
            } else {
                cout << "impossible" << endl;
            }
            continue;
        }

        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());

        for (int i = 0; i < Y.size(); ++i) {
            f[0][i] = INF;
            if (Y[i] == X[0]) f[0][i] = 0;
        }

        for (int i = 1; i < N - 1; ++i) {
            deque<pair<long long, long long> > Q;
            int k = 0;
            for (int j = 0; j < Y.size(); ++j) {
                while (k < Y.size() && Y[k] - Y[j] <= M) {
                    while (!Q.empty() && Q.back().first > f[i - 1][k]) Q.pop_back();
                    Q.push_back(make_pair(f[i - 1][k], Y[k]));
                    ++k;
                }
                while (!Q.empty() && Y[j] - Q.front().second > M) Q.pop_front();
                f[i][j] = min(INF, Q.front().first + abs(Y[j] - X[i]));
            }
        }
        long long ans = INF;
        for (int i = 0; i < Y.size(); ++i) {
            if (abs(Y[i] - X[N - 1]) <= M) ans = min(ans, f[N - 2][i]);
        }
        if (ans == INF) cout << "impossible" << endl; else cout << ans << endl;
    }

    return 0;
}
