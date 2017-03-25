#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 102;
const int MAXA = 27;

string P, Q;
int f[MAXN][MAXN][27];

int dp(int a, int b, int c) {
    if (f[a][b][c] != -1) return f[a][b][c];
    if (a == b) {
        if (c == 26) {
            if (P[a] == Q[a]) return f[a][b][c] = 0; 
            return f[a][b][c] = 1;
        }
        if (c == Q[a] - 'a') return f[a][b][c] = 0;
        return f[a][b][c] = 1;
    }

    f[a][b][c] = MAXN;
    for (int i = a; i < b; ++i) {
        f[a][b][c] = min(f[a][b][c], dp(a, i, c) + dp(i + 1, b, c));
    }

    if (c == 26) {
        if (P[a] == Q[a]) return f[a][b][c] = dp(a + 1, b, c);
        if (P[b] == Q[b]) return f[a][b][c] = dp(a, b - 1, c);
    } else {
        if (Q[a] - 'a' == c) return f[a][b][c] = dp(a + 1, b, c);
        if (Q[b] - 'a' == c) return f[a][b][c] = dp(a, b - 1, c);
    }
    int i = a, j = b;
    while (i <= j && Q[i] == Q[a]) ++i;
    while (i <= j && Q[j] == Q[a]) --j;
    if (i > j) return f[a][b][c] = 1;
    f[a][b][c] = min(f[a][b][c], dp(i, j, Q[a] - 'a') + 1);
    if (Q[a] == Q[b]) return f[a][b][c];

    i = a, j = b;
    while (i <= j && Q[i] == Q[b]) ++i;
    while (i <= j && Q[j] == Q[b]) --j;
    if (i > j) return f[a][b][c] = 1;
    f[a][b][c] = min(f[a][b][c], dp(i, j, Q[b] - 'a') + 1);
    return f[a][b][c];
}

int main() {
    while (cin >> P >> Q) {
        int N = P.size();
        memset(f, -1, sizeof(f));
        dp(0, N - 1, 26);
        cout << f[0][N - 1][26] << endl;
    }
    return 0;
}
