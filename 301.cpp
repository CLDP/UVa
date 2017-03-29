#include <iostream>
using namespace std;

const int MAXN = 30;
int n, m, num, ans;
int x[MAXN], y[MAXN], w[MAXN];
int z[MAXN];

int dfs(int a, int now) {
    if (now > ans) ans = now;
    bool flag;
    for (int i = a + 1; i < m; ++i) {
        flag = true;
        for (int j = x[i]; j < y[i]; ++j) {
            z[j] += w[i];
            flag &= (z[j] <= num);
        }
        if (flag) dfs(i, now + (y[i] - x[i]) * w[i]);
        for (int j = x[i]; j < y[i]; ++j) z[j] -= w[i];
    }
    return 0;
}

int swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    cin >> num >> n >> m;
    while (num || n || m) {
        for (int i = 0; i < m; ++i) cin >> x[i] >> y[i] >> w[i];
        ans = 0;
        dfs(-1, 0);
        cout << ans << endl;
        cin >> num >> n >> m;
    }
    return 0;
}
