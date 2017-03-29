#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2010;

int f[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string P, Q;
    while (getline(cin, P)) {
        getline(cin, Q);
        memset(f, 0, sizeof(f));
        for (int i = 0; i < P.size(); ++i) {
            for (int j = 0; j < Q.size(); ++j) {
                f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);
                if (P[i] == Q[j]) f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
            }
        }
        cout << f[P.size()][Q.size()] << endl;
    }
    return 0;
}
