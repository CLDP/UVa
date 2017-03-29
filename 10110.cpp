#include <cstdio>
#include <cmath>

int main() {
    long n, m;
    scanf("%ld", &n);
    while (n > 0) {
        m = sqrt(n + 0.1);
        if (m * m == n) printf("yes\n"); else printf("no\n");
        scanf("%ld", &n);
    }
    return 0;
}
