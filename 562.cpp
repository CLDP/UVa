#include <cstdio>
#include <cstring>

const int MAXM = 50010;
const int MAXN = 110;
bool f[MAXM];


int main() {
    int tt, n, a, total, ans;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        memset(f, 0, sizeof(f));
        f[0] = true;
        total = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            total += a;
            for (int j = MAXM - 1; j >= a; --j) f[j] = f[j] || f[j - a];
        }
        if (total % 2) ans = 1; else ans = 0;
        total >>= 1;
        while (!f[total] && !f[total + ans]) {
            --total;
            ans += 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
