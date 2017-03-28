#include <iostream>
using namespace std;


int main() {
    int n, m, t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        while (m) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 0; k < j; ++k) cout << j;
                cout << endl;
            }
            for (int j = n-1; j > 0; --j) {
                for (int k = 0; k < j; ++k) cout << j;
                if (i < t-1 || m > 1 || j > 1) cout << endl;
            }
            cout << endl;
            --m;
        }
    }
    return 0;
}
