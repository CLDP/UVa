#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 300;

char x[MAXN][MAXN];

int n, m;

int fill(int a, int b, char p, char q) {
    x[a][b] = q;
    if (a < n && x[a + 1][b] == p) fill(a + 1, b, p, q);
    if (a > 1 && x[a - 1][b] == p) fill(a - 1, b, p, q);
    if (b < m && x[a][b + 1] == p) fill(a, b + 1, p, q);
    if (b > 1 && x[a][b - 1] == p) fill(a, b - 1, p, q);
    return 0;
}

int main() {
    char p, q, r;
    char s[MAXN];
    int a, b, c, d;
    while (true) {
        scanf("%c", &p);
        if (p == 'X') break;
        if (p == 'I') {
            scanf("%d%d", &m, &n);
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) x[i][j] = 'O';
            }
        } else 
        if (p == 'C') {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) x[i][j] = 'O';
            }
        } else 
        if (p == 'L') {
            scanf("%d%d%c%c", &a, &b, &r, &q);
            if (a <= m && b <= n) x[b][a] = q;
        } else
        if (p == 'V') {
            scanf("%d%d%d%c%c", &c, &a, &b, &r, &q);
            if (b < a) swap(a, b);
            for (int i = a; i <= b; ++i) x[i][c] = q;
        } else 
        if (p == 'H') {
            scanf("%d%d%d%c%c", &a, &b, &c, &r, &q);
            if (b < a) swap(a, b);
            for (int i = a; i <= b; ++i) x[c][i] = q;
        } else 
        if (p == 'K') {
            scanf("%d%d%d%d%c%c", &a, &b, &c, &d, &r, &q);
            if (c < a) swap(a,c);
            if (d < b) swap(b,d);
            for (int i = a; i <= c; ++i) {
                for (int j = b; j <= d; ++j) x[j][i] = q;
            }
        } else 
        if (p == 'F') {
            scanf("%d%d%c%c", &a, &b, &r, &q);
            if (x[b][a] != q) fill(b, a, x[b][a], q);
        } else 
        if (p == 'S'){
            scanf("%s", s);
            printf("%s\n", s);
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) printf("%c", x[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
