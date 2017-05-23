#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int MAXL = 510;
const int INF = 1000000000;

int N, L, C;
int x[MAXN];
int f[MAXN][MAXN];


int cost(int a) {
    if (a == 0) return 0;
    if (a <= 10) return -C;
    return (a - 10) * (a - 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    int times = 0;
    while (cin >> N) {
        if (N == 0) break;
        cin >> L >> C;
        for (int i = 0; i < N; ++i) cin >> x[i];
        if (times) cout << endl;
        cout << "Case " << ++times << ":" << endl;
        int ans = 1, temp = 0;
        for (int i = 0; i < N; ++i) {
            if (temp + x[i] > L) {
                temp = x[i];
                ++ans;
            } else {
                temp += x[i];
            }
        }
        cout << "Minimum number of lectures: " << ans << endl;
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= ans; ++j) f[i][j] = INF;
        }
        f[0][0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= ans; ++j) {
                int temp = x[i], k = i;
                while (temp <= L) {
                    f[i + 1][j] = min(f[i + 1][j], f[k][j - 1] + cost(L - temp));
                    if (k == 0) break;
                    temp += x[--k];
                }
            }
        }
        cout << "Total dissatisfaction index: " << f[N][ans] << endl;
    }

    return 0;
}
