#include <cstdio>
#include <cstring>

int main() {
    int n;
    scanf("%d", &n);
    for (int k = 1; k <= n; ++k) {
        int DNA[10];
        for (int i = 0; i <= 9; ++i) scanf("%d", &DNA[i]);
        int now[50] = {0}, old[50];
        now[20] = 1;
        for (int i = 1; i <= 50; ++i) {
            for (int j = 1; j <= 40; ++j) {
                switch (now[j]) {
                    case 0 : printf(" "); break;
                    case 1 : printf("."); break;
                    case 2 : printf("x"); break;
                    default: printf("W"); break;
                }
            }
            printf("\n");
            memcpy(old, now, sizeof(old));
            for (int j = 1; j <= 40; ++j) 
                now[j] = DNA[old[j - 1] + old[j] + old[j + 1]];
        }
        if (k != n) printf("\n");
    }
    return 0;
}
