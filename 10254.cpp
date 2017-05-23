#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10010;
const int MAXL = 100;

struct HP {
    int L;
    int x[MAXL];

    HP() {}
    HP(int a) {
        memset(x, 0, sizeof(x));
        L = 1;
        x[0] = 1;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < L; ++j) x[j] += x[j];
            for (int j = 0; j < L; ++j) {
                if (x[j] > 9) {
                    x[j + 1] += x[j] / 10;
                    x[j] %= 10;
                }
            }
            if (x[L] > 0) ++L;
        }
    }

    void dec() {
        --x[0];
        for (int i = 0; i < L; ++i) {
            if (x[i] < 0) {
                x[i] += 10;
                --x[i + 1];
            } else {
                break;
            }
        }
        while (L > 1 && x[L - 1] == 0) --L;
    }

    void add(const HP &B) {
        L = max(L, B.L);
        for (int i = 0; i < L; ++i) {
            x[i] += B.x[i];
            x[i + 1] += x[i] / 10;
            x[i] %= 10;
        }
        if (x[L] > 0) ++L;
    }

    bool operator < (const HP &B) {
        if (L < B.L) return true;
        if (L > B.L) return false;
        for (int i = L - 1; i >= 0; --i) {
            if (x[i] < B.x[i]) return true;
            if (x[i] > B.x[i]) return false;
        }
        return false;
    }
};

HP f[MAXN];

int main() {
    f[0].L = 1;
    f[1] = HP(0);
    
    int k = 1;
    for (int i = 2; i <= 10000; ++i) {
        f[i].L = MAXL;
        for (int j = k; j < i; ++j) {
            HP temp = f[j];
            temp.add(f[j]);
            temp.add(HP(i - j));
            temp.dec();
            if (temp < f[i]) {
                f[i] = temp;
                k = j;
            } else {
                break;
            }
        }
    }
    int N;
    while (cin >> N) {
        for (int i = f[N].L - 1; i >= 0; --i) cout << f[N].x[i];
        cout << endl;
    }

    return 0;
}
