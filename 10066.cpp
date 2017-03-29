#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;


const int MAXN = 111;
int n, m, ans, num;
int x[MAXN], y[MAXN], z[MAXN], f[MAXN][MAXN];


int main() {
    scanf("%d%d", &n, &m); 
    while (n || m) {
        ans = 0;
        for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
        for (int i = 1; i <= m; ++i) scanf("%d", &y[i]);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                if (x[i] == y[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
                ans = max(ans, f[i][j]);
            }
        }
        printf("Twin Towers #%d\n", ++num);
        printf("Number of Tiles : %d\n\n", ans);
        scanf("%d%d", &n, &m); 
    }
    return 0;
}
