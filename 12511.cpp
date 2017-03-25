#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1002;
const int INF = 1000000007;

int X[MAXN], Y[MAXN];
int f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, M, ans = 0;
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> X[i];
        cin >> M;
        for (int j = 1; j <= M; ++j) cin >> Y[j];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= N; ++i) {
            int temp = 0;
            for (int j = 1; j <= M; ++j) {
                if (X[i] == Y[j]) f[j] = max(f[j], temp + 1);
                if (Y[j] < X[i] && f[j] > temp) temp = f[j];
                ans = max(ans, f[j]);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
