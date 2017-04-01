#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 105;

int x[MAXN], y[MAXN], T, B;
int f[MAXN][MAXN][MAXN][2];

void update(int a, int b) {
    if (x[a] == 0) x[a] = b;
    if (y[a] == 0) y[a] = b;
    x[a] = min(x[a], b);
    y[a] = max(y[a], b);
}


// d = 1, must take (b, c)
// d = 0, must cover before b, currently take from c
int dp(int a, int b, int c, int d) {
    if (f[a][b][c][d] != -1) return f[a][b][c][d];

    int &ans = f[a][b][c][d];
    ans = MAXN;

    if (a == B) {
        if (d == 1) return ans;
        return ans = 0;
    }

    if (d == 1) {
        if (b < x[a]) return ans;

        // fill this row
        if (b == c) {
            ans = dp(a + 1, 0, c + 1, 0) + 1;
        } else {
            ans = dp(a + 1, b + 1, c, d) + 1;
        }
        // not fill this row
        ans = min(ans, dp(a + 1, b, y[a], d));
    } else {
        if (c < x[a]) c = x[a];

        // owe nothing
        if (b < x[a]) {
            if (c > y[a]) return ans = dp(a + 1, b, c, 0);
            // not fill this row
            ans = min(ans, dp(a + 1, c, y[a], 1));
        } else {
            if (c > y[a]) return ans;
            // not fill this row: no you cannot do that
        }

        // fill this row
        ans = min(ans, dp(a + 1, b, c + 1, 0) + 1);
        for (int i = c + 1; i <= y[a]; ++i) {
            ans = min(ans, dp(a + 1, i - 1, i + 1, 0) + 1);
        }
    }
    return ans;
}

int main() {
    int a, b, times = 0;
    while (cin >> a >> b) {
        if (a + b == 0) break;
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        int sa = a, sb = b;
        int c, d;
        T = B = a;
        while (cin >> c >> d) {
            if (c + d == 0) {
                c = sa;
                d = sb;
                sa = sb = 0;
            }
            T = min(T, c);
            B = max(B, c);
            if (c == a) {
                if (b < d) update(c, d - 1); else update(c - 1, d);
            } else {
                if (a < c)
                    for (int i = a; i < c; ++i) update(i, d - 1);
                else 
                    for (int i = c; i < a; ++i) update(i, d);
            }
            a = c;
            b = d;
            if (sa + sb == 0) break;
        }
        memset(f, -1, sizeof(f));
        cout << ++times << " " << dp(T, 0, x[T], 0) << endl;
    }

    return 0;
}
