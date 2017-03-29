#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 100000;

int main() {
    char p[MAXN], q[MAXN];
    while (scanf("%s", p) != EOF) {
        scanf("%s", q);
        int i = 0, j = 0;
        while (i < strlen(p) && j < strlen(q)) {
            if (p[i] == q[j]) ++i;
            ++j;
        }
        if (i == strlen(p)) printf("Yes"); else printf("No");
        printf("\n");
    }
    return 0;
}
