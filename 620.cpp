#include <iostream>
#include <string>
using namespace std;

string P;

int check(int a, int b) {
    if (a > b) return 0;
    if (a == b) return P[a] == 'A' ? 1 : 0;
    if (P[b - 1] == 'A' && P[b] == 'B') {
        if (a + 1 == b) return 0;
        if (check(a, b - 2)) return 2;
    }
    if (P[a] == 'B' && P[b] == 'A') {
        if (a + 1 == b) return 0;
        if (check(a + 1, b - 1)) return 3;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> P;
        switch (check(0, P.size() - 1)) {
            case 0: cout << "MUTANT" << endl; break;
            case 1: cout << "SIMPLE" << endl; break;
            case 2: cout << "FULLY-GROWN" << endl; break;
            case 3: cout << "MUTAGENIC" << endl; break;
        }
    }
    return 0;
}
