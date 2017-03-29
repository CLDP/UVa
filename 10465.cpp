#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
int f[MAXN];


int main() {
    int m, n, t, ans;
    while (scanf("%d%d%d", &m, &n, &t) != EOF) {
        memset(f, 0, sizeof(f));
        for (int i = m; i <= t; i += m) f[i] = f[i - m] + 1;
        f[n] = max(f[n], 1);
        for (int i = n + 1; i <= t; ++i) {
            if (f[i - n]) f[i] = max(f[i], f[i - n] + 1);
        }
        ans = 0;
        while (!f[t - ans] && (t > ans)) ++ans;
        if (ans) printf("%d %d\n", f[t - ans], ans); else printf("%d\n", f[t]);
    }
    return 0;
}
