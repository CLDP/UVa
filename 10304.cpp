#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 252;
const int INF = 1000000000;

int x[MAXN], s[MAXN], f[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    while (cin >> N) {
        for (int i = 1; i <= N; ++i) {
            cin >> x[i];
            s[i] = s[i - 1] + x[i];
            f[i][i] = 0;
        }
        for (int l = 1; l < N; ++l) {
            for (int i = 1; i + l <= N; ++i) {
                int j = i + l;
                f[i][j] = INF;
                for (int k = i; k <= j; ++k) f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j] + s[j] - s[i - 1] - x[k]);
            }
        }
        cout << f[1][N] << endl;
    }
    return 0;
}
