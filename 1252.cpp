#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 130;

int M, N;
string x[MAXN];
int f[180000];

int dp(int a) {
    if (f[a] != -1) return f[a];
    f[a] = M;
    vector<int> S;
    int b = a;
    for (int i = 0; i < M; ++i) {
        S.push_back(b % 3);
        b /= 3;
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        bool flag = true;
        for (int j = 0; j < M; ++j) {
            if (S[j] == 2) continue;
            if (S[j] == 1 && x[i][j] == '0') flag = false;
            if (S[j] == 0 && x[i][j] == '1') flag = false;
        }
        cnt += flag;
    }
    if (cnt == 1) return f[a] = 0;

    for (int i = 0; i < M; ++i) {
        if (S[i] != 2) continue;
        int A = 0, B = 0;
        S[i] = 0;
        for (int j = S.size() - 1; j >= 0; --j) A = A * 3 + S[j];
        S[i] = 1;
        for (int j = S.size() - 1; j >= 0; --j) B = B * 3 + S[j];
        f[a] = min(f[a], max(dp(A), dp(B)) + 1);
        S[i] = 2;
    }
    return f[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> M >> N) {
        if (N + M == 0) break;
        for (int i = 0; i < N; ++i) cin >> x[i];
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        memset(f, -1, sizeof(f));
        int s = 0;
        for (int i = 0; i < M; ++i) s = s * 3 + 2;
        cout << dp(s) << endl;
    }

    return 0;
}
