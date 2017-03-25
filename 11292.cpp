#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20010;

int X[MAXN], Y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N >> M) {
        if (N + M == 0) break;
        for (int i = 0; i < N; ++i) cin >> X[i];
        for (int i = 0; i < M; ++i) cin >> Y[i];
        sort(X, X + N);
        sort(Y, Y + M); 
        int j = 0, ans = 0;
        bool flag = true;
        for (int i = 0; i < N; ++i) {
            while (j < M && Y[j] < X[i]) ++j;
            if (j == M) {
                flag = false;
                break;
            }
            ans += Y[j++];
        }
        if (flag) cout << ans << endl; else cout << "Loowater is doomed!" << endl;
    }
    return 0;
}
