#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 1000;
char s[MAXN], q[MAXN];

double get(int &a) {
    int b = 0;
    double c;
    a += 2;
    while (isdigit(s[a]) || s[a] == '.') q[b++] = s[a++];
    q[b] = '\0';
    sscanf(q, "%lf", &c);
    switch (s[a++]) {
        case 'k' : c *= 1e3;   break;
        case 'm' : c *= 1e-3;  break;
        case 'M' : c *= 1e6;   break;
    }
    return c;
}

int main() {
    int n;
    bool pp, uu, ii;
    double P, U, I;
    scanf("%d\n", &n);
    for (int k = 0; k < n; ++k) {
        gets(s);
        pp = false; uu = false; ii = false;
        for (int i = 0; i < strlen(s); ++i) {
            if (s[i + 1] == '=') {
                switch (s[i]) {
                    case 'P' : P = get(i); pp = true; break;
                    case 'U' : U = get(i); uu = true; break;
                    case 'I' : I = get(i); ii = true; break;
                }
            }
        }
        printf("Problem #%d\n", k + 1);
        if (pp && uu) {
            printf("I=%.2lfA", P / U);
        } else 
        if (pp && ii) {
            printf("U=%.2lfV", P / I);
        } else {
            printf("P=%.2lfW", U * I);
        }
        printf("\n\n");
    }
    return 0;
}
