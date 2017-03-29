#include <iostream>
using namespace std;

int x[5], y[5];
bool z[5];
bool flag;

int dfs2(int a, int b) {
    if (a == 5) {
        if (b == 23) flag = true;
    } else {
        dfs2(a + 1, b + y[a]);
        dfs2(a + 1, b - y[a]);
        dfs2(a + 1, b * y[a]);
    }
}

int dfs1(int a) {
    if (a == 5) {
         dfs2(1, y[0]);
    } else
    for (int i = 0; i < 5; ++i) {
        if (!z[i]) {
            z[i] = true;
            y[a] = x[i];
            dfs1(a + 1);
            z[i] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 5; ++i) cin >> x[i];
    while (x[0] || x[1] || x[2] || x[3] || x[4]) {
        flag = false;
        dfs1(0);
        if (flag) cout << "Possible"; else cout << "Impossible";
        cout << endl;
        for (int i = 0; i < 5; ++i) cin >> x[i];
    }
    return 0;
}
