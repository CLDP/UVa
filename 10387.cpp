#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);

int main() {
    double a, b, s, m, n, v, A;
    scanf("%lf%lf%lf%lf%lf", &a, &b, &s, &m, &n);
    while (!(a == 0 && b == 0 && s == 0 && m == 0 && n == 0)) {
        v = sqrt(pow(m * a / s, 2) + pow(n * b / s, 2));
        A = 180 * atan(n * b / (m * a)) / PI;
        printf("%.2lf %.2lf\n", A, v);
        scanf("%lf%lf%lf%lf%lf", &a, &b, &s, &m, &n);
    }
    return 0;
}
