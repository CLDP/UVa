#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 210;
const int MAXM = 21000;
const int KM = 211;
const int INF = 1000000007;

struct event {
    int s, t, l, ID;
    event() {}
    event(int _s, int _t, int _l, int _ID): s(_s), t(_t), l(_l), ID(_ID) {}
    bool operator < (const event &B) const {
        if (ID != B.ID) return ID < B.ID;
        if (l != B.l) return l < B.l;
        if (s != B.s) return s < B.s;
        return t < B.t;
    }
};

int N;
string P;
vector<event> E;
int x[MAXN][MAXN];

// results
int f[MAXN][MAXN];
bool zf[MAXN][MAXN];
int g[MAXM][MAXN], h[MAXM][MAXN];
bool zg[MAXM][MAXN];

int dp(int a, int b);
int dp2(int a, int b);
string bk(int a, int b);
string bk2(int a, int b, int c);

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> P) {
        N = P.size();

        E.clear();
        for (int i = 0; i < N; ++i) {
            long long temp = 0;
            for (int j = i; j < N; ++j) {
                temp = (temp * KM + P[j]) % INF;
                E.push_back(event(i, j, j - i + 1, (int)temp));
            }
        }
        sort(E.begin(), E.end());
        for (int i = 0; i < E.size(); ++i) x[E[i].s][E[i].t] = i;
        E.push_back(event(-1, -1, -1, -1));

        memset(zf, 0, sizeof(zf));
        memset(zg, 0, sizeof(zg));
        cout << dp(0, N - 1);
        cout << " " << bk(0, N - 1) << endl;
    }

    return 0;
}


int dp(int a, int b) {
    if (a > b) return f[a][b] = 0;
    if (zf[a][b]) return f[a][b];
    zf[a][b] = true;
    // no changes
    f[a][b] = b - a + 1;
    // split into two
    for (int i = a + 1; i <= b; ++i) f[a][b] = min(f[a][b], dp(a, i - 1) + dp(i, b));
    // change
    for (int l = 1; l < b - a + 1; ++l) {
        int s1 = a, t1 = a + l - 1;
        int t2 = b, s2 = b - l + 1;
        if (t1 >= s2) break;
        int x1 = x[s1][t1], x2 = x[s2][t2];
        if (E[x1].ID != E[x2].ID) continue;
        f[a][b] = min(f[a][b], dp2(x1, s2 - 1) + 3 + dp(s1, t1));
    }
    return f[a][b];
}

int dp2(int a, int b) {
    if (zg[a][b]) return g[a][b];
    zg[a][b] = true;
    // no changes
    if (b == E[a].t) {
        g[a][b] = 0;
    } else {
        g[a][b] = dp(E[a].t + 1, b) + 3;
    }
    h[a][b] = 1;
    // changes
    for (int i = a + 1; ; ++i) {
        if (E[i].ID != E[a].ID || E[i].t > b) break;
        if (E[i].s <= E[a].t) continue;
        dp2(i, b);
        if (E[a].t + 1 == E[i].s) {
            if (g[a][b] > g[i][b]) {
                g[a][b] = g[i][b];
                h[a][b] = h[i][b] + 1;
            }
        } else {
            dp(E[a].t + 1, E[i].s - 1);
            if (g[a][b] > g[i][b] + f[E[a].t + 1][E[i].s - 1] + 3) {
                g[a][b] = g[i][b] + f[E[a].t + 1][E[i].s - 1] + 3;
                h[a][b] = h[i][b] + 1;
            }
        }
    }
    return g[a][b];
}

string bk(int a, int b) {
    if (a > b) return "";
    if (f[a][b] == b - a + 1) return P.substr(a, b - a + 1);
    for (int i = a + 1; i <= b; ++i) {
        if (f[a][b] == f[a][i - 1] + f[i][b]) return bk(a, i - 1) + bk(i, b);
    }
    for (int l = 1; l < b - a + 1; ++l) {
        int s1 = a, t1 = a + l - 1;
        int t2 = b, s2 = b - l + 1;
        if (t1 >= s2) break;
        int x1 = x[s1][t1], x2 = x[s2][t2];
        if (E[x1].ID != E[x2].ID) continue;
        if (f[a][b] == g[x1][s2 - 1] + 3 + f[s1][t1]) {
            return "[" + bk(s1, t1) + "]" + to_string(h[x1][s2 - 1] + 1) + bk2(x1, s2 - 1, 1);
        }
    }
    return "";
}

string bk2(int a, int b, int c) {
    if (b == E[a].t) return "";
    if (g[a][b] == f[E[a].t + 1][b] + 3) return "{" + bk(E[a].t + 1, b) + "}" + to_string(c);
    for (int i = a + 1; ; ++i) {
        if (E[i].ID != E[a].ID || E[i].t > b) break;
        if (E[i].s <= E[a].t) continue;
        if (E[a].t + 1 == E[i].s) {
            if (g[a][b] == g[i][b]) return bk2(i, b, c + 1);
        } else {
            if (g[a][b] == g[i][b] + f[E[a].t + 1][E[i].s - 1] + 3) {
                return "{" + bk(E[a].t + 1, E[i].s - 1) + "}" + to_string(c) + bk2(i, b, c + 1);
            }
        }
    }
    return "";
}
