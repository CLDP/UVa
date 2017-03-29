#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 12;
const int INF = 2100000000;
int x[MAXN], y[MAXN], f[MAXN][MAXN];
bool ff[MAXN][MAXN];


int DP(const int a, const int b) {
    if (ff[a][b]) return f[a][b];
    if (a == b) return 0;
    if (a + 1 == b) {
        ff[a][b] = true;
        f[a][b] = x[a] * y[a] * y[b];
        return f[a][b];
    }
    ff[a][b] = true;
    f[a][b] = INF;
    for (int i = a; i < b; ++i) 
        f[a][b] = min(f[a][b], DP(a, i) + DP(i + 1, b) + x[a] * y[i] * y[b]);
    return f[a][b];
}

string get(const int a, const int b) {
    char p[100];
    string ans;
    if (a == b) {
        sprintf(p, "A%d", a + 1);
        ans = p;
        return ans;
    }
    if (a + 1 == b) {
        sprintf(p, "(A%d x A%d)", a + 1, b + 1);
        ans = p;
        return ans;
    }
    for (int i = a; i < b; ++i) {
        if (f[a][b] == f[a][i] + f[i + 1][b] + x[a] * y[i] * y[b]) {
            ans = "(" + get(a, i) + " x " + get(i + 1, b) + ")";
            return ans;
        }
    }
    return ans;
}

int main() {
    int n, num = 0;
    scanf("%d", &n);
    while (n) {
        memset(ff, 0, sizeof(ff));
        for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
        DP(0, n - 1);
        cout << "Case " << ++num << ": " << get(0, n - 1) << endl;
        scanf("%d", &n);
    }
    return 0;
}
