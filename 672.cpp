#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;

struct node {
    int T, P, S;
    bool operator < (const node &B) const {
        return T < B.T;
    }
};

node X[MAXN];
int f[MAXN][MAXN];

void update(int &a, int b) {
    if (a < b) a = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, K, M;
        cin >> N >> K >> M;
        for (int i = 1; i <= N; ++i) cin >> X[i].T;
        for (int i = 1; i <= N; ++i) cin >> X[i].P;
        for (int i = 1; i <= N; ++i) cin >> X[i].S;
        sort(X + 1, X + N + 1);

        memset(f, -1, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= K; ++j) {
                int add = 0;
                if (j == X[i].S) add = X[i].P;
                for (int k = 0; k <= K; ++k) {
                    if (f[i - 1][k] == -1) continue;
                    if (abs(j - k) > X[i].T - X[i - 1].T) continue;
                    f[i][j] = max(f[i][j], f[i - 1][k] + add);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= K; ++i) ans = max(ans, f[N][i]);
        cout << ans << endl;
        if (T != 0) cout << endl;
    }

    return 0;
}
