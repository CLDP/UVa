#include <cstdio>
#include <cctype>
#include <cstring>

int main() {
    int t, flag, a, b;
    int A[26], B[26];
    char p[1000];
    scanf("%d\n", &t);
    while (t != -1) {
        printf("Round %d\n", t);
        
        scanf("%s", p);
        memset(A, 0, sizeof(A));
        a = 0;
        for (int i = 0; i < strlen(p); ++i) A[p[i] - 'a'] = 1;
        for (int i = 0; i < 26; ++i) {
            if (A[i]) ++a;
        }
        
        scanf("%s", p);
        memset(B, 0, sizeof(B));
        b = 0; 
        flag = 0;
        for (int i = 0; i < strlen(p); ++i) {
            if (A[p[i] - 'a'] == 1) {
                A[p[i] - 'a'] = 2;
                B[p[i] - 'a'] = 1;
                --a;
            } else 
            if (!B[p[i] - 'a']) {
                B[p[i] - 'a'] = 1;
                ++b;
            }
            if (b > 6) {
                printf("You lose.\n"); 
                flag = 1;
                break;
            }
            if (!a) {
                printf("You win.\n"); 
                flag = 1;
                break;
            }
        }
        if (!flag) printf("You chickened out.\n");
        scanf("%d\n", &t);
    }
    return 0;
}
