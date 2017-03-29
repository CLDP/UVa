#include <cstdio>
#include <cstring>

const int MAXN = 5;

int n, ans;
bool x[MAXN][MAXN], z[MAXN][MAXN];

int find(int a, int b, int now) {
    if (a == n) {
        if (now > ans) ans = now;
    } else
    if (x[a][b]) {
        bool y[MAXN][MAXN];
        memset(y, 0, sizeof(y));
        x[a][b] = false;
        y[a][b] = true;
        
        for (int i = a - 1, j = b; i >= 0; --i) {
            if (z[i][j]) {
                if (x[i][j]) {
                    x[i][j] = false;
                    y[i][j] = true;
                }
            } else break;
        }
         
        for (int i = a + 1, j = b; i < n; ++i) {
            if (z[i][j]) {
                if (x[i][j]) {
                    x[i][j] = false;
                    y[i][j] = true;
                }
            } else break;
        }
         
        for (int i = a, j = b - 1; j >= 0; --j) {
            if (z[i][j]) {
                if (x[i][j]) {
                    x[i][j] = false;
                    y[i][j] = true;
                }
            } else break;
        }
         
        for (int i = a, j = b + 1; j < n; ++j) {
            if (z[i][j]) {
                if (x[i][j]) {
                    x[i][j] = false;
                    y[i][j] = true;
                }
            } else break;
        }
        
        if (b + 1 == n) find(a + 1, 0, now + 1); else find(a, b + 1, now + 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (y[i][j]) x[i][j] = true;
            }
        }
        
        if (b + 1 == n) find(a + 1, 0, now); else find(a, b + 1, now);
    } else {
        if (b + 1 == n) find(a + 1, 0, now); else find(a, b + 1, now);
    }
    return 0;
}
 
int main() {
    char p;
    scanf("%d", &n);
    while (n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%c", &p);
                while (p != '.' && p != 'X') scanf("%c", &p);
                if (p == '.') z[i][j] = true; else z[i][j] = false;
                x[i][j] = z[i][j];
            }
        }
        
        ans = 0;
        find(0, 0, 0);
        printf("%d\n", ans);
        scanf("%d", &n);
    }
    
    return 0;
}
