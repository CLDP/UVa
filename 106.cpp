#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXM = 1000010;
int n, f[MAXM];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int solve() {
    int limit, num[2] = {0}, a, b, c;
    for(int i = 0; i <= n; ++i) f[i] = 1;
    limit = (int)sqrt(n + 1);
    for(int i = 1; i <= limit; i ++) {
        for(int j = i + 1; j <= limit; j ++) {
            c = i * i + j * j;
            if (c > n) break;
            a = j * j - i * i;
            b = 2 * i * j;
            if(gcd(gcd(a, b), c) == 1) {
                f[a] = f[b] = f[c] = 0;
                ++num[0];
                for(int k = 2; k * c <= n; k ++) f[a * k] = f[b * k] = f[c * k] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if (f[i]) ++num[1];
    }
    printf("%d %d\n", num[0], num[1]);
    return 0;
}


int main() {
    while(scanf("%d", &n) == 1) solve();
    return 0;
}
