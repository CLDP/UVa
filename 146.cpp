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
    int len, a, b;
    scanf("%s", p);
    while (p[0] != '#') { 
        len = strlen(p);
        a = len - 1;
        while (a > 0 && p[a - 1] >= p[a]) --a;
        if (a == 0) {
            printf("No Successor\n");
        } else {
            --a;
            b = len - 1;
            while (p[b] <= p[a]) --b;
            swap(p[a], p[b]);
            ++a;
            for (int i = a; i < len; ++i) {
                for (int j = a + 1; j < len; ++j) {
                    if (p[j - 1] > p[j]) swap(p[j - 1],p[j]);
                }
            }
            printf("%s\n", p);
        }
        scanf("%s", p);
    }
            
    return 0;
}
