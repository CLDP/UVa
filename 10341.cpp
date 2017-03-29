#include <cstdio>
#include <cmath>

const double zero1 = 1e-10;
const double zero2 = 1e-6;

double p, q, r, s, t, u;

double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
    double max, min, mid;
    while(scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF) {
        max = 1; min = 0;
        while (max - min > zero1) {
            mid = (min + max) / 2;
            if (f(mid) > 0) min = mid; else max = mid;
        }
        if (f(min) > zero2 || f(min) < -zero2) 
            printf("No solution\n");
        else
            printf("%.4lf\n", min);
    }
    return 0;
}
