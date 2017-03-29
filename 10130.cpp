#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
const int MAXM = 31;
int w[MAXN], v[MAXN];
int f[MAXN * MAXM];


int main() {
    int n, m, tt, ans, a;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d", &w[i], &v[i]);
        ans = 0;
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &a);
            memset(f, 0, sizeof(f));
            for (int i = 0; i < n; ++i) {
                for (int j = a; j >= v[i]; --j) {
                    f[j] = max(f[j], f[j - v[i]] + w[i]);
                }
            }
            ans += f[a];
        }
        printf("%d\n", ans);
    }
    return 0;
}
