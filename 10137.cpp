#include <cstdio>
#include <cstring>

const int MAXN = 1010;
double x[MAXN];

int main() {
    char p[MAXN];
    while (true) {
        int n;
        scanf("%d", &n);
        if (!n) break;
        double avg = 0, ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &x[i]);
            avg += x[i];
        }
        avg /= n;
        sprintf(p, "%.2lf", avg);
        sscanf(p, "%lf", &avg);
        for (int i = 0; i < n; ++i) {
            if (x[i] < avg) ans1 += avg - x[i]; else ans2 += x[i] - avg;
        }
        if (ans1 < ans2) 
            printf("$%.2lf\n", ans1);
        else
            printf("$%.2lf\n", ans2);
    }
    return 0;
}
