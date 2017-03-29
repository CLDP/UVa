#include <cstdio>
#include <cstring>

const int MAXN = 10001;
int x[MAXN], y[MAXN];

int main() {
    int a, b, c, num = 0;
    scanf("%d%d", &a, &b);
    while (a > 0 || b > 0) {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for (int i = 0; i < a; ++i) {
            scanf("%d", &c);
            ++x[c];
        }
        for (int i = 1; i < MAXN; ++i) y[i] = y[i - 1] + x[i];
        
        printf("CASE# %d:\n", ++num);
        for (int i = 0; i < b; ++i) {
            scanf("%d", &c);
            if (!x[c]) 
                printf("%d not found\n", c); 
            else 
                printf("%d found at %d\n", c, y[c - 1]+1);
        }
        scanf("%d%d", &a, &b);
    }
    return 0;
}
