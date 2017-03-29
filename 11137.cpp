#include <iostream>
using namespace std;

const int MAXN = 10010;
long long f[MAXN];

int main() {
    int n;
    f[0] = 1;
    for (int i = 1; i < 22; ++i) {
        n = i * i * i;
        for (int j = n; j < MAXN; ++j) f[j] += f[j - n];
    }
    while (cin >> n) cout << f[n] << endl;
    return 0;
}
