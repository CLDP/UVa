#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

const int MAXN = 20010;
const int MAXL = MAXN / 30 + 5;
const int INF = (1 << 30) - 1;

struct node {
    int L;
    int X[MAXL];
};

void NEW(node &A, const int &L) {
    A.L = L;
    memset(A.X, 0, sizeof(A.X));
}

void COPY(node &A, const node &B) {
    A.L = B.L;
    for (int i = 0; i < A.L; ++i) A.X[i] = B.X[i];
}

void OR(const node &A, const node &B, node &C) {
    NEW(C, A.L);
    for (int i = 0; i < A.L; ++i) C.X[i] = A.X[i] | B.X[i];
}

void MV(node &A) {
    for (int i = A.L - 1; i >= 0; --i) {
        if (A.X[i] & (1 << 29)) A.X[i + 1] |= 1;
        A.X[i] = (A.X[i] << 1) & INF;
    }
    A.X[0] |= 1;
}

node OP(node &A, const node &B) {
    node C;
    COPY(C, A);
    for (int i = 0; i < A.L; ++i) {
        if (A.X[i] < B.X[i]) {
            --A.X[i + 1];
            A.X[i] += (1 << 30);
        }
        C.X[i] = ((A.X[i] - B.X[i]) ^ C.X[i]) & C.X[i];
    }
    return C;
}

string X[30];
string P, Q;
node Y[100];
node ans;

void getstring(string &P) {
    int K, a, b;
    string R;
    cin >> K;
    getline(cin, R);
    istringstream RIN(R);
    RIN >> a >> b;
    getline(cin, R);
    P = string(K + 1, ' ');
    --a; --b;
    P[0] = X[a][b];
    for (int i = 0; i < K; ++i) {
        switch (R[i]) {
            case 'W' : --b; break;
            case 'E' : ++b; break;
            case 'N' : --a; break;
            case 'S' : ++a; break;
        }
        P[i + 1] = X[a][b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i) cin >> X[i];
        getstring(P);
        getstring(Q);
        for (int i = 0; i < 100; ++i) Y[i].L = 0;
        for (int i = 0; i < P.size(); ++i) {
            int c = P[i] - 32;
            if (Y[c].L > 0) continue;
            NEW(Y[c], (P.size() + 29) / 30);
            int a = 0, b = 0;
            for (int j = 0; j < P.size(); ++j) {
                if (P[j] == P[i]) Y[c].X[a] |= (1 << b);
                if (++b == 30) {
                    ++a;
                    b = 0;
                }
            }
        }
        NEW(ans, (P.size() + 29) / 30);
        for (int i = 0; i < Q.size(); ++i) {
            int c = Q[i] - 32;
            if (Y[c].L == 0) continue;
            node temp;
            OR(ans, Y[c], temp);
            MV(ans);
            ans = OP(temp, ans);
        }
        int cnt = 0;
        for (int i = 0; i < ans.L; ++i) cnt += __builtin_popcount(ans.X[i]);
        cout << "Case " << times << ": " << P.size() - cnt << " " << Q.size() - cnt << endl;
    }
    return 0;
}
