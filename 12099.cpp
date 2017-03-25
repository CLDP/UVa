#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 71;
const int MAXW = 31;
const int INF = 1000000007;

struct book {
    int w, h;
    bool operator < (const book &B) const {
        return h > B.h;
    }
};

book X[MAXN];
int f[2][MAXN * MAXW][MAXN * MAXW];
int sum[MAXN];

void update(int &a, int b) {
    if (a == -1 || b < a) a = b;
}

int add(int a, int b) {
    if (a == 0) return b; 
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> X[i].h >> X[i].w;
        sort(X, X + N);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + X[i].w;

        int t = 0;
        f[0][0][0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= sum[i + 1]; ++j) {
                for (int k = 0; k <= sum[i + 1] - j; ++k) f[t ^ 1][j][k] = -1;
            }

            for (int j = 0; j <= sum[i]; ++j) {
                for (int k = 0; k <= sum[i] - j; ++k) {
                    if (f[t][j][k] == -1) continue;
                    update(f[t ^ 1][j][k], f[t][j][k]);
                    update(f[t ^ 1][j + X[i].w][k], f[t][j][k] + add(j, X[i].h));
                    update(f[t ^ 1][j][k + X[i].w], f[t][j][k] + add(k, X[i].h));
                }
            }
            t ^= 1;
        }

        int ans = INF;
        for (int j = 1; j <= sum[N]; ++j) {
            for (int k = 1; k <= sum[N] - j; ++k) {
                if (f[t][j][k] == -1) continue;
                int W = max(max(j, k), sum[N] - j - k);
                int H = f[t][j][k] + X[0].h;
                ans = min(ans, W * H);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
