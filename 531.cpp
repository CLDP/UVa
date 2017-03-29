#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 101;
string x[MAXN], y[MAXN];
int d1[MAXN], d2[MAXN], f[MAXN][MAXN];

int main() {
    int t, dd, ans;
    string p, q;
    while (cin >> p) {
        int n = 0, m = 0;
        while (p != "#") {
            x[++n] = p;
            cin >> p;
        }
        cin >> p;
        while (p != "#") {
            y[++m] = p;
            cin >> p;
        }
        ans = 0;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (x[i] == y[j]) {
                    if (f[i][j] < f[i - 1][j - 1] + 1) f[i][j] = f[i - 1][j - 1] + 1;
                    if (f[i][j] > ans) {
                        ans = f[i][j];
                        dd = i;
                    }
                }
            }
        }
        t = 0;
        d2[0] = m + 1;
        for (int i = n; i > 0; --i) {
            for (int j = d2[t] - 1; j > 0; --j) {
                if (f[i][j] == ans && x[i] == y[j]) {
                    d1[++t] = i;
                    d2[t] = j;
                    --ans;
                    break;
                }
            }
        }
           
        while (t) {
            cout << x[d1[t--]];
            if (t > 0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
