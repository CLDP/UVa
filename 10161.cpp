#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    int n, a;
    scanf("%d", &n);
    while (n > 0) {
        a = sqrt(n + 0.1);
        n -= a * a;
        ++a;
        if (a % 2 == 1) {
            if (n == 0) printf("%d %d\n", a - 1, 1); else
            if (n <= a) printf("%d %d\n", a, n); else printf("%d %d\n", 2 * a - n, a);
        } else {
            if (n == 0) printf("%d %d\n", 1, a - 1); else
            if (n <= a) printf("%d %d\n", n, a); else printf("%d %d\n", a, 2 * a - n);
        }
        scanf("%d", &n);
    }
    return 0;
}
