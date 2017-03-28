#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

const int MAXM = 10000;
char p[MAXM];

int main() {
    int n, m, j;
    gets(p);
    while (true) {
        int i = 0;
        while (i < strlen(p)) {
            if (isdigit(p[i])) {
                j = i;
                m = 0;
                while (isdigit(p[j])) { 
                    m += p[j] - '0';
                    ++j;
                }
                i = j - 1;
            } else 
            if (isalpha(p[i]) || p[i] == '*') {
                if (p[i] == 'b') 
                    for (j = 0; j < m; ++j) printf(" ");
                else 
                    for (j = 0; j < m; ++j) printf("%c", p[i]);
            } else 
            if (p[i] == '!') printf("\n");
            ++i;
        }
        printf("\n");
        if (!gets(p)) break;      
    };
    return 0;
}
