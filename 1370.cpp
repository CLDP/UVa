#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 52;
const int MAXM = 310;

int t1[MAXN], t2[MAXN];
int x[MAXM], y[MAXM];
int f[MAXM][MAXM][2][102];

void update(int &a, int b) {
    if (b == -1) return ;
    if (a == -1 || a > b) a = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> t1[i];
        for (int i = 1; i <= N; ++i) cin >> t2[i];
        int A, B;
        cin >> A >> B;
        for (int i = 1; i <= A; ++i) cin >> x[i];
        for (int i = 1; i <= B; ++i) cin >> y[i];
        memset(f, -1, sizeof(f));
        f[0][0][0][0] = f[0][0][1][0] = 0;
        for (int i = 0; i <= A; ++i) {
            for (int j = 0; j <= B; ++j) {
                if (f[i][j][0][0] != -1 || f[i][j][1][0] != -1) {
                    int temp = -1;
                    update(temp, f[i][j][0][0]);
                    update(temp, f[i][j][1][0]);
                    if (i != A) update(f[i + 1][j][0][t1[x[i + 1]]], temp + t1[x[i + 1]]);
                    if (j != B) update(f[i][j + 1][1][t2[y[j + 1]]], temp + t2[y[j + 1]]);
                }

                for (int k = 1; k <= 100; ++k) {
                    if (f[i][j][0][k] == -1) continue;
                    update(f[i + 1][j][0][t1[x[i + 1]]], f[i][j][0][k] + t1[x[i + 1]]);
                    if (x[i] == y[j + 1]) {
                        update(f[i][j + 1][1][t2[y[j + 1]]], f[i][j][0][k] + t2[y[j + 1]]);
                        continue;
                    } 
                    if (k >= t2[y[j + 1]]) {
                        update(f[i][j + 1][0][k - t2[y[j + 1]]], f[i][j][0][k]);
                    } else {
                        update(f[i][j + 1][1][t2[y[j + 1]] - k], f[i][j][0][k] + t2[y[j + 1]] - k);
                    }
                }

                for (int k = 1; k <= 100; ++k) {
                    if (f[i][j][1][k] == -1) continue;
                    update(f[i][j + 1][1][t2[y[j + 1]]], f[i][j][1][k] + t2[y[j + 1]]);
                    if (x[i + 1] == y[j]) {
                        update(f[i + 1][j][0][t1[x[i + 1]]], f[i][j][1][k] + t1[x[i + 1]]);
                        continue;
                    }
                    if (k >= t1[x[i + 1]]) {
                        update(f[i + 1][j][1][k - t1[x[i + 1]]], f[i][j][1][k]);
                    } else {
                        update(f[i + 1][j][0][t1[x[i + 1]] - k], f[i][j][1][k] + t1[x[i + 1]] - k);
                    }
                }
            }
        }

        int ans = -1;
        for (int i = 0; i <= 100; ++i) {
            update(ans, f[A][B][0][i]);
            update(ans, f[A][B][1][i]);
        }

        cout << ans << endl;
    }

    return 0;
}
