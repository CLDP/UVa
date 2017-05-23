#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 18;

long long f[1 << 16];
bool x[MAXN][MAXN];
bool y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N;
        cin >> N;
        for (int i = 0; i <= N; ++i) {
            string P;
            cin >> P;
            for (int j = 0; j < N; ++j) x[i][j] = (P[j] == '1');
        }
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 0; i < (1 << N); ++i) {
            if (f[i] == 0) continue;
            for (int j = 0; j < N; ++j) y[j] = x[0][j];
            for (int j = 0; j < N; ++j) {
                if (!(i & (1 << j))) continue;
                for (int k = 0; k < N; ++k) y[k] |= x[j + 1][k];
            }
            for (int j = 0; j < N; ++j) {
                if (i & (1 << j)) continue;
                if (y[j]) f[i | (1 << j)] += f[i];
            }
        }
        cout << "Case " << times << ": " << f[(1 << N) - 1] << endl;
    }
    return 0;
}
