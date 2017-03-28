#include <iostream>
using namespace std;

int main() {
    int n, m;
    int a, b, c, ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        ans = 0;
        for (int j = 0; j < m; ++j) {
            cin >> a >> b >> c;
            ans += a * c;
        }
        cout << ans << endl;
    }
    return 0;
}
