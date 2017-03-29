#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 21;
const int MAXM = 100000;

int x[MAXN];
int g[MAXM];
bool f[MAXM];

int main() {
    int N, M;
    while (cin >> M) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> x[i];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));

        f[0] = true;
        for (int i = 0; i < N; ++i) {
            for (int j = M - x[i]; j >= 0; --j) {
                if (!f[j] || f[j + x[i]]) continue;
                f[j + x[i]] = true;
                g[j + x[i]] = x[i];
            }
        }
        while (!f[M]) --M;
        int ans = M;
        vector<int> ansT;
        while (M != 0) {
            ansT.push_back(g[M]);
            M -= g[M];
        }
        for (int i = (int)ansT.size() - 1; i >= 0; --i) cout << ansT[i] << " ";
        cout << "sum:" << ans << endl;
    }

    return 0;
}
