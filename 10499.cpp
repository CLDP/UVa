#include <cstdio>
#include <cmath>

const double zero = 1e-9;

int main() {
    int n;
    double k;
    
    while (scanf("%d",&n) == 1) {
        if (n < 0) return 0;
        if (n == 1 || n == 0) {
            printf("0%%\n");
            continue;
        }
        k = n * 25.0 + zero;
        printf("%.lf%%\n", k);
    }
    return 0;
}
