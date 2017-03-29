#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500010;

struct node {
    int a, b;
    bool operator < (const node &B) const {
        if (a != B.a) return a < B.a;
        return b < B.b;
    }
};

node X[MAXN], Y[MAXN];

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        for (int i = 0; i < N; ++i) {
            cin >> X[i].a >> X[i].b;
            Y[i].a = X[i].b;
            Y[i].b = X[i].a;
        }
        sort(X, X + N);
        sort(Y, Y + N);
        bool flag = true;
        for (int i = 0; i < N; ++i) {
            flag &= (X[i].a == Y[i].a && Y[i].b == X[i].b);
            if (!flag) break;
        }
        if (flag) cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
}
