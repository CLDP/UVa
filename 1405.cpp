#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 202;
const int MAXL = 105;
const int INF = 1000000007;
const long long INFF = 10000000000000061LL;

int L[MAXN];
char x[MAXN][MAXL + MAXL];
long long y[MAXN][MAXL + MAXL][MAXL];
int f[MAXN][MAXL];

void update(int &a, int b) {
    if (a == -1 || a > b) a = b;
}

int add(int a, int b, int c) {
    for (int i = L[a + 1]; i >= 1; --i) {
        if (y[a][b][i] == y[a + 1][c + L[a + 1] - i][i]) return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        string P;
        cin >> P;
        reverse(P.begin(), P.end());
        int N = 0;
        for (int i = 0; i < P.size(); ) {
            int j = i;
            while (j < P.size() && isalpha(P[j])) ++j;
            L[N] = j - i;
            for (int k = i; k < j; ++k) x[N][k - i] = x[N][k - i + j - i] = P[j + i - k - 1];
            ++N;
            i = j + 1;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < L[i] + L[i]; ++j) {
                y[i][j][0] = 0;
                for (int k = 1; k <= L[i] && j + k < L[i] + L[i]; ++k) {
                    y[i][j][k] = (y[i][j][k - 1] * 26 + x[i][j + k - 1] - 'A') % INFF;
                }
            }
        }

        memset(f, -1, sizeof(f));
        for (int i = 0; i < L[0]; ++i) f[0][i] = L[0];


        for (int i = 0; i < N - 1; ++i) {
            for (int j = 0; j < L[i]; ++j) {
                for (int k = 0; k < L[i + 1]; ++k) {
                    update(f[i + 1][k], f[i][j] + L[i + 1] - add(i, j, k));
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < L[N - 1]; ++i) ans = min(ans, f[N - 1][i]);

        int p;
        string ansA, ansP, ansC;
        for (int i = 0; i < L[N - 1]; ++i) ansC.push_back(x[N - 1][i]);

        for (int i = 0; i < L[N - 1]; ++i) {
            if (f[N - 1][i] != ans) {
                ansC = ansC.substr(1, L[N - 1] - 1) + x[N - 1][i + L[N - 1]];
                continue;
            }
            if (ansP.empty() || ansC < ansP) {
                p = i;
                ansP = ansC;
            }
            ansC = ansC.substr(1, L[N - 1] - 1) + x[N - 1][i + L[N - 1]];
        }
        ansC.clear();

        for (int i = N - 2; i >= 0; --i) {
            int pos = -1;
            for (int j = 0; j < L[i]; ++j) {
                int temp = add(i, j, p);
                if (f[i][j] + L[i + 1] - temp == f[i + 1][p]) {
                    string ansT = ansP;
                    for (int k = temp; k < L[i]; ++k) ansT.push_back(x[i][j + k]);
                    if (ansC.empty() || ansC > ansT) {
                        pos = j;
                        ansC = ansT;
                    }
                }
            }
            p = pos;
            ansP = ansC;
            ansC.clear();

            if (ansP.size() > L[i]) {
                ansA = ansA + ansP.substr(0, ansP.size() - L[i]);
                ansP = ansP.substr(ansP.size() - L[i], L[i]);
            }
        }

        cout << ansA + ansP << endl;
    }

    return 0;
}
