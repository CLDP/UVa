#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int f[MAXN][MAXN];
string g[MAXN][MAXN];

void update(string &P, string Q) {
    if (P == "" || P > Q) P = Q;
}

int main() {
    ios_base::sync_with_stdio(false);
    string P;
    while (cin >> P) {
        memset(f, 0, sizeof(f));
        string Q = P;
        reverse(Q.begin(), Q.end());
        int N = P.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; i + j < N; ++j) {
                f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
                if (P[i] == Q[j]) f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; i + j < N; ++j) {
                g[i + 1][j + 1] = "";
                if (f[i + 1][j + 1] == f[i][j + 1]) update(g[i + 1][j + 1], g[i][j + 1]);
                if (f[i + 1][j + 1] == f[i + 1][j]) update(g[i + 1][j + 1], g[i + 1][j]);
                if (P[i] == Q[j] && f[i + 1][j + 1] == f[i][j] + 1) update(g[i + 1][j + 1], g[i][j] + P[i]);
            }
        }

        int ans = 1;
        for (int i = 0; i < N; ++i) {
            ans = max(ans, 1 + f[i][N - i - 1] * 2);
            ans = max(ans, f[i + 1][N - i - 1] * 2);
        }
        string R;
        for (int i = 0; i < N; ++i) {
            if (1 + f[i][N - i - 1] * 2 == ans) {
                string temp = g[i][N - i - 1];
                string S = temp + P[i];
                reverse(temp.begin(), temp.end());
                S = S + temp;
                update(R, S);
            }
            if (f[i + 1][N - i - 1] * 2 == ans) {
                string temp = g[i + 1][N - i - 1];
                string S = temp;
                reverse(temp.begin(), temp.end());
                S = S + temp;
                update(R, S);
            }
        }
        cout << R << endl;
    }
    return 0;
}
