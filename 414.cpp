#include <string>
#include <iostream>
using namespace std;

const int MAXM = 30;
const int MAXN = 1000;
char p[MAXM];
int x[MAXN];

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        int temp = 25;
        string P;
        getline(cin, P);
        for (int i = 0; i < N; ++i) {
            getline(cin, P);
            int cnt = 0;
            for (int j = 0; j < 25; ++j) {
                if (P[j] == ' ') ++cnt;
            }
            x[i] = cnt;
            temp = min(temp, cnt);
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) ans += x[i] - temp;
        cout << ans << endl;
    }
    return 0;
}
