#include <cstdio>

int main() {
    int n, a, b, c, d, e;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &e);
        a = 0; c = 0;
        for (int j = 2; j < e; ++j) {
            if (e % j != 0) continue;
            if (!a) {
                a = j;
                b = e / j;
            } else 
            if (!c) {
                c = j;
                d = e / j;
                break;
            }
        }
        printf("Case #%d: %d = %d * %d = %d * %d\n", i + 1, e, a, b, c, d);
    }
    return 0;
}
