#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 52;
const int INF = 1000000007;

int N, M, K, ans;
int X[MAXN][MAXN], st[MAXN];
int f[MAXN][1 << 10];
bool Z[MAXN][1 << 10], CZ[MAXN];
queue<int> Q;

void init() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) X[i][j] = 0; else X[i][j] = INF;
        }
    }
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        X[a][b] = min(X[a][b], c);
        X[b][a] = min(X[b][a], c);
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                X[i][j] = min(X[i][j], X[i][k] + X[k][j]);
            }
        }
    }

    ans = INF;
    memset(st, 0, sizeof(st));
    for (int i = 1; i <= K; ++i) {
        st[i] = (1 << (i - 1));
        st[N - K + i] = (1 << (K + i - 1));
    }
}

void SPFA(int s) {
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        Z[a][s] = false;
        for (int i = 1; i <= N; ++i) {
            if (f[i][st[i]|s] > f[a][s] + X[a][i]) {
                f[i][st[i]|s] = f[a][s] + X[a][i];
                if ((st[i]|s) != s || Z[i][s]) continue;
                Z[i][s] = true;
                Q.push(i);
            }
        }
    }
}

void BASE() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < (1 << (K + K)); ++j) f[i][j] = INF;
        f[i][st[i]] = 0;
    }
    for (int j = 1; j < (1 << (K + K)); ++j) {
        for (int i = 1; i <= N; ++i) {
            if (st[i] && (st[i] & j) == 0) continue;
            for (int k = (j - 1) & j; k; k = (k - 1) & j) {
                int x = st[i] | k, y = st[i] | (j - k);
                f[i][j] = min(f[i][j], f[i][x] + f[i][y]);
            }
            if (f[i][j] != -1) {
                Q.push(i);
                Z[i][j] = true;
            }
        }
        SPFA(j);
        f[0][j] = INF;
        for (int i = 1; i <= N; ++i) f[0][j] = min(f[0][j], f[i][j]);
    }
}

void dfs(int a, int s, int sum, vector<int> &S) {
    if (a == K + 1) {
        ans = min(sum + f[0][s], ans);
        return ;
    }
    for (int i = 1; i <= K; ++i) {
        if (CZ[i]) continue;
        CZ[i] = true;
        s |= st[i];
        s |= st[S[i - 1]];
        dfs(a + 1, s, sum, S);
        if (f[0][s] != INF) dfs(a + 1, 0, sum + f[0][s], S);
        s ^= st[i];
        s ^= st[S[i - 1]];
        CZ[i] = false;
    }
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        init();
        BASE();
        vector<int> S;
        for (int i = 0; i < K; ++i) S.push_back(N - K + i + 1);
        do {
            dfs(1, 0, 0, S);
        } while (next_permutation(S.begin(), S.end()));
        if (ans == INF) 
            cout << "No solution" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
