#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x[4], t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) cin >> x[j];
        for (int k = 0; k < 3; ++k) {
            for (int j = 1; j < 4; ++j) {
                if (x[j - 1] > x[j]) swap(x[j - 1], x[j]);
            }
        }
        if (x[0] == x[3]) {
            cout << "square" << endl;
            continue;
        }
        if (x[0] == x[1] && x[2] == x[3]) {
            cout << "rectangle" << endl;
            continue;
        }
        if (x[0] + x[1] + x[2] > x[3]) {
            cout << "quadrangle" << endl;
            continue;
        }
        cout << "banana" << endl;
    }
    return 0;
}
