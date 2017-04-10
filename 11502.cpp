#include <iostream>
#include <cmath>
using namespace std;

const int MAXM = 10001;
const double G = 9.8;

double f[MAXM];


int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i < MAXM; ++i) f[i] = -1e100;
        for (int i = 1; i <= N; ++i) {
            int s, l, t, c;
            cin >> s >> l >> t >> c;
            for (int j = MAXM - s - l - 1; j >= 0; --j) {
                int total = j + s + l;
                if (t / total < G) continue;
                double time = 1.0 * l / c;
                double acc = t * (log(total) - log(j + s)) / c - time * G;
                f[total] = max(f[total], acc + f[j]);
            }
        }
        double ans = 0;
        for (int i = 0; i < MAXM; ++i) ans = max(ans, f[i]);
        cout << round(ans) << endl;
    }
    return 0;
}
