#include <iostream>
#include <string>
using namespace std;

const int MAXN = 202;

string P;
string f[MAXN][MAXN];

void update(string &P, string Q) {
    if (P == "" || P.size() > Q.size()) P = Q;
}

bool check(int a, int b, int c) {
    string Q = P.substr(a, c);
    for (int i = a + c; i <= b; i += c) {
        if (Q != P.substr(i, c)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> P;
        int N = P.size();
        for (int i = 0; i < N; ++i) {
            f[i][i] = P[i];
            for (int j = i + 1; j < N; ++j) f[i][j] = "";
        }
        for (int l = 2; l <= N; ++l) {
            for (int i = 0; i + l - 1 < N; ++i) {
                int j = i + l - 1;
                for (int k = i; k < j; ++k) update(f[i][j], f[i][k] + f[k + 1][j]);
                for (int k = 1; k <= l; ++k) {
                    if (l % k != 0) continue;
                    if (check(i, j, k)) update(f[i][j], to_string(l / k) + "(" + f[i][i + k - 1] + ")");
                }
            }
        }
        cout << f[0][N - 1].size() << endl;
    }
    return 0;
}
