#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1002;

int f[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string P;
    while (cin >> P) {
        int N = P.size();
        for (int i = 0; i < N; ++i) f[i][i] = 0;
        for (int l = 1; l < N; ++l) {
            for (int i = 0; i + l < N; ++i) {
                int j = i + l;
                f[i][j] = min(f[i][j - 1], f[i + 1][j]) + 1;
                if (P[i] == P[j]) f[i][j] = min(f[i][j], f[i + 1][j - 1]);
            }
        }

        string Q;
        int a = 0, b = N - 1;
        while (a < b) {
            if (f[a][b] == f[a + 1][b - 1] && P[a] == P[b]) {
                Q.push_back(P[a]);
                ++a;
                --b;
                continue;
            }
            if (f[a][b] == f[a][b - 1] + 1) {
                Q.push_back(P[b]);
                --b;
                continue;
            }
            if (f[a][b] == f[a + 1][b] + 1) {
                Q.push_back(P[a]);
                ++a;
                continue;
            }
        }
        cout << f[0][N - 1] << " " << Q;
        if (a == b) cout << P[a];
        reverse(Q.begin(), Q.end());
        cout << Q << endl;
    }

    return 0;
}
