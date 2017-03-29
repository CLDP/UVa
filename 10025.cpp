#include <cstdio>
#include <cmath>

int main() {
    int n, k, t, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        if (k < 0) k = -k;
        t = sqrt(2 * k);
        if (k == 0) t = 1;
        ans = t * (t + 1) / 2;
        while (ans < k) ans += ++t;
        while ((ans - k) % 2) ans += ++t;
        printf("%d\n", t);
        if (i < n - 1) printf("\n");
    }
    return 0;
}
