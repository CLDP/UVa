#include <iostream> 
#include <string>
using namespace std;

int swap(string &a, string &b) {
    string t = a;
    a = b;
    b = t;
}

bool small(string a, string b) {
    string c = a + b, d = b + a;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] < d[i]) return 1;
        if (c[i] > d[i]) return 0;
    }
    return 0;
}


int main() {
    int n;
    string x[60];
    cin >> n;
    while (n) {
        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n - i; ++j) {
                if (small(x[j - 1], x[j])) swap(x[j - 1], x[j]);
            }
        }
        for (int i = 0; i < n; ++i) cout << x[i];
        cout << endl;
        cin >> n;
    }
    return 0;
}
