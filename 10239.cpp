#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 1010;
const double EPS = 1e-8;

double h[MAXN], w[MAXN];
double f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    double W;
    while (cin >> N >> W) {
        if (N == 0) break;
        for (int i = 1; i <= N; ++i) cin >> h[i] >> w[i];
        f[0] = 0;
        for (int i = 1; i <= N; ++i) {
            double temp = W, dh = 0;
            f[i] = 1e10;
            for (int j = i; j >= 1; --j) {
                temp -= w[j];
                if (temp < -EPS) break;
                dh = max(dh, h[j]);
                f[i] = min(f[i], f[j - 1] + dh);
            }
        }
        cout << fixed << setprecision(4) << f[N] << endl;
    }
    return 0;
}
