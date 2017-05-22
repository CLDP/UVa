#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 102;


double x[MAXN], sum[MAXN];
double f[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        double total = 0;
        for (int i = 1; i <= N; ++i) {
            cin >> x[i];
            total += x[i];
        }

        for (int i = 1; i <= N; ++i) x[i] /= total;
        sort(x + 1, x + N + 1, greater<double>());

        for (int i = 1; i <= N; ++i) sum[i] = sum[i - 1] + x[i];

        for (int i = 1; i <= N; ++i) {
            f[i][0] = 1e100;
            for (int j = 1; j <= K; ++j) {
                f[i][j] = 1e100;
                for (int k = 1; k <= i; ++k) {
                    f[i][j] = min(f[i][j], f[k - 1][j - 1] + i * (sum[i] - sum[k - 1]));
                }
            }
        }
        cout << fixed << setprecision(4) << f[N][K] << endl;
    }

    return 0;
}
