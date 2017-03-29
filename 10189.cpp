#include <cstdio>
#include <cstring>

const int mx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int my[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool x[111][111];
int f[111][111];

bool get() {
    char p;
    scanf("%c", &p);
    while (p != '.' && p != '*') scanf("%c", &p);
    if (p == '*') return true;
    return false;
}

int main() {
    int n, m, num = 0;
    scanf("%d%d", &n, &m);
    while (n || m) {
        memset(x, 0, sizeof(x));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) x[i][j] = get();
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = 0;
                for (int k = 0; k < 8; ++k) {
                    if (x[i + mx[k]][j + my[k]]) ++f[i][j];
                }
            }
        }
        printf("Field #%d:\n", ++num);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (x[i][j]) printf("*"); else printf("%d", f[i][j]);
            }
            printf("\n");
        }
        scanf("%d%d", &n, &m);
        if (n || m) printf("\n");
    }
    return 0;
}
