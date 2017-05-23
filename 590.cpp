#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x[11][11];
int f[1010][11];

void update(int &a, int b) {
    if (a == -1 || a > b) a = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, K, times = 0;
    while (cin >> N >> K) {
        if (N + K == 0) break;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                x[i][j].clear();
                int M;
                cin >> M;
                for (int k = 0; k < M; ++k) {
                    int a;
                    cin >> a;
                    x[i][j].push_back(a);
                }
            }
        }

        memset(f, -1, sizeof(f));
        f[0][0] = 0;
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < N; ++j) {
                if (f[i][j] == -1) continue;
                for (int k = 0; k < N; ++k) {
                    if (j == k) continue;
                    if (x[j][k][i % (int)x[j][k].size()] == 0) continue;
                    update(f[i + 1][k], f[i][j] + x[j][k][i % (int)x[j][k].size()]);
                }
            }
        }
    
        cout << "Scenario #" << ++times << endl;
        if (f[K][N - 1] != -1) 
            cout << "The best flight costs " << f[K][N - 1] << "." << endl;
        else 
            cout << "No flight possible." << endl;
        cout << endl;
    }
    return 0;
}
