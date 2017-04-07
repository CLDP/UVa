#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int MAXK = 3010;

struct matching {
    int N, M, l[MAXN];
    bool x[MAXN][MAXN], z[MAXN];

    void clear(int _N, int _M) {
        N = _N;
        M = _M;
        memset(x, 0, sizeof(x));
    }

    void add(int a, int b) {
        x[a][b] = true;
    }

    void del(int a, int b) {
        x[a][b] = false;
    }

    bool find(int v) {
        for (int i = 1; i <= M; ++i) {
            if (!z[i] && x[v][i]) {
                z[i] = 1;
                int k = l[i];
                l[i] = v;
                if (!k || find(k)) return true;
                l[i] = k;
            }
        }
        return false;
    }

    int match() {
        memset(l, 0, sizeof(l));
        for (int i = 1; i <= N; ++i) {
            memset(z, 0, sizeof(z));
            find(i);
        }
        int ans = 0;
        for (int i = 1; i <= M; ++i) ans += (l[i] > 0);
        return ans;
    }
};


int N, K, root;

vector<int> X[MAXN];
// up coming edge list
vector<int> Y[MAXN];
// pairing edges
vector<int> P[MAXN];
bool z[MAXK];
// depth, color, father, result
int d[MAXN], c[MAXN], f[MAXN], g[MAXN];
// vertex ID in matching
int p[MAXN];
// path top
int s1[MAXK], s2[MAXK];
// top vertex to path ID
vector<int> Q[MAXN];

matching mt;


void dfs(int a, int fa, int depth) {
    f[a] = fa;
    d[a] = depth;
    c[a] = 0;
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i] == fa) continue;
        dfs(X[a][i], a, depth + 1);
    }
}

void color(int a, int ca) {
    c[a] = ca;
    z[a] = true;
    for (int i = 0; i < P[a].size(); ++i) {
        if (z[P[a][i]]) continue;
        color(P[a][i], 3 - ca);
    }
}

void dp(int a) {
    g[a] = 0;
    int N = 0, M = 0;
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i] == f[a]) continue;
        dp(X[a][i]);
        if (c[X[a][i]] == 1) p[X[a][i]] = ++N;
        if (c[X[a][i]] == 2) p[X[a][i]] = ++M;
    }

    for (int i = 0; i < Q[a].size(); ++i) {
        if (z[Q[a][i]]) continue;
        int t = Q[a][i];
        if (s1[t] == 0) {
            ++g[a];
            t = s2[t];
            for (int j = 0; j < Y[t].size(); ++j) z[Y[t][j]] = true;
        }
    }

    mt.clear(N, M);
    for (int i = 0; i < Q[a].size(); ++i) {
        if (z[Q[a][i]]) continue;
        int t = Q[a][i];
        if (s1[t] == 0) continue;
        if (c[s1[t]] == 2) swap(s1[t], s2[t]);
        // new edge p[s1[t]] -- p[s2[t]]
        mt.add(p[s1[t]], p[s2[t]]);
    }

    if (N == 0 || M == 0) return ;
    int res = mt.match();

    int xx[MAXN];

    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i] == f[a]) continue;
        if (c[X[a][i]] == 1) {
            int t = p[X[a][i]];
            for (int j = 1; j <= M; ++j) {
                xx[j] = mt.x[t][j];
                mt.x[t][j] = false;
            }
            int temp = mt.match();
            for (int j = 1; j <= M; ++j) mt.x[t][j] = xx[j];
            if (temp == res) continue;
        } else {
            int t = p[X[a][i]];
            for (int j = 1; j <= N; ++j) {
                xx[j] = mt.x[j][t];
                mt.x[j][t] = false;
            }
            int temp = mt.match();
            for (int j = 1; j <= N; ++j) mt.x[j][t] = xx[j];
            if (temp == res) continue;
        }
        int t = X[a][i];
        for (int j = 0; j < Y[t].size(); ++j) z[Y[t][j]] = true;
    }
    g[a] += res;
}


int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> N >> K >> root) {
        if (N + K + root == 0) break;
        for (int i = 1; i <= N; ++i) {
            X[i].clear();
            Y[i].clear();
            P[i].clear();
            Q[i].clear();
        }
        for (int i = 1; i < N; ++i) {
            int a, b;
            cin >> a >> b;
            X[a].push_back(b);
            X[b].push_back(a);
        }
        dfs(root, -1, 0);
        for (int i = 1; i <= K; ++i) {
            int a, b;
            cin >> a >> b;
            s1[i] = s2[i] = 0;
            while (a != b) {
                if (d[a] > d[b]) {
                    Y[a].push_back(i);
                    s2[i] = a;
                    a = f[a];
                } else
                if (d[a] < d[b]) {
                    Y[b].push_back(i);
                    s2[i] = b;
                    b = f[b];
                } else {
                    Y[a].push_back(i);
                    Y[b].push_back(i);
                    if (f[a] == f[b]) {
                        P[a].push_back(b);
                        P[b].push_back(a);
                        s1[i] = a;
                        s2[i] = b;
                        Q[f[a]].push_back(i);
                    }
                    a = f[a];
                    b = f[b];
                }
            }
            if (s1[i] == 0) Q[a].push_back(i);
        }

        memset(z, 0, sizeof(z));
        for (int i = 1; i <= N; ++i) {
            if (z[i] || P[i].empty()) continue;
            color(i, 1);
        }

        memset(z, 0, sizeof(z));
        dp(root);
        int ans = 0;
        for (int i = 1; i <= N; ++i) ans += g[i];
        cout << ans << endl;
    }

    return 0;
}
