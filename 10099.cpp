#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int INF = 1000000000;

int x[MAXN][MAXN];

int main() {
    int n, m, num = 0, s, t, p;
    int a, b, c;
    while (true) {
        scanf("%d%d", &n, &m);
        if (!n && !m) break;
         
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) x[i][j] = 0;
        }
          
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            x[a][b] = x[b][a] = c;
        }
         
        scanf("%d%d%d", &s, &t, &p);
         
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    x[i][j] = max(x[i][j], min(x[i][k], x[k][j]));
                }
            }
        }
         
        if (p % (x[s][t] - 1) == 0) 
            p = p / (x[s][t] - 1);
        else 
            p = p / (x[s][t] - 1) + 1;
        printf("Scenario #%d\n", ++num);
        printf("Minimum Number of Trips = %d\n\n", p);
    }
    return 0;
}
