#include <cstdio>

const int M10[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};


int main() {
    int s, n, m, t;
    char ans[25][110];
    char p[10][25][15];
    while (true) {
        scanf("%d%d", &s, &n);
        if (!s && !n) break;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 2 * s + 3; ++j) {
                for (int k = 0; k < s + 2; ++k) p[i][j][k] = ' ';
            }
        }
        for (int i = 1; i <= s; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (j == 1 || j == 4) continue;
                p[j][0][i] = '-';
            }
            
            for (int j = 2; j < 10; ++j) {
                if (j == 7) continue;
                p[j][s + 1][i] = '-';
            }
            
            for (int j = 0; j < 10; ++j) {
                if (j == 1 || j == 4 || j ==7) continue;
                p[j][s + s + 2][i] = '-';
            }
            
            p[0][i][0] = '|';
            p[4][i][0] = '|';
            p[5][i][0] = '|';
            p[6][i][0] = '|';
            p[8][i][0] = '|';
            p[9][i][0] = '|';
            
            for (int j = 0; j < 10; ++j) {
                if (j == 5 || j == 6) continue;
                p[j][i][s + 1] = '|';
            }
            
            p[0][s + 1 + i][0] = '|';
            p[2][s + 1 + i][0] = '|';
            p[6][s + 1 + i][0] = '|';
            p[8][s + 1 + i][0] = '|';
            
            for (int j = 0; j < 10; ++j) {
                if (j == 2) continue;
                p[j][s + 1 + i][s + 1] = '|';
            }
        }
        m = 0;
        while (M10[m + 1] <= n) ++m;
        for (int j = 0; j < 2 * s + 3; ++j) {
            for (int k = 0; k < (s + 2) * (m + 1) + m; ++k) ans[j][k] = ' ';
        }

        for (int i = m; i >= 0; --i) {
            t = (n / M10[i]) % 10;
            for (int j = 0; j < 2 * s + 3; ++j) {
                for (int k = 0; k < s + 2; ++k) ans[j][(s + 3) * (m - i) + k] = p[t][j][k];
            }
        }
        
        for (int j = 0; j < 2 * s + 3; ++j) {
            for (int k = 0; k < (s + 2) * (m + 1) + m; ++k) printf("%c", ans[j][k]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
