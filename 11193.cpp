#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 510;
const int INF = 1000000007;

int w[4], f[MAXN][MAXN];
string P;

int dp(const vector<int> &x, const vector<bool> &y, int *w) {
    int N = x.size();
    for (int i = 0; i < N; ++i) f[i][1] = x[i];
    for (int l = 2; l <= N; ++l) {
        for (int i = 0; i + l <= N; ++i) {
            int &ans = f[i][l];
            ans = INF;
            if (!y[i]) continue;
            for (int j = 1; j < l; ++j) {
                if (y[i + j]) {
                    ans = min(ans, max(f[i][j], f[i + j][l - j]) + w[0]);
                } else {
                    ans = min(ans, max(f[i][j], f[i + j][l - j]) + w[1]);
                }
            }
        }
    }
    return f[0][N];
}

int parse(int &a);
// multiply, divide
int solvemd(int &a);
// add, subtract
int solveas(int &a);


int main() {
    ios_base::sync_with_stdio(false);
    while (true) {
        for (int i = 0; i < 4; ++i) cin >> w[i];
        if (w[0] + w[1] + w[2] + w[3] == 0) break;
        cin >> P;
        int a = 0;
        cout << solveas(a) << endl;
    }
    return 0;
}


int parse(int &a) {
    if (P[a] == '(') {
        ++a;
        int ans = solveas(a);
        ++a;
        return ans;
    } 
    while (isdigit(P[a])) ++a;
    return 0;
}

int solvemd(int &a) {
    vector<int> x;
    vector<bool> y;
    x.push_back(parse(a));
    y.push_back(true);
    while (a < P.size() && (P[a] == '*' || P[a] == '/')) {
        y.push_back(P[a] == '*');
        ++a;
        x.push_back(parse(a));
    }
    return dp(x, y, w + 2);
}


int solveas(int &a) {
    vector<int> x;
    vector<bool> y;
    x.push_back(solvemd(a));
    y.push_back(true);
    while (a < P.size() && (P[a] == '+' || P[a] == '-')) {
        y.push_back(P[a] == '+');
        ++a;
        x.push_back(solvemd(a));
    }
    return dp(x, y, w);
}
