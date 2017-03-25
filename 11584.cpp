#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int f[MAXN];
vector<int> X[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string P;
        cin >> P;
        int N = P.size();
        for (int j = 0; j <= N; ++j) X[j].clear();
        for (int j = 0; j < N; ++j) {
            X[j + 1].push_back(j);
            int k = 1;
            while (j - k >= 0 && j + k < N && P[j - k] == P[j + k]) {
                X[j + k + 1].push_back(j - k);
                ++k;
            }
            k = 1;
            if (j > 0 && P[j] == P[j - 1]) X[j + 1].push_back(j - 1);
            while (j - k - 1 >= 0 && j + k < N && P[j - k - 1] == P[j + k]) {
                X[j + k + 1].push_back(j - k - 1);
                ++k;
            }
        }

        f[0] = 0;
        for (int j = 1; j <= N; ++j) {
            f[j] = MAXN;
            for (int k = 0; k < X[j].size(); ++k) f[j] = min(f[j], f[X[j][k]] + 1);
        }
        cout << f[N] << endl;
    }
    return 0;
}
