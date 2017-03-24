#include <iostream>
using namespace std;

const int MAXN = 40010;

int N, M, D;
int X[MAXN], S[MAXN];
int f[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int times = 0; times < T; ++times) {
        cin >> N >> M >> D;
        --M;
        for (int i = 1; i <= N; ++i) {
            cin >> X[i];
            S[i] = S[i - 1] + X[i];
        }
        if (N % 2 == 1 || 2 * D * M < N || M * 2 > N) {
            cout << "BAD" << endl;
            continue;
        }

        int L = 0, R = S[N];
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            f[0][0] = 0;
            f[0][1] = MAXN;
            for (int i = 2; i <= N; i += 2) {
                f[i][0] = f[i][1] = MAXN;
                for (int j = 1; j <= D && i - j - j >= 0; ++j) {
                    if (S[i] - S[i - j] > mid) break;
                    if (S[i - j] - S[i - j - j] > mid) continue;
                    f[i][0] = min(f[i][0], f[i - j - j][1] + 1);
                    f[i][1] = min(f[i][1], f[i - j - j][0] + 1);
                }
            }
            if (f[N][M % 2] <= M) R = mid; else L = mid;
        }
        cout << R << endl;
    }
    return 0;
}
