#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int MAXM = 10010;

struct node {
    int x, y;
    double z;
    bool operator < (const node &B) const {
        return z < B.z;
    }
};

int d[MAXN];
double xx[MAXN], yy[MAXN];
node X[MAXM];


int find(int &a) {
    if (a != d[a]) d[a] = find(d[a]);
    a = d[a];
    return d[a];
}

double Kruskal(const int n, const int m) {
    int a, b, j;
    double ans = 0;
    for (int i = 0; i < n; ++i) d[i] = i;
    j = 0;
    for (int i = 1; i < n; ++i) {
        while (find(X[j].x) == find(X[j].y)) ++j;
        ans += X[j].z;
        d[X[j].x] = min(d[X[j].x], find(X[j].y));
        d[X[j].y] = min(d[X[j].y], find(X[j].x));
    }
    return ans;
}

int main() {
    int tt, n, m;
    scanf("%d", &tt);
    while (tt--) {
        m = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%lf%lf", &xx[i], &yy[i]);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                X[m].x = i;
                X[m].y = j;
                X[m].z = sqrt((xx[i] - xx[j]) * (xx[i] - xx[j]) + (yy[i] - yy[j]) * (yy[i] - yy[j]));
                ++m;
            }
        }
        sort(X, X + m);
        printf("%.2lf\n", Kruskal(n, m));
        if (tt) printf("\n");
    }
    return 0;
}
