#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 510;

int X[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> X[i];
        sort(X, X + N);
        int ans = 40000 * 501;
        for (int i = 0; i < N; ++i) {
            int temp = 0;
            for (int j = 0; j < N; ++j) temp += abs(X[i] - X[j]);
            ans = min(ans, temp);
        }
        cout << ans << endl;
    }
    return 0;
}
