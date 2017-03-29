#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50010;
int d[MAXN], f[MAXN];

int find(int a) {
    if (a != f[a]) f[a] = find(f[a]);
    return f[a];
}

int main() {
    int tt, n, m, ans;
    int a, b, c;
    scanf("%d", &tt);
    while (tt--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            d[i] = 0;
            f[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            if (find(a) != find(b)) f[find(a)] = find(b);
        }
        for (int i = 1; i <= n; ++i) ++d[find(i)];
        for (int i = 1; i <= n; ++i) ans = max(ans, d[i]);
        printf("%d\n", ans);
    }
    return 0;
}
