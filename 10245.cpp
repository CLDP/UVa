#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const double zero = 1e-8;
const double INF = 1e8;

struct node {
    double x, y;
    bool operator < (const node &B) const {
        if (x != B.x) return x < B.x;
        return y < B.y;
    }
};

node X[MAXN], Y[MAXN];

double x[MAXN], y[MAXN], xx[MAXN], yy[MAXN];
int d[MAXN];

int Cmp(const double a, const double b) {
    if (fabs(a - b) < zero) return 0;
    if (a < b) return -1;
    return 1;
}

double dist(const int a, const int b) {
    return sqrt((X[a].x - X[b].x) * (X[a].x - X[b].x) 
              + (X[a].y - X[b].y) * (X[a].y - X[b].y));
}

double disty(const int a, const int b) {
    return sqrt((Y[a].x - Y[b].x) * (Y[a].x - Y[b].x) 
              + (Y[a].y - Y[b].y) * (Y[a].y - Y[b].y));
}


double find(const int l, const int r) {
    int mid = (l + r) >> 1;
    if (l + 1 == mid) return dist(l, mid);
    if (l == mid) return INF;
    double a = find(l, mid);
    
    if (mid + 1 == r) return dist(mid, r);
    if (mid == r) return INF;
    double b = find(mid, r);
    
    if (a > b) a = b;
    int M = 0;
    for (int i = l; i <= r; ++i) {
        if (fabs(X[i].x - X[mid].x) < a) {
            Y[M].x = X[i].x;
            Y[M].y = X[i].y;
            ++M;
        }
    }
    sort(Y, Y + M);
    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M && j < i + 7; ++j) {
            b = disty(i, j);
            if (b < a) a = b;
        }
    }
    return a;
}

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        for (int i = 0; i < N; ++i) cin >> X[i].x >> X[i].y;
        sort(X, X + N);
        double ans = find(0, N - 1);
        if (Cmp(ans, 1e4) == -1) printf("%.4lf\n", ans); else printf("INFINITY\n");
    }
    return 0;
}
