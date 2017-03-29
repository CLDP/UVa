#include <cstdio>

const int INF  = 1 << 30;
const int MAXN = 1001;
const int MAXM = 1000001;

int t, n, m;
int d[MAXN], z[MAXN];
int x[MAXN][MAXN], y[MAXN][MAXN], sta[MAXM];

bool SPFA(int v) {
    int l, r, now, i;
    bool cz[MAXN];
    for (i = 1; i <= n; ++i) {
        cz[i] = false;
        d[i] = INF;
        z[i] = 0;
    }
    cz[v] = true;
    l = r = 1;
    sta[l] = v;
    d[v] = 0;
    while (l <= r) {
        now = sta[l];
        for (i = 1; i <= x[now][0]; ++i) {
            if (d[x[now][i]] > d[now] + y[now][i]) {
                d[x[now][i]] = d[now] + y[now][i];
                if (!cz[x[now][i]]) {
                    ++r;
                    sta[r] = x[now][i];
                    cz[x[now][i]] = true;
                    ++z[x[now][i]];
                    if (z[x[now][i]] > n) return true;
                }
            }
        }
        cz[now] = false;
        ++l;
    }    
    return false;
}

int main() {
    int a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) x[i][0] = 0;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            ++a;  ++b;
            ++x[a][0];
            x[a][x[a][0]] = b;
            y[a][x[a][0]] = c;
        }
        if (SPFA(1)) printf("possible\n"); else printf("not possible\n");
    }
    return 0;
}
