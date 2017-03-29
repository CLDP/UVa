#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 3660;
bool f[MAXN];

int main() {
    int tt, n, m, a, b, ans;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < m; ++i) {
            cin >> a;
            b = 0;
            while ((b += a) <= n) f[b] = true;
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 7 != 0 && i % 7 != 6) ans += f[i];
        }
        cout << ans << endl;
    }
    return 0;
}
