#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
string x[MAXN];

int Compare(string a, string b) {
    for (int i = 0; i < min(a.size(), b.size()); ++i) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }   
    if (a.size() < b.size()) return -1;
    if (a.size() > b.size()) return 1;
    return 0;   
}

int main() {
    int n, ans;
    char p[100];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        gets(p);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n - i; ++j) {
            if (Compare(x[j - 1], x[j]) == 1) swap(x[j - 1], x[j]);
        }
    }
    ans = 0;
    cout << x[0] << " ";
    for (int i = 1; i < n; ++i) {
        ++ans;
        if (x[i] != x[i - 1]) {
            cout << ans << endl << x[i] << " ";
            ans = 0;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
