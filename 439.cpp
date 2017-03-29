#include <cstdio>
#include <cstring>
#include <cctype>

int mx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int my[8] = {1, -1, 2, -2, 2, -2, 1, -1};

bool check(int a, int b) {
    if (a >= 0 && a < 8 && b >= 0 && b < 8) return true;
    return false;
}


int main() {
    char p[3], q[3];
    bool z[8][8];
    int a[100], b[100], x[100], l, r, a0, b0;
    while (scanf("%s%s", p, q) != EOF) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(x, 0, sizeof(x));
        memset(z, 0, sizeof(z));
        l = r = 0; 
        a[r] = p[0] - 'a';
        b[r] = p[1] - '1';
        a0 = q[0] - 'a';
        b0 = q[1] - '1';
        ++r;
        while (l < r) {
            if (a0 == a[l] && b0 == b[l]) {
                printf("To get from %s to %s takes %d knight moves.\n", p, q, x[l]);
                break;
            }
            z[a[l]][b[l]] = true;
            for (int i = 0; i < 8; ++i) {
                if (check(a[l] + mx[i], b[l] + my[i]) 
                    && !z[a[l] + mx[i]][b[l] + my[i]]) {
                    a[r] = a[l] + mx[i];
                    b[r] = b[l] + my[i];
                    x[r] = x[l] + 1;
                    z[a[r]][b[r]] = true;
                    ++r;
                }
            }
            ++l;
        }
    }
    
    return 0;
}
