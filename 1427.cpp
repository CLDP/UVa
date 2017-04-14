#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

const int MAXN = 102;
const int MAXM = 10010;
const int INF = 2000000000;

int x[MAXN][MAXM], y[MAXN][MAXM];
int f[MAXM], g[MAXM], h[MAXM], l[MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, K;
    while (cin >> N >> M >> K) {
        if (N + M + K == 0) break;
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j < M; ++j) cin >> x[i][j];
        }
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j < M; ++j) cin >> y[i][j];
        }
        for (int j = 0; j <= M; ++j) f[j] = 0;

        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                g[j] = h[j] = f[j];
                if (j > 0) l[j] = l[j - 1] + y[i][j - 1];
            }
            deque<pair<int, int> > Q;
            Q.push_back(make_pair(g[0], 0));
            int temp = 0;
            for (int j = 1; j <= M; ++j) {
                temp += x[i][j - 1];
                while (!Q.empty() && Q.back().first < g[j] - temp) Q.pop_back();
                Q.push_back(make_pair(g[j] - temp, j));

                while (!Q.empty() && l[j] - l[Q.front().second] > K) Q.pop_front();
                if (!Q.empty()) g[j] = max(g[j], Q.front().first + temp);
            }

            temp = 0;
            Q.clear();
            Q.push_back(make_pair(h[M], M));
            for (int j = M - 1; j >= 0; --j) {
                temp += x[i][j];
                while (!Q.empty() && Q.back().first < h[j] - temp) Q.pop_back();
                Q.push_back(make_pair(h[j] - temp, j));

                while (!Q.empty() && l[Q.front().second] - l[j] > K) Q.pop_front();
                if (!Q.empty()) h[j] = max(h[j], Q.front().first + temp);
            }

            for (int j = 0; j <= M; ++j) f[j] = max(g[j], h[j]);
        }

        int ans = 0;
        for (int i = 0; i <= M; ++i) ans = max(ans, f[i]);
        cout << ans << endl;
    }

    return 0;
}
