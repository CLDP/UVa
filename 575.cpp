#include <cstring>
#include <cstdio>

int main() {
    int len, ans;
    char p[40];
    gets(p);
    while (p[0] != '0') {
        ans = 0;
        len = strlen(p);
        for (int i = 0; i < len; ++i) ans += (p[i] - '0') * ((1 << (len - i)) - 1);
        printf("%d\n", ans);
        gets(p);
    }
    return 0;
}
