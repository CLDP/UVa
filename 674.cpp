#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXM = 5;
const int MAXN = 400000;
const int d[MAXM] = {1, 5, 10, 25, 50};

int n;
int f[MAXN];

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(f, 0, sizeof(f[0]) * (n + 1));
        f[0] = 1;
        for (int j = 0; j < MAXM; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (i >= d[j]) f[i] += f[i - d[j]];
            }
        }
        
        printf("%d\n", f[n]);
    }
    return 0;
}
