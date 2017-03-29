#include <cstdio>
#include <cstring>
#include <cctype>

char s[100] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    int len = strlen(s);
    char p[1000];
    while (gets(p)) {
        for (int i = 0; i < strlen(p); ++i) {
            if (p[i] == ' ') {
                printf(" ");
                continue;
            }
            for (int j = 1; j < len; ++j) {
                if (s[j] == p[i]) {
                    printf("%c", s[j - 1]);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
