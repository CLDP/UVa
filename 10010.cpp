#include <cstring>
#include <cstdio>
#include <cctype>

char p[1000][1000];
char q[1000];
int n, m;

bool check(int a, int b) {
    int len = strlen(q);
    if (a + len - 1 < n) {
        bool flag = true;        
        for (int i = 0; i < len; ++i) flag &= (q[i] == p[a + i][b]);
        if (flag) return true;
    }
    if (a - len + 1 >= 0) {
        bool flag = true;
        for (int i = 0; i < len; ++i) flag &= (q[i] == p[a - i][b]);
        if (flag) return true;
    }
    if (b + len - 1 < m) {
        bool flag = true;        
        for (int i = 0; i < len; ++i) flag &= (q[i] == p[a][b + i]);
        if (flag) return true;
    }
    if (b - len + 1 >= 0) {
        bool flag = true;
        for (int i = 0; i < len; ++i) flag &= (q[i] == p[a][b - i]);
        if (flag) return true;
    }
    if (a + len - 1 < n && b + len - 1 < m) {
        bool flag = true;        
        for (int i = 0; i < len; ++i) flag &= (q[i] == p[a + i][b + i]);
        if (flag) return true;
    }
    if (a + len - 1 < n && b - len + 1 >= 0) {
        bool flag = true;        
        for (int i = 0; i < len; ++i) flag &= (q[i] == p[a + i][b - i]);
        if (flag) return true;
    }
    if (a - len + 1 >= 0 && b + len - 1 < m) {
        bool flag = true;
        for (int i = 0; i < len; ++i) flag &= (q[i] == p[a - i][b + i]);
        if (flag) return true;
    }
    if (a - len + 1 >= 0 && b - len + 1 >= 0) {
        bool flag = true;
        for (int i = 0; i < len; ++i) flag &= (q[i] == p[a - i][b - i]);
        if (flag) return true;
    }
    return false;
}

int main() {
    int t, k;
    bool flag;
    scanf("%d", &t);
    for (int tt = 0; tt < t; ++tt) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%s", p[i]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) p[i][j] = toupper(p[i][j]);
        }
        scanf("%d", &k);
        for (int kk = 0; kk < k; ++kk) {
            scanf("%s", q);
            for (int i = 0; i < strlen(q); ++i) q[i] = toupper(q[i]);
            flag = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (flag) break;
                    if (check(i,j)) {
                        flag = true;
                        printf("%d %d\n", i+1, j+1);
                    }
                }
            }
        }
        if (tt < t - 1) printf("\n");
    }
    return 0;
}
