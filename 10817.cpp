#include <iostream>
#include <cstring>
#include <set>
#include <sstream>
using namespace std;

int f[1 << 16], g[1 << 16];

void update(int &a, int b) {
    if (a == -1 || a > b) a = b;
}

int cal(int a, set<int> &X) {
    for (auto i = X.begin(); i != X.end(); ++i) {
        if ((a >> (*i + *i)) % 4 == 2) continue;
        a += (1 << (*i + *i));
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, M, N;
    while (cin >> T >> M >> N) {
        if (T + M + N == 0) break;
        memset(f, -1, sizeof(f));
        memset(g, -1, sizeof(g));
        string Q;
        getline(cin, Q);
        int ans = 0, state = 0;
        for (int i = 0; i < M; ++i) {
            getline(cin, Q);
            istringstream QIN(Q);
            int a;
            QIN >> a;
            ans += a;
            while (QIN >> a) {
                --a;
                int b = (state >> (a + a)) % 4;
                if (b == 2) continue;
                state += (1 << (a + a));
            }
        }

        f[state] = ans;
        g[state] = ans;
        set<int> S;
        S.insert(state);
        for (int i = 0; i < N; ++i) {
            getline(cin, Q);
            istringstream QIN(Q);
            int cost;
            QIN >> cost;
            set<int> X;
            int a;
            while (QIN >> a) X.insert(a - 1);
            set<int> NS;
            for (auto iter = S.begin(); iter != S.end(); ++iter) {
                int val = cal(*iter, X);
                if (S.find(val) == S.end()) NS.insert(val);
                update(g[val], f[*iter] + cost);
            }
            for (auto iter = NS.begin(); iter != NS.end(); ++iter) S.insert(*iter);
            for (auto iter = S.begin(); iter != S.end(); ++iter) f[*iter] = g[*iter];
        }

        state = 0;
        for (int i = 0; i < T; ++i) state += (1 << (i + i + 1));
        cout << f[state] << endl;
    }

    return 0;
}
