#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    int a, b;
    double ans;
    char p[10], q;
    scanf("%s", p);
    if (p[1] == ':') {
        a = p[0] - '0';
        b = (p[2] - '0') * 10 + (p[3] - '0');
    } else {
        a = (p[0] - '0') * 10 + (p[1] - '0');
        b = (p[3] - '0') * 10 + (p[4] - '0');
    }
    while (a != 0 || b != 0) {
        ans = (6.0 * b) - (30.0 * a + 0.5 * b);
        if (ans < 0) ans = -ans;
        if (ans > 180) ans = 360.0 - ans;
        printf("%.3lf\n", ans);
        scanf("%s", p);  
        if (p[1] == ':') {
            a = p[0] - '0';
            b = (p[2] - '0') * 10 + (p[3] - '0');
        } else {
            a = (p[0] - '0') * 10 + (p[1] - '0');
            b = (p[3] - '0') * 10 + (p[4] - '0');
        }
    }
    return 0;
}
