#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 15;
const int MAXM = 101;

bool x[MAXN][MAXN];
char y[MAXM], z[MAXM];
int f[1 << MAXN], g[1 << MAXN], ans[MAXN], MM;
bool h[1 << MAXN];

bool check(int a) {
    for (int i = 0; i < MM; ++i) {
        if ((a & (1 << i)) == 0) continue;
        for (int j = i + 1; j < MM; ++j) {
            if ((a & (1 << j)) == 0) continue;
            if (x[i][j]) return false;
        }
    }
    return true;
}

int dp(int a) {
    if (f[a] != -1) return f[a];
    if (a == 0) return -1;
    f[a] = MM + 1;
    for (int i = a; i; i = (i - 1) & a) {
        if (h[i]) {
            int temp = dp(a ^ i) + 1;
            if (temp < f[a]) {
                f[a] = temp;
                g[a] = a ^ i;
            }
        }
    }
    return f[a];
}

int main() {
    int N;
    while (cin >> N) {
        map<char, int> C;
        for (int i = 0; i < N; ++i) {
            cin >> y[i] >> z[i];
            C[y[i]] = C[z[i]] = 0;
        }
        MM = 0;
        for (auto iter = C.begin(); iter != C.end(); ++iter) iter->second = MM++;
        memset(x, 0, sizeof(x));
        for (int i = 0; i < N; ++i) x[C[y[i]]][C[z[i]]] = x[C[z[i]]][C[y[i]]] = true;

        for (int i = 0; i < (1 << MM); ++i) {
            f[i] = g[i] = -1;
            h[i] = check(i);
        }
        dp((1 << MM) - 1);
        vector<int> X;
        X.push_back((1 << MM) - 1);
        while (X.back() != 0) X.push_back(g[X.back()]);
        memset(ans, -1, sizeof(ans));
        for (int i = X.size() - 1; i >= 0; --i) {
            for (int j = 0; j < MM; ++j) {
                if ((1 << j) & X[i] && ans[j] == -1) ans[j] = i;
            }
        }
        cout << f[(1 << MM) - 1] - 1 << endl;
        for (int i = 0; i < N; ++i) {
            if (ans[C[y[i]]] > ans[C[z[i]]]) {
                cout << y[i] << " " << z[i] << endl;
            } else {
                cout << z[i] << " " << y[i] << endl;
            }
        }
    }
    return 0;
}
