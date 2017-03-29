#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 1010;
int d[MAXN];
double x[MAXN], y[MAXN], w[MAXN];

int cmp(const void *_p, const void *_q) {
    int *p = (int *)_p;
    int *q = (int *)_q;
    if (fabs(w[*p] - w[*q]) < 1e-6) {
        return *p - *q; 
    } else {
        if (w[*p] < w[*q]) 
            return 1;
        else 
            return -1;
    }
}

int main() {
    int n, k;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &x[i], &y[i]);
            w[i] = y[i] / x[i];
            d[i] = i;
        }
        qsort(d, n, sizeof(d[0]), cmp);
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", d[i] + 1);
        }
        printf("\n");
        if (k) printf("\n");
    }
    return 0;
}
