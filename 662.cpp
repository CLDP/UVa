#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 202;
const int MAXK = 32;
const int INF = 1000000000;

struct node {
    int a, b, c;
};

int x[MAXN];
int w[MAXN][MAXN];
int f[MAXN][MAXK];
int p[MAXN][MAXK], q[MAXN][MAXK], r[MAXN][MAXK];

int main() {
    ios_base::sync_with_stdio(false);
    int N, K, times = 0;
    while (cin >> N >> K) {
        if (N + K == 0) break;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= N; ++i) cin >> x[i];
        for (int i = 1; i <= N; ++i) {
            for (int j = i; j <= N; ++j) {
                int p = (i + j) / 2;
                w[i][j] = 0;
                for (int k = i; k <= j; ++k) w[i][j] += abs(x[p] - x[k]);
            }
        }

        for (int i = 1; i <= N; ++i) {
            f[i][1] = w[1][i];
            p[i][1] = 0;
            q[i][1] = 0;
            r[i][1] = (1 + i) / 2;
            for (int j = 2; j <= K; ++j) {
                if (j > i) break;
                f[i][j] = INF;
                for (int k = j; k <= i; ++k) {
                    if (f[i][j] > f[k - 1][j - 1] + w[k][i]) {
                        f[i][j] = f[k - 1][j - 1] + w[k][i];
                        p[i][j] = k - 1;
                        q[i][j] = j - 1;
                        r[i][j] = (k + i) / 2;
                    }
                }
            }
        }


        cout << "Chain " << ++times << endl;

        int NN = N, KK = K;
        vector<node> ans;
        while (N != 0) {
            node Q;
            Q.a = r[N][K];
            Q.b = p[N][K] + 1;
            Q.c = N;
            K = q[N][K];
            N = Q.b - 1;
            ans.push_back(Q);
        } 
        for (int i = ans.size() - 1; i >= 0; --i) {
            cout << "Depot " << KK - i << " at restaurant " << ans[i].a << " serves restaurant";
            if (ans[i].b == ans[i].c) {
                cout << " " << ans[i].b << endl;
            } else {
                cout << "s " << ans[i].b << " to " << ans[i].c << endl;
            }
        }

        cout << "Total distance sum = " << f[NN][KK] << endl;
        cout << endl;
    }

    return 0;
}
