#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 202;
const int INF = 10000;

struct matching {
    int N, M;
    // z is the weight matrix input
    int z[MAXN][MAXN];
    bool x[MAXN], y[MAXN];
    int lx[MAXN], ly[MAXN];

    // l is the matching result, see below for usage
    int l[MAXN];

    void clear(int _N, int _M) {
        N = _N;
        M = _M;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) z[i][j] = 0;
        }
    }

    void add(int a, int b, int c) {
        z[a][b] = c;
    }

    bool find(int v, int M) {
        int k;
        x[v] = true;
        for (int i = 1; i <= M; ++i) {
            if (!y[i] && lx[v] + ly[i] == z[v][i]) {
                y[i] = true;
                k = l[i];
                l[i] = v;
                if (k == 0 || find(k, M)) return true;
                l[i] = k;
            }
        }
        return false;
    }

    // requires an input with perfect matching
    // otherwise will go into infinite loop
    int match(int N, int M) {
        memset(lx, 0, sizeof(lx));
        memset(ly, 0, sizeof(ly));
        memset(l, 0, sizeof(l));

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (z[i][j] > lx[i]) lx[i] = z[i][j];
            }
        }
        
        for (int k = 1; k <= N; ++k) while (true) {
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            
            if (find(k, M)) break;
            int d = INF;
            for (int i = 1; i <= N; ++i) if (x[i])
             for (int j = 1; j <= M; ++j) if (!y[j])
              if (d > lx[i] + ly[j] - z[i][j]) d = lx[i] + ly[j] - z[i][j];
            for (int i = 1; i <= N; ++i) if (x[i]) lx[i] -= d;
            for (int j = 1; j <= M; ++j) if (y[j]) ly[j] += d;
        }
        
        int flow = 0, cost = 0;
        for (int i = 1; i <= M; ++i) {
            if (l[i] > 0) {
                ++flow;
                cost += z[l[i]][i];     
            }
        }
        return cost;
    }
};


bool z[MAXN][MAXN];
int f[MAXN][MAXN];
int f1[MAXN], f2[MAXN];
int s1[MAXN], s2[MAXN];
vector<int> X[MAXN], Y[MAXN];
matching mt;

int dp(int a, int b) {
    if (z[a][b]) return f[a][b];
    z[a][b] = true;
    for (int i = 0; i < X[a].size(); ++i) {
        for (int j = 0; j < Y[b].size(); ++j) dp(X[a][i], Y[b][j]);
    }
    int N = max(X[a].size(), Y[b].size());
    if (N == 0) return f[a][b] = 0;
    mt.clear(N, N);
    for (int i = 0; i < X[a].size(); ++i) {
        for (int j = 0; j < Y[b].size(); ++j) mt.add(i + 1, j + 1, INF - f[X[a][i]][Y[b][j]]);
    }
    if (X[a].size() < N) {
        for (int i = X[a].size(); i < N; ++i) {
            for (int j = 0; j < Y[b].size(); ++j) mt.add(i + 1, j + 1, INF - s2[Y[b][j]]);
        }
    } 
    if (Y[b].size() < N) {
        for (int i = 0; i < X[a].size(); ++i) {
            for (int j = Y[b].size(); j < N; ++j) mt.add(i + 1, j + 1, INF - s1[X[a][i]]);
        }
    }
    return f[a][b] = N * INF - mt.match(N, N);
}

int dfsx(int a) {
    s1[a] = 1;
    for (int i = 0; i < X[a].size(); ++i) s1[a] += dfsx(X[a][i]);
    return s1[a];
}

int dfsy(int a) {
    s2[a] = 1;
    for (int i = 0; i < Y[a].size(); ++i) s2[a] += dfsy(Y[a][i]);
    return s2[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N, M;
        cin >> N;
        for (int i = 0; i <= N; ++i) X[i].clear();
        for (int i = 1; i <= N; ++i) {
            cin >> f1[i];
            X[f1[i]].push_back(i);
        }
        cin >> M;
        for (int i = 0; i <= M; ++i) Y[i].clear();
        for (int i = 1; i <= M; ++i) {
            cin >> f2[i];
            Y[f2[i]].push_back(i);
        }
        dfsx(0);
        dfsy(0);
        memset(z, 0, sizeof(z));
        cout << "Case " << times << ": " << dp(0, 0) << endl;
    }
    return 0;
}
