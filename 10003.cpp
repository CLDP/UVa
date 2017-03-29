#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAXN = 52;
const int INF = 1000000000;
int f[MAXN][MAXN];
bool ff[MAXN][MAXN];
int x[MAXN];


int DP(const int a, const int b) {
    if (ff[a][b]) return f[a][b];
    if (a + 1 == b) return 0;
    f[a][b] = INF;
    ff[a][b] = 1;
    for (int i = a + 1; i < b; ++i) 
        f[a][b] = min(f[a][b], DP(a, i) + DP(i, b) + x[b] - x[a]);
    return f[a][b];
}

int main() {
    int n, m;
    scanf("%d", &n);
    while (n) {
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) scanf("%d", &x[i]);
        x[++m] = n;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 1; j < m; ++j) {
                if (x[j - 1] > x[j]) swap(x[j - 1], x[j]);
            }
        }
        
        memset(ff, 0, sizeof(ff));
        printf("The minimum cutting is %d.\n", DP(0, m));
        scanf("%d", &n);
    }
    return 0;
}
