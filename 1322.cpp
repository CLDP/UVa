#include <iostream>
using namespace std;

const int MAXN = 200000;
const int INF = 1000000000;

int x[MAXN], mx[MAXN];
int y[MAXN];

void build(int t, int l, int r) {
    y[t] = INF;
    if (l == r) {
        if (l == 1) x[t] = 0; else x[t] = INF;
        mx[t] = x[t];
        return ;
    }
    int mid = (l + r) / 2;
    build(t + t, l, mid);
    build(t + t + 1, mid + 1, r);
    mx[t] = min(mx[t + t], mx[t + t + 1]);
}

void clear(int t) {
    y[t + t] = min(y[t + t], y[t]);
    y[t + t + 1] = min(y[t + t + 1], y[t]);
    y[t] = INF;
}

int query(int t, int l, int r, int a) {
    if (l == r) {
        mx[t] = x[t] = min(x[t], y[t]);
        y[t] = INF;
        return x[t];
    }

    if (y[t] != INF) clear(t);

    int mid = (l + r) / 2, ans;
    if (a <= mid) ans = query(t + t, l, mid, a); else ans = query(t + t + 1, mid + 1, r, a);
    mx[t] = min(min(mx[t + t], mx[t + t + 1]), min(y[t + t], y[t + t + 1]));
    return ans;
}

void insert(int t, int l, int r, int a, int b, int c) {
    if (l == r) {
        mx[t] = x[t] = min(c, min(x[t], y[t]));
        y[t] = INF;
        return ;
    }
    if (y[t] != INF) clear(t);
    if (a <= l && r <= b) {
        y[t] = c;
        return ;
    }
    int mid = (l + r) / 2;
    if (a <= mid) insert(t + t, l, mid, a, b, c); 
    if (mid < b) insert(t + t + 1, mid + 1, r, a, b, c);
    mx[t] = min(min(mx[t + t], mx[t + t + 1]), min(y[t + t], y[t + t + 1]));
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        build(1, 1, N);
        while (M--) {
            int a, b;
            cin >> a >> b;
            int c = query(1, 1, N, a);
            if (c == INF) continue;
            insert(1, 1, N, a + 1, b, c + 1);
        }
        cout << query(1, 1, N, N) << endl;
        if (T > 0) cout << endl;
    }
    return 0;
}
