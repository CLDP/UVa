#include <cstdio>
#include <cctype>
#include <cstring>

void swap(char &a, char &b) {
    int t = a;
    a = b;
    b = t;
} 


int main() {
    char p[100];
    int len, n, a, b;
    scanf("%d", &n);
    
    for (int k = 0; k < n; ++k) {
        scanf("%s", p);
        len = strlen(p);
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j < len - i; ++j) {
                if (p[j - 1] > p[j]) swap(p[j - 1],p[j]);
            }
        }
        a = len - 1;
        printf("%s\n", p);
        while (a > 0 && p[a - 1] >= p[a]) --a;
        while (a > 0) {
            --a;
            b = len - 1;
            while (p[b] <= p[a]) --b;
            swap(p[a], p[b]);
            ++a;
            for (int i = a; i < len; ++i) {
                for (int j = a+1; j < len; ++j) {
                    if (p[j - 1] > p[j]) swap(p[j - 1],p[j]);
                }
            }
              
            printf("%s\n", p);
            a = len - 1;
            while (a > 0 && p[a - 1] >= p[a]) --a;
        }
        printf("\n");
    }
    return 0;
}
