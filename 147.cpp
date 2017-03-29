#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 30010;
const int MAXM = 11;
int W[MAXM] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long f[MAXN];


int main() {
    double a;
    int n;
    f[0] = 1;
    for (int i = 0; i < MAXM; ++i) {
        for (int j = 5; j < MAXN; j += 5) {
            if (j >= W[i]) f[j] += f[j - W[i]];
        }
    }
    scanf("%lf", &a);
    n = a * 100 + 0.01;
    while (n) {
        printf("%6.2lf%17lld\n", a, f[n]);
        scanf("%lf", &a);
        n = a * 100 + 0.01;
    }
    return 0;
}
