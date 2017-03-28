#include <cstdio>
#include <cstring>

const int MAXN = 2000;
char p[MAXN], q[MAXN];
char x[5][MAXN];


int main() {
    int n, a, b;
    scanf("%d\n", &n);
    while (n--) {
        gets(p);
        gets(q);
        for (int i = 0; i < strlen(p); ++i) {
            a = 0;
            for (int j = 0; j < 5; ++j) {
                b = 0;
                while (p[a] != '<' && p[a] != '>' && a < strlen(p)) x[j][b++] = p[a++];
                x[j][b] = '\0';
                ++a;
            }
        }
        for (int i = 0; i < 5; ++i) printf("%s", x[i]);
        printf("\n");
        for (int i = 0; i < strlen(q); ++i) {
            if (q[i] == '.' && q[i + 1] == '.' && q[i + 2] == '.') {
                printf("%s%s%s%s", x[3], x[2], x[1], x[4]);
                i += 2;
            } else {
                printf("%c", q[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
