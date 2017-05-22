#include <iostream>
using namespace std;

int main() {
    int N, K, M;
    while (cin >> N >> K >> M) {
        if (N == 0) break;
        int a = 0;
        for (int i = 2; i <= N; ++i) a = ((a + K) % i + i) % i;
        a = ((a - K + M) % N + N) % N;
        cout << a + 1 << endl;
    }
    return 0;
}

