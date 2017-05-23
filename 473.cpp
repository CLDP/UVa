#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 502;

int f[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int K;
    cin >> K;
    while (K--) {
        int N, T, M;
        cin >> N >> T >> M;

        memset(f, 0, sizeof(f));
        for (int i = 0; i < N; ++i) {
            int a;
            char c;
            cin >> a;
            if (i != N - 1) cin >> c;
            for (int j = M - 1; j >= 0; --j) {
                int temp = 0;
                for (int k = 0; k <= T; ++k) temp = max(temp, f[j][k]);
                f[j + 1][a] = max(f[j + 1][a], temp + 1);
                for (int k = T - a; k >= 0; --k) {
                    f[j][k + a] = max(f[j][k + a], f[j][k] + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j <= T; ++j) ans = max(ans, f[i][j]);
        }
        cout << ans << endl;
        if (K) cout << endl;
    }

    return 0;
}
