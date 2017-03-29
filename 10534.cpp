#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

int x[MAXN], f[MAXN], g[MAXN], p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    while (cin >> N) {
        for (int i = 1; i <= N; ++i) cin >> x[i];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));

        int m = 1;
        for (int i = 1; i <= N; ++i) {
            int t = lower_bound(p + 1, p + m, x[i]) - p;
            p[t] = x[i];
            f[i] = t;
            if (t == m) ++m;
        }

        m = 1;
        for (int i = N; i >= 1; --i) {
            int t = lower_bound(p + 1, p + m, x[i]) - p;
            p[t] = x[i];
            g[i] = t;
            if (t == m) ++m;
        }
        int ans = 0;
        for (int i = 1; i <= N; ++i) ans = max(ans, min(f[i], g[i]) * 2 - 1);
        cout << ans << endl;
    }
    return 0;
}
