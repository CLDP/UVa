#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5010;

int X[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) cin >> X[i];
        X[N] = 2000000;
        sort(X, X + N);
        int ans = 1;
        for (int i = 0; i + 1 < N; ++i) {
            if (X[i] + K < X[i + 1]) continue;
            int A = X[i], B = X[i + 1], j = i + 2;
            while (j < N) {
                if (A + K < X[j]) break;
                A = B;
                B = X[j];
                ++j;
            }
            ans = max(ans, j - i);
        }
        cout << ans << endl;
    }
    return 0;
}
