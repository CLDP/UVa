#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1010;
const int MAXM = 10;
int x[MAXN], y[MAXN];
int xx[MAXM], yy[MAXM];

int get(const int n, int &a, int &b) {
    a = 0; b = 0;
    for (int i = 0; i < n; ++i) 
        if (x[i] == y[i]) ++a;
    for (int i = 1; i < MAXM; ++i) 
        if (yy[i] > xx[i]) b += xx[i]; else b += yy[i];
    b -= a;
    return 0;
}


int main() {
    int n, m = 0, a, b;
    cin >> n;
    while (n) {
        ++m;
        cout << "Game " << m << ":" << endl;
        memset(xx, 0, sizeof(xx));
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            ++xx[x[i]];
        }
        memset(yy, 0, sizeof(yy));
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
            ++yy[y[i]];
        }
        while (y[0]) {
            get(n, a, b);
            cout << "    (" << a << "," << b << ")" << endl;
            memset(yy, 0, sizeof(yy));
            for (int i = 0; i < n; ++i) {
                cin >> y[i];
                ++yy[y[i]];
            }
        }
        cin >> n;      
    }
    return 0;
}
