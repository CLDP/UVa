#include <cstdio>

int main() {
    int n, x[100], ans, avg, num = 0;
    scanf("%d", &n);
    while (n) {
        avg = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
            avg += x[i];
        }
        avg /= n;
        ans = 0;
        for (int i = 0; i < n; ++i) 
         if (avg > x[i]) ans += avg - x[i]; else ans += x[i] - avg;
        ans /= 2;
        ++num;
        printf("Set #%d\n", num);
        printf("The minimum number of moves is %d.\n\n", ans);
        scanf("%d", &n);
    }
    return 0;
}
