#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAXN = 111;

int num;
char p[MAXN], q[MAXN];
int f[MAXN][MAXN];

int main() {
    gets(p); 
    int n = strlen(p);
    while (p[0] != '#') {
        gets(q); 
        int m = strlen(q);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                if (p[i - 1] == q[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
                ans = max(ans, f[i][j]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", ++num, ans);
        gets(p); 
        n = strlen(p);
    }
    return 0;
}
