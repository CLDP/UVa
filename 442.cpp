#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 1000;
int x[100], y[100];


int main() {
    int n;
    char p;
    char q[MAXN];
    int xx[MAXN], yy[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%c", &p);
        while (!isalpha(p)) scanf("%c", &p);
        scanf("%d%d", &x[p], &y[p]);
    }
    int a, b, c, d, top, ans;
    bool flag;
    while (scanf("%s", q) != EOF) {
        top = strlen(q);
        for (int i = top; i >= 0; --i) q[i + 1] = q[i];
        q[0] = '(';   
        q[top + 1] = ')';   
        q[top + 2] = '\0';
        ans = 0;
        top = 0;
        flag = false;
        for (int i = 0; i < strlen(q); ++i) {
            if (isalpha(q[i])) {
                ++top;
                xx[top] = x[q[i]];
                yy[top] = y[q[i]];
            } else 
            if (q[i] == '(') {
                ++top;
                xx[top] = -1;
                yy[top] = -1;
            } else {
                a = xx[top];  b = yy[top]; --top;
                c = xx[top];  d = yy[top]; 
                while (c > -1) {
                    --top;
                    if (d == a) {
                        ans += c * d * b;
                        ++top;
                        xx[top] = c;
                        yy[top] = b;
                    } else {
                        flag = true;
                        printf("error\n");
                        break;
                    }
                    if (flag) break;
                    a = xx[top];  b = yy[top]; --top;
                    c = xx[top];  d = yy[top]; 
                }
                xx[top] = a;
                yy[top] = b;
            }
            if (flag) break;
        }
        if (!flag) printf("%d\n", ans);
    }
    return 0;
}
