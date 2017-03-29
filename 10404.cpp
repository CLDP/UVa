#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

bool f[1000010][2];
int x[11];

int main() {
    int n, m;
    bool flag;
    while (scanf("%d%d", &n, &m) != -1) {
        for (int i = 0; i < m; ++i) scanf("%d", &x[i]);
        memset(f, 0, sizeof(f));
        f[0][1] = true;
        for (int i = 1; i <= n; ++i) {
            flag = true;
            for (int j = 0; j < m; ++j) {
                if (i - x[j] >= 0) flag &= f[i - x[j]][0];
            }
            if (flag) f[i][1] = true;
            flag = false;
            for (int j = 0; j < m; ++j)
                if (i - x[j] >= 0) flag |= f[i - x[j]][1];
            if (flag) f[i][0] = true;
        }
        if (f[n][0]) printf("Stan wins\n"); else printf("Ollie wins\n");
    }
    return 0;
}
