#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    vector<vector<int> > X;
    vector<int> Z(3, 0);
    int a, b, c;
    while (cin >> a >> c >> b) {
        Z[0] = a;
        Z[1] = -1;
        Z[2] = -c;
        X.push_back(Z);
        Z[0] = b;
        Z[1] = 1;
        Z[2] = c;
        X.push_back(Z);
    }
    sort(X.begin(), X.end());
    
    bool first = true;
    multiset<int> S;
    S.insert(0);
    for (int i = 0; i < X.size(); ++i) {
        if (X[i][1] == -1) {
            if (S.empty() || *S.rbegin() < -X[i][2]) {
                if (!first) cout << " ";
                first = false;
                cout << X[i][0] << " " << -X[i][2];
            }
            S.insert(-X[i][2]);
        } else {
            S.erase(S.find(X[i][2]));
            if (*S.rbegin() < X[i][2]) cout << " " << X[i][0] << " " << *S.rbegin();
        }
    }
    cout << endl;

    return 0;
}
