#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

pair<int, int> X[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, times = 0;
    while (cin >> N) {
        if (N == 0) break;
        for (int i = 0; i < N; ++i) cin >> X[i].second >> X[i].first;
        sort(X, X + N, greater<pair<int, int> >());
        int ans = 0, cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += X[i].second;
            ans = max(ans, cnt + X[i].first);
        }
        cout << "Case " << ++times << ": " << ans << endl;
    }
    return 0;
}
