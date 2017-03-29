#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);

int main() {
    int n;
    scanf("%d", &n);
    double B, H, R, h, r;
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &B, &H);
        r = sqrt(B * B / 4 + H * H);
        R = B * H / (B + 2 * r);
        h = H;
        r = R;
        while (r >= 0.000001) {
            h -= 2 * r;
            r = h * R / H;
        }
        printf("%13lf\n", PI * (H - h));
        if (i < n - 1) printf("\n");
    }
    return 0;
}
