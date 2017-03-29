#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000000;
int n, ans, dd;
int x[MAXN], y[MAXN], z[MAXN], f[MAXN], d[MAXN];


int main() {
    int a, b;
    n = 0;
    while (scanf("%d%d", &a, &b) != EOF) {
        x[n] = a;
        y[n] = b;
        z[n] = n + 1;
        ++n;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 1; j < n - i; ++j) {
            if (x[j - 1] < x[j]) {
                swap(x[j - 1], x[j]);
                swap(y[j - 1], y[j]);
                swap(z[j - 1], z[j]);
            }
        }
    }
    ans = 0; 
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        d[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (x[j] > x[i] && y[j] < y[i]) {
                if (f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    d[i] = j;
                }
                if (f[i] > ans) {
                    ans = f[i];
                    dd = i;
                }
            }
        }
    }
    
    printf("%d\n", ans);
    while (dd != -1) {
        printf("%d\n", z[dd]);
        dd = d[dd];
    }
    return 0;
}
