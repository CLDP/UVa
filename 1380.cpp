#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 210;
const int INF = 1000000007;

struct edge {
    // 0 -- undir,  1 -- in,  2 -- out
    int v, dir;
};

struct event {
    int a, v;
    event() {}
    event(int _a, int _v): a(_a), v(_v) {}
    bool operator < (const event &B) const {
        return v < B.v;
    }
};

int N, ans;
vector<edge> X[MAXN];
bool Z[MAXN];
bool OK;
int IN[MAXN], OUT[MAXN];


bool init(int &root) {
    int a;
    cin >> a;
    root = N = a;
    if (a == 0) return false;
    for (int i = 1; i <= 200; ++i) X[i].clear();
    while (a != 0) {
        string P;
        while (cin >> P) {
            if (P == "0") break;
            edge E;
            E.dir = 0;
            if (isalpha(P.back())) {
                if (P.back() == 'd') E.dir = 2; else E.dir = 1;
                P.pop_back();
            }
            int b = atoi(P.c_str());
            N = max(N, b);
            E.v = b;
            X[a].push_back(E);
            E.v = a;
            if (E.dir != 0) E.dir = 3 - E.dir;
            X[b].push_back(E);
        }
        cin >> a;
    }
    return true;
}

int dfs(int a) {
    int ans = 0;
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i].dir != 2) continue;
        ans = max(ans, dfs(X[a][i].v));
    }
    return ans + 1;
}

int maxS(multiset<int> &S) {
    if (S.empty()) return 0;
    return *S.rbegin();
}

void check(int a, vector<event> &C, multiset<int> &O, int *IN, int *OUT, int preva) {
    if (!OK) return ;
    sort(C.begin(), C.end());
    bool flag = false;
    for (int i = 0; i <= C.size(); ++i) {
        int OO = max(preva, maxS(O) + 1);
        if (IN[a] + OO + 1 > ans) {
            if (i == C.size()) break;
            O.erase(O.find(OUT[C[i].a]));
            IN[a] = max(IN[a], C[i].v + 1);
            continue;
        }
        flag = true;
        break;
    }
    if (!flag) {
        IN[a] = INF;
        return ;
    }
}

void dp(int a) {
    Z[a] = true;
    // chain length, not point length!
    IN[a] = OUT[a] = 0;
    vector<event> C, D;
    multiset<int> I, O;
    for (int i = 0; i < X[a].size(); ++i) {
        if (!Z[X[a][i].v]) {
            dp(X[a][i].v);
            if (X[a][i].dir == 2) OUT[a] = max(OUT[a], OUT[X[a][i].v] + 1);
            if (X[a][i].dir == 1) IN[a] = max(IN[a], IN[X[a][i].v] + 1);
            if (X[a][i].dir == 0) {
                C.push_back(event(X[a][i].v, IN[X[a][i].v]));
                D.push_back(event(X[a][i].v, OUT[X[a][i].v]));
                I.insert(IN[X[a][i].v]);
                O.insert(OUT[X[a][i].v]);
            }
        }
        if (!OK) return ;
    }
    if (IN[a] + OUT[a] + 1 > ans) OK = false;
    if (C.empty()) return ;
    int tempI = IN[a];
    check(a, C, O, IN, OUT, OUT[a]);
    check(a, D, I, OUT, IN, tempI);
    if (IN[a] == INF && OUT[a] == INF) OK = false;
}

int main() {
    while (true) {
        int root;
        if (!init(root)) break;
        ans = 1;
        for (int i = 1; i <= N; ++i) ans = max(dfs(i), ans);
        OK = true;
        memset(Z, 0, sizeof(Z));
        dp(root);
        if (OK) cout << ans << endl; else cout << ans + 1 << endl;
    }
    return 0;
}
