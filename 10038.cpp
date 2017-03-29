#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 3010;
int x[MAXN];


int main() {
    bool ans;
    int n, a, b;
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &a);
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d", &b);
            if (b > a) x[i] = b - a; else x[i] = a - b;
            a = b;
        }
        sort(x, x + n - 1);
        ans = true;
        for (int i = 0; i < n - 1; ++i) ans &= (x[i] == i + 1);
        if (ans) printf("Jolly\n"); else printf("Not jolly\n");
    }
    return 0;
}
