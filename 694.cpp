#include <iostream>
using namespace std;

int main() {
    long long a, b, n = 0, ans;
    cin >> a >> b;
    while (a > -1) {
        n = n + 1;
        cout << "Case " << n << ": A = " << a << ", limit = " 
             << b << ", number of terms = ";
        ans = 0;
        while (a != 1 && a <= b) {
            if (a % 2) a = a * 3 + 1; else a = a / 2;
            ++ans;
        }
        if (a == 1) ++ans;
        cout << ans << endl;
        cin >> a >> b;      
    }
    return 0;
}
