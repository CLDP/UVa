#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 30;
int n, m, ans;
bool z[MAXN][MAXN];
bool cz[MAXN][MAXN];

int dfs(int a, int now) {
    if (now > ans) ans = now;
    for (int i = 0; i < n; ++i) {
        if (z[a][i] && !cz[a][i]) {
            cz[a][i] = true;
            cz[i][a] = true;
            dfs(i, now + 1);
            cz[a][i] = false;
            cz[i][a] = false;
        }
    }
    return 0;
}


int main() {
    int a, b;
    cin >> n >> m;
    while (n && m) {
        memset(z, 0, sizeof(z));
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            z[a][b] = true;
            z[b][a] = true;
        }
        ans = 0;
        for (int i = 0; i < n; ++i) dfs(i, 0);
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}
