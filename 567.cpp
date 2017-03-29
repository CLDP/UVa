#include <cstdio>
#include <cstring>

const int MAXN = 22;
const int INF = 100;
int x[MAXN][MAXN];

int main() {
    int a, b, c, num = 0;
    while (scanf("%d", &a) != EOF) {
        for (int i = 1; i <= 20; ++i) {
            for (int j = 1; j <= 20; ++j) {
                if (i == j) x[i][j] = 0; else x[i][j] = INF;
            }
        }
            
        for (int i = 1; i < 20; ++i) {
            for (int j = 0; j < a; ++j) {
                scanf("%d", &c);
                x[i][c] = x[c][i] = 1;
            }
            scanf("%d", &a);
        }
          
        for (int k = 1; k <= 20; ++k) {
            for (int i = 1; i <= 20; ++i) {
                for (int j = 1; j <= 20; ++j) {
                    if (x[i][k] + x[k][j] < x[i][j]) x[i][j] = x[i][k] + x[k][j];
                }
            }
        }
          
        printf("Test Set #%d\n", ++num);
        for (int i = 1; i <= a; ++i) {
            scanf("%d%d", &b, &c);
            printf("%2.d to %2.d: %d\n", b, c, x[b][c]);
        }
        printf("\n");
    }
    return 0;
}
