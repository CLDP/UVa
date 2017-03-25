#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

int N;
int X[MAXN], f[MAXN], g[MAXN], h[MAXN];

void solve(int *f) {
    int R = 1;
    f[0] = 1;
    h[1] = X[0];
    for (int i = 1; i < N; ++i) {
        int P = lower_bound(h + 1, h + R + 1, X[i]) - h;
        h[P] = X[i];
        f[i] = P;
        if (P == R + 1) ++R;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> N) {
        for (int i = 0; i < N; ++i) cin >> X[i];
        solve(f);
        reverse(X, X + N);
        solve(g);
        reverse(g, g + N);
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (min(f[i], g[i]) * 2 - 1 > ans) ans = min(f[i], g[i]) * 2 - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
