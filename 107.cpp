#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        int k = 1, ans1 = 1, ans2 = a + b;
        if (!a && !b) break;
        if (a == b && b == 1) {
            cout << "0 1" << endl;
            continue;
        }
        while (a != int(pow(1.0 + pow(b, 1.0 / k), k) + 0.1)) ++k;

        int n = int(pow(b, 1.0 / k) + 0.1);
        for (int i = 1; i < k; ++i) {
            ans1 += int(pow(n * 1.0, i));
            ans2 += int(pow(n * 1.0, i) / pow(n + 1.0, i) * a + 0.1);
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
