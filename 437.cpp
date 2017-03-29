#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, x[40], y[40], z[40], f[40][3], ans, tt, num;
bool cz[40][3];

int DP(int a, int b) {
    if (cz[a][b]) return f[a][b];
    f[a][b] = 0;
    cz[a][b] = true;
    int p, q;
    switch (b) {
        case 0 : p = y[a]; q = z[a]; break;
        case 1 : p = x[a]; q = z[a]; break;
        case 2 : p = x[a]; q = y[a]; break;
    }
    for (int i = 0; i < n; ++i) {
        if ((x[i] < p && y[i] < q) || (y[i] < p && x[i] < q)) f[a][b] = max(f[a][b], DP(i, 2));
        if ((y[i] < p && z[i] < q) || (z[i] < p && y[i] < q)) f[a][b] = max(f[a][b], DP(i, 0));
        if ((z[i] < p && x[i] < q) || (x[i] < p && z[i] < q)) f[a][b] = max(f[a][b], DP(i, 1));
    }
    switch (b) {
        case 0 : f[a][b] += x[a]; break; 
        case 1 : f[a][b] += y[a]; break; 
        case 2 : f[a][b] += z[a]; break; 
    }
    return f[a][b];
    
}

int main() {
    scanf("%d", &n);
    tt = 0;
    num = 0;
    while (n > 0) {
        ++num;
        ++tt;
        for (int i = 0; i < n; ++i) scanf("%d%d%d", &x[i], &y[i], &z[i]);
        memset(f, 0, sizeof(f));
        memset(cz, 0, sizeof(cz));
        ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, DP(i, 0));
            ans = max(ans, DP(i, 1));
            ans = max(ans, DP(i, 2));
        }
        printf("Case %d: maximum height = %d\n", num, ans);
        scanf("%d", &n);
    }
    
    return 0;
}
