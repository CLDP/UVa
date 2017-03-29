#include <cstdio>

const int MAXN = 30;
int n;
int d[MAXN], x[MAXN][MAXN], y[MAXN];

int get(const int c, int &a, int &b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d[i]; ++j) {
            if (x[i][j] == c) {
                a = i;
                b = j;
            }
        }
    }
    return 0;
}

int main() {
    int a, b, ax, ay, bx, by, num = 0;
    char p[5], q[5];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        x[i][0] = i;
    }
    scanf("%s", p);
    while (p[0] != 'q') {
        scanf("%d%s%d", &a, q, &b);
        get(a, ax, ay);
        get(b, bx, by);
        if (ax != bx) {
            if (p[0] == 'm' && q[1] == 'n') {
                // move onto
                for (int i = ay + 1; i < d[ax]; ++i) 
                    x[x[ax][i]][++d[x[ax][i]]] = x[ax][i];
                for (int i = by + 1; i < d[bx]; ++i) 
                    x[x[bx][i]][++d[x[bx][i]]] = x[bx][i];
                d[ax] = ay;
                d[bx] = by + 2;
                x[bx][by + 1] = a;
            }
            if (p[0] == 'm' && q[1] == 'v') {
                //move over
                for (int i = ay + 1; i < d[ax]; ++i) 
                    x[x[ax][i]][++d[x[ax][i]]] = x[ax][i];
                d[ax] = ay;
                x[bx][d[bx]] = a;
                ++d[bx];
            }
            if (p[0] == 'p' && q[1] == 'n') {
                //pile onto
                for (int i = d[bx] - 1; i > by; --i) 
                    x[x[bx][i]][++d[x[bx][i]]] = x[bx][i];
                for (int i = by + 1; i < by + d[ax] - ay + 1; ++i) 
                    x[bx][i] = x[ax][i - by - 1 + ay];
                d[bx] = by + 1 + d[ax] - ay;
                d[ax] = ay;
            }
            if (p[0] == 'p' && q[1] == 'v') {
                //pile over
                for (int i = ay; i < d[ax]; ++i) 
                    x[bx][d[bx] + i - ay] = x[ax][i];
                d[bx] += d[ax] - ay;
                d[ax] = ay;
            }
        }
        scanf("%s", p);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d:", i);
        for (int j = 0; j < d[i]; ++j) printf(" %d", x[i][j]);
        printf("\n");
    }
    return 0;
}
