#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
int x[MAXN];
long long y[MAXN];


int main() {
    int n;
    long long a, b, c, MAXK = 10;
    for (int i = 0; i < 16; ++i) MAXK *= 10;
    scanf("%d", &n);
    while (n) {
        for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
        sort(x, x + n);
        int i = 0, j = 0, r = 0, ans = 0;
        while (i < n || j < r-1) {
            a = MAXK; b = a; c = b;
            if (i < n - 1) a = x[i] + x[i + 1];
            if (j < r - 1) b = y[j] + y[j + 1];
            if (i < n && j < r) c = x[i] + y[j];
            if (a <= b && a <= c) {
                y[r++] = a;
                ans += a;
                i += 2;
                continue;
            }
            if (b <= a && b <= c) {
                y[r++] = b;
                ans += b;
                j += 2;
                continue;
            }
            if (c <= a && c <= b) {
                y[r++] = c;
                ans += c;
                ++i; 
                ++j;
                continue;
            }
        }
        printf("%lld\n", ans);
        scanf("%d", &n);
    }
    return 0;
}
