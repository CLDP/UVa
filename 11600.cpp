#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAXN = 32;
const int MAXK = 5700;
const int INF = 1000000000;

int N, M;
vector<int> X[MAXN];
map<vector<int>, int> S;
double f[MAXK][30];
bool z[MAXN], cz[MAXK][30];

void dfs(int a, int b, int &cnt, vector<int> &Y) {
    if (a == 0) {
        S[Y] = ++cnt;
        return ;
    }
    for (int i = 1; i <= min(a, b); ++i) {
        Y.push_back(i);
        dfs(a - i, i, cnt, Y);
        Y.pop_back();
    }
}

void init(int N) {
    int cnt = 0;
    vector<int> Y;
    dfs(N, N, cnt, Y);
    for (int i = 1; i <= N; ++i) X[i].clear();
}

void flood(int a, int &b) {
    z[a] = true;
    ++b;
    for (int i = 0; i < X[a].size(); ++i) {
        if (z[X[a][i]]) continue;
        flood(X[a][i], b);
    }
}

double dp(const vector<int> &Y, int b) {
    if (Y.size() == 1) return 0;
    int a = S[Y];
    if (cz[a][b]) return f[a][b];
    cz[a][b] = true;
    f[a][b] = 0;
    vector<int> Z;
    double sum = 1;
    for (int i = 0; i < Y.size(); ++i) {
        if (i == b) continue;
        Z = Y;
        if (i > b) {
            Z[b] += Z[i]; 
            Z[i] = Z.back();
            Z.pop_back();
        } else {
            Z[i] += Z[b];
            Z[b] = Z.back();
            Z.pop_back();
        }
        sort(Z.begin(), Z.end(), greater<int>());
        for (int j = 0; j < Z.size(); ++j) {
            if (Z[j] == Y[i] + Y[b]) {
                sum += 1.0 * Y[i] / (N - 1) * dp(Z, j);
                break;
            }
        }
    }
    f[a][b] = sum / (1 - 1.0 * (Y[b] - 1) / (N - 1));
    return f[a][b];
}


int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        cin >> N >> M;
        init(N);
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            X[a].push_back(b);
            X[b].push_back(a);
        }

        memset(z, 0, sizeof(z));
        vector<int> Y;
        int s = 0;
        for (int i = 1; i <= N; ++i) {
            if (z[i]) continue;
            int cnt = 0;
            flood(i, cnt);
            Y.push_back(cnt);
            if (i == 1) s = cnt;
        }
        sort(Y.begin(), Y.end(), greater<int>());
        for (int i = 0; i < Y.size(); ++i) {
            if (Y[i] == s) {
                s = i;
                break;
            }
        }
        memset(cz, 0, sizeof(cz));
        cout << fixed << setprecision(8) << "Case " << times << ": " << dp(Y, s) << endl;
    }
    return 0;
}
