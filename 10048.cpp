#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int INF = 1000000000;
int x[MAXN][MAXN];

int main() {
    int n, m, t, num = 0;
    int a, b, c;
    while (true) {
        scanf("%d%d%d", &n, &m, &t);
        if (!n && !m && !t) break;
        if (n && num) printf("\n");
         
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) x[i][j] = INF;
        }
          
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            x[a][b] = x[b][a] = c;
        }
         
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    x[i][j] = min(x[i][j], max(x[i][k], x[k][j]));
                }
            }
        }
         
        printf("Case #%d\n", ++num);
        while (t--) {
            scanf("%d%d", &a, &b);
            if (x[a][b] != INF) 
                printf("%d\n", x[a][b]);
            else 
                printf("no path\n");
        }
    }
    return 0;
}
