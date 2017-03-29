#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 1010;
const int INF = 1000000000;

int n, m, k;
int x[MAXN][MAXN], d[MAXN], l[MAXN];
char p[MAXN];
bool z[MAXN];

int get(int &a) {
    int b = 0;
    if (a == strlen(p)) return INF;
    while (!isdigit(p[a])) ++a;
    while (a < strlen(p) && isdigit(p[a])) b = b * 10 + p[a++] - '0';
    return b;
}

int Dijkstra() {
    int w, t;
    memset(z, 0, sizeof(z));
    z[0] = true;
    d[0] = 0;
    for (int i = 1; i < m; ++i) d[i] = x[0][i];
    
    for (int i = 1; i < m; ++i) {
        w = INF;
        t = 0;
        for (int j = 0; j < m; ++j) {
            if (!z[j] && d[j] < w) w = d[t = j];
        }
         
        if (t != 0) z[t] = true; else return 0;
        if (t == m - 1) return 0;
        
        for (int j = 0; j < m; ++j) {
            if (!z[j] && d[t] + x[t][j] < d[j]) d[j] = d[t] + x[t][j];
        }
    }
    return 0;
}

int main() {
    int a, b, c;
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &k);
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                if (i != j) x[i][j] = INF;
            }
        }
        for (int i = 0; i < n; ++i) scanf("%d", &l[i]);
        gets(p);
        for (int i = 0; i < n; ++i) {
            gets(p);
            c = 0;
            a = get(c);
            b = get(c);
            while (b != INF) {
                x[100 * i + a + 1][100 * i + b + 1] = l[i] * (b - a);
                x[100 * i + b + 1][100 * i + a + 1] = l[i] * (b - a);
                a = b;
                b = get(c);
            }
        }
         
        for (int i = 0; i < n; ++i) x[0][i * 100 + 1] = 0;
        for (int tt = 1; tt < 101; ++tt) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) x[i * 100 + tt][j * 100 + tt] = 60;
            }
        }
         
        m = 100 * n + 100 + 1;
        for (int i = 0; i < n; ++i) x[i * 100 + k + 1][m] = 0;
        ++m;
        Dijkstra();
        if (d[m - 1] != INF) 
            printf("%d\n", d[m - 1]);
        else 
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
