#include <iostream>
using namespace std;

int main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        int a, b, c;
        if (K % 3 == 0) {
            a = 2;
            if (K % 2 == 0) b = 1, c = 0; else b = 0, c = 1;
        } 
        if (K % 3 == 1) {
            a = 0;
            if (K % 2 == 0) b = 2, c = 1; else b = 1, c = 2;
        }
        if (K % 3 == 2) {
            a = 1;
            if (K % 2 == 0) b = 0, c = 2; else b = 2, c = 0;
        }
        for (int i = 4; i <= N; ++i) {
            a = ((a + K) % i + i) % i;
            b = ((b + K) % i + i) % i;
            c = ((c + K) % i + i) % i;
        }
        cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    }
    return 0;
}

