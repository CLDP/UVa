#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int MAXM = 250010;
const int INF = 1000000007;
const int KM[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

struct node {
    string X;
    long long XX;

    bool operator < (const node &B) const {
        return XX < B.XX;
    }
};

node X[MAXN];
int Y[MAXN];
string Z[MAXN];
int f[MAXM];
// number string to position, if directly
unordered_map<long long, int> C;
// alpha string to position, all
unordered_map<string, int> S;

void update(int &temp, int &cnt, string &Q, const int &i, string UD) {
    ++cnt;
    if (Y[i] > temp + cnt) {
        Y[i] = temp + cnt;
        Z[i] = Q + UD + "(" + to_string(cnt) + ")";
    } else {
        temp = Y[i];
        Q = Z[i];
        cnt = 0;
    }
}

void dp(int N) {
    int l = 0;
    while (l != N) {
        int r = l;
        while (X[r].XX == X[l].XX) ++r;
        int temp = Y[l], cnt = 0;
        string Q = Z[l];
        for (int i = l + 1; i < r; ++i) update(temp, cnt, Q, i, "U");
        for (int i = l; i < r; ++i) update(temp, cnt, Q, i, "U");
        temp = Y[r - 1], cnt = 0;
        Q = Z[r - 1];
        for (int i = r - 2; i >= l; --i) update(temp, cnt, Q, i, "D");
        for (int i = r - 1; i >= l; --i) update(temp, cnt, Q, i, "D");
        l = r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N) {
        if (N == 0) break;
        C.clear();
        S.clear();

        for (int i = 0; i < N; ++i) {
            cin >> X[i].X;
            X[i].XX = 0;
            for (int j = 0; j < X[i].X.size(); ++j) X[i].XX = X[i].XX * 10 + KM[X[i].X[j] - 'a'];
        }
        stable_sort(X, X + N);

        X[N].XX = -1;
        for (int i = 0; i < N; ++i) {
            Y[i] = MAXN;
            S[X[i].X] = i;

            if (C.find(X[i].XX) == C.end()) {
                C[X[i].XX] = i;
                Y[i] = X[i].X.size();
                Z[i] = "";
                for (int j = 0; j < X[i].X.size(); ++j) Z[i] = Z[i] + to_string(KM[X[i].X[j] - 'a']);
            }
        }

        dp(N);

        cin >> M;
        while (M--) {
            string Q;
            cin >> Q;

            for (int i = 0; i < Q.size(); ++i) f[i + 1] = INF;
            f[0] = 0;
            for (int i = 0; i < Q.size(); ++i) {
                string R = "";
                for (int j = i; j < min((int)Q.size(), i + 10); ++j) {
                    R.push_back(Q[j]);
                    if (S.find(R) == S.end()) continue;
                    f[j + 1] = min(f[j + 1], f[i] + Y[S[R]] + 1);
                }
            }

            vector<string> ans;

            int j = Q.size();
            while (j != 0) {
                for (int i = j - 1; i >= max(j - 10, 0); --i) {
                    string R = Q.substr(i, j - i);
                    if (S.find(R) == S.end()) continue;
                    if (f[j] == f[i] + Y[S[R]] + 1) {
                        ans.push_back(Z[S[R]]);
                        j = i;
                        break;
                    }
                }
            }
            for (int i = ans.size() - 1; i >= 0; --i) {
                cout << ans[i];
                if (i != 0) cout << "R"; else cout << endl;
            }
        }
    }

    return 0;
}
