#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 10;
const int MAXM = 101;
const int MAXB = 12880;
const double EPS = 1e-8;

int Y[MAXB];
int Z[50000000];
vector<int> KM;

int M, N, K, MM;
string name[MAXN];
int A[MAXN], B[MAXN];
double X[MAXN][MAXM];
double f[MAXM][MAXB];
int g[MAXM][MAXB], h[MAXM][MAXB];

void dfs(int a, int n, int temp) {
    if (a == 8) {
        Z[temp] = MM;
        Y[MM++] = temp;
        return ;
    }
    for (int i = 0; i <= n; ++i) dfs(a + 1, n - i, temp + i * KM[a]);
}

void update(int a, int b, int c, int d, int e, double T) {
    if (f[a][b] < f[c][d] + T) {
        f[a][b] = f[c][d] + T;
        g[a][b] = d;
        h[a][b] = e;
    }
}

void decomp(int temp, vector<int> &T) {
    for (int k = 0; k < N; ++k) {
        T.push_back(temp % 9);
        temp /= 9;
    }
}

void output(int a, int b) {
    cout << fixed << setprecision(2) << f[a][b] << endl;
    vector<string> ansT;
    while (a > 0) {
        if (h[a][b] == 0) {
            ansT.push_back("HOLD");
        } else 
        if (h[a][b] > 0) {
            ansT.push_back("SELL " + name[h[a][b] - 1]);
        } else {
            ansT.push_back("BUY " + name[-h[a][b] - 1]);
        }
        b = g[a][b];
        --a;
    }
    for (int i = M - 1; i >= 0; --i) cout << ansT[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    KM.push_back(1);
    for (int i = 1; i < 8; ++i) KM.push_back(KM.back() * 9);
    dfs(0, 8, 0);

    bool flag = false;
    double C;
    while (cin >> C >> M >> N >> K) {
        if (flag) cout << endl;
        flag = true;
        for (int i = 0; i < N; ++i) {
            cin >> name[i] >> A[i] >> B[i];
            for (int j = 0; j < M; ++j) {
                cin >> X[i][j];
                X[i][j] *= A[i];
            }
        }
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j < MM; ++j) f[i][j] = -1;
        }
        f[0][0] = C;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < MM; ++j) {
                if (f[i][j] < -EPS) continue;
                vector<int> T;
                decomp(Y[j], T);

                int sum = 0;
                for (int k = 0; k < N; ++k) sum += T[k];
                update(i + 1, j, i, j, 0, 0);
                for (int k = 0; k < N; ++k) {
                    if (T[k] == 0) continue; 
                    update(i + 1, Z[Y[j] - KM[k]], i, j, k + 1, X[k][i]);
                }
                if (sum == K) continue;
                for (int k = 0; k < N; ++k) {
                    if (T[k] == B[k] || f[i][j] < X[k][i] - EPS) continue;
                    update(i + 1, Z[Y[j] + KM[k]], i, j, -k - 1, -X[k][i]);
                }
            }
        }
        output(M, 0);
    }
    return 0;
}
