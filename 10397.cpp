#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 800;
const int MAXM = 600000;

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

double Kruskal(const int n, const int m, const int t) {
    int a, b, j;
    double ans = 0;
    j = 0;
    for (int i = t + 1; i < n; ++i) {
        while (find(X[j].x) == find(X[j].y)) ++j;
        ans += X[j].z;
        d[X[j].x] = min(d[X[j].x], find(X[j].y));
        d[X[j].y] = min(d[X[j].y], find(X[j].x));
    }
    return ans;
}

int main() {
    int n, t, a, b, c;
    while (scanf("%d", &n) != EOF) {
        int m = 0;
        for (int i = 0; i < n; ++i) scanf("%lf%lf", &xx[i], &yy[i]);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j < n; ++j) {
                X[m].x = i;
                X[m].y = j;
                X[m].z = sqrt((xx[i] - xx[j]) * (xx[i] - xx[j]) + (yy[i] - yy[j]) * (yy[i] - yy[j]));
                ++m;
            }
        }
        sort(X, X + m);
        scanf("%d", &t);
        c = t;
        for (int i = 0; i < n; ++i) d[i] = i;
        for (int i = 0; i < t; ++i) {
            scanf("%d%d", &a, &b);
            --a; --b;
            if (find(a) == find(b)) --c;
            d[a] = min(d[a], find(b));
            d[b] = min(d[b], find(a));
        }
        printf("%.2lf\n", Kruskal(n, m, c));
    }
    return 0;
}
