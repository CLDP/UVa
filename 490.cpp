#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

const int MAXM = 105;
char p[MAXM][MAXM];

int main() {
    int n = 0, max = 0;
    while (gets(p[n])) {
        if (strlen(p[n]) > max) max = strlen(p[n]);
        ++n;
    }
    
    for (int i = 0; i < max; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i < strlen(p[j])) printf("%c", p[j][i]); else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
