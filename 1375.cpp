#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const int MAXN = 650;
const int MAXL = 22;
const string INF = "~";

vector<pair<int, int> > X[MAXN];
string f[MAXN][MAXL];
bool z[MAXN][MAXL];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N >> M) {
        if (N + M == 0) break;
        for (int i = 0; i < MAXN; ++i) X[i].clear();
        int K = 130;
        for (int i = 0; i < N; ++i) {
            string P;
            cin >> P;
            if (P.size() == 2) {
                X[P[0]].push_back(make_pair(0, 0));
            } else 
            if (P.size() == 3) {
                X[P[0]].push_back(make_pair(P[2], 0));
            } else 
            if (P.size() == 4) {
                X[P[0]].push_back(make_pair(P[2], P[3]));
            } else {
                X[P[0]].push_back(make_pair(P[2], ++K));
                for (int j = 3; j + 2 < P.size(); ++j) {
                    X[K].push_back(make_pair(P[j], K + 1));
                    ++K;
                }
                X[K].push_back(make_pair(P[P.size() - 2], P[P.size() - 1]));
            }
        }
        for (int i = 0; i <= K; ++i) {
            for (int j = 0; j <= M; ++j) f[i][j] = INF;
        }
        memset(z, 0, sizeof(z));

        z[0][0] = true;
        f[0][0] = "";
        for (int i = 'A'; i <= 'Z'; ++i) {
            for (int j = 0; j < X[i].size(); ++j) {
                if (X[i][j].first + X[i][j].second == 0) {
                    f[i][0] = "";
                    z[i][0] = true;
                }
            }
        }

        for (int i = 'a'; i <= 'z'; ++i) {
            f[i][1] = (char)(i);
            z[i][1] = true;
        }

        for (int j = 0; j <= M; ++j) {
            set<pair<string, int> > S;
            for (int i = 'A'; i <= K; ++i) {
                for (int k = 1; k < j; ++k) {
                    for (int l = 0; l < X[i].size(); ++l) {
                        if (z[X[i][l].first][k] && z[X[i][l].second][j - k]) {
                            f[i][j] = min(f[i][j], f[X[i][l].first][k] + f[X[i][l].second][j - k]);
                            z[i][j] = true;
                        }
                    }
                }
                if (z[i][j]) S.insert(make_pair(f[i][j], i));
            }

            bool cz[MAXN];
            memset(cz, 0, sizeof(cz));

            while (!S.empty()) {
                int a = S.begin()->second;
                S.erase(S.begin());
                if (cz[a]) continue;
                cz[a] = z[a][j] = true;

                for (int i = 'A'; i <= K; ++i) {
                    if (cz[i]) continue;
                    for (int l = 0; l < X[i].size(); ++l) {
                        if (X[i][l].first != a && X[i][l].second != a) continue;
                        if (X[i][l].first == a && z[X[i][l].second][0]) f[i][j] = f[a][j];
                        if (X[i][l].second == a && z[X[i][l].first][0]) f[i][j] = f[a][j];
                        if (f[i][j] == f[a][j]) S.insert(make_pair(f[i][j], i));
                    }
                }
            }
        }

        if (!z['S'][M]) {
            cout << "-" << endl;
        } else {
            cout << f['S'][M] << endl;
        }
    }
    return 0;
}
