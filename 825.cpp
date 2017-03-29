#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

const int MAXN = 210;

int f[MAXN][MAXN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        memset(f, 0, sizeof(f));
        f[1][1] = 1;
        string P;
        getline(cin, P);
        for (int i = 0; i < N; ++i) {
            getline(cin, P);
            int a, b;
            istringstream PIN(P);
            PIN >> a;
            while (PIN >> b) {
                f[a][b] = -1;
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (f[i][j] == -1) continue;
                if (f[i - 1][j] != -1) f[i][j] += f[i - 1][j];
                if (f[i][j - 1] != -1) f[i][j] += f[i][j - 1];
            }
        }
        if (f[N][M] == -1) f[N][M] = 0;
        cout << f[N][M] << endl;
        if (T != 0) cout << endl;
    }
    return 0;
}
