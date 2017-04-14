#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

struct node {
    int a, b;
    bool operator < (const node &B) const {
        if (a != B.a) return a > B.a;
        return b < B.b;
    }
};

node X[MAXN];
// Jan, Petra
int f[MAXN][MAXN], g[MAXN][MAXN];

void update(int a, int b, int c, int d) {
    if (c == -1 || d == -1) return ;
    if (f[a][b] < c || (f[a][b] == c && g[a][b] < d)) {
        f[a][b] = c;
        g[a][b] = d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        string P;
        cin >> N >> P;
        for (int i = 1; i <= N; ++i) cin >> X[i].a >> X[i].b;
        sort(X + 1, X + N + 1);
        memset(f, -1, sizeof(f));
        memset(g, -1, sizeof(g));

        int off = (P != "Petra");
        f[0][0] = g[0][0] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= (i + off) / 2; ++j) {
                update(i, j, f[i - 1][j], g[i - 1][j] + X[i].a);
                if (j > 0) update(i, j, f[i - 1][j - 1] + X[i].b, g[i - 1][j - 1]);
            }
        }
        cout << g[N][(N + off) / 2] << " " << f[N][(N + off) / 2] << endl;
    }
    return 0;
}
