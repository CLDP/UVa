#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1010;

int f[MAXN][26];
int s[26];

void update(int &a, int b) {
    if (a == -1 || a > b) a = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        string P;
        cin >> N >> P;
        memset(f, -1, sizeof(f));
        for (int i = 0; i < 26; ++i) f[0][i] = 1;
        for (int i = 0, k = 0; i < P.size(); i += N, ++k) {
            memset(s, 0, sizeof(s));
            for (int j = i; j < i + N; ++j) ++s[P[j] - 'a'];
            int cnt = 0;
            for (int j = 0; j < 26; ++j) cnt += (s[j] != 0);

            for (int j = 0; j < 26; ++j) {
                if (f[k][j] == -1) continue;
                for (int l = 0; l < 26; ++l) {
                    if (s[l] == 0) continue;
                    if (l == j) {
                        if (cnt == 1) update(f[k + 1][l], f[k][j]);
                    } else {
                        update(f[k + 1][l], f[k][j] + cnt - (s[j] > 0));
                    }
                }
            }
        }
        int ans = MAXN, K = P.size() / N;
        for (int i = 0; i < 26; ++i) {
            if (f[K][i] == -1) continue;
            ans = min(ans, f[K][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
