#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 10010;
const int INF = 12624462;
int l[MAXN], r[MAXN], key[MAXN], m, n;
string all;

void init() {
    char p = ' ';
    int a = 1;
    all = "";
    while (p != '(') cin >> p;
    all = all + p;
    while (a > 0) {
        cin >> p;
        if (p == '(') {
            ++a;            
        } else 
        if (p == ')') {
            --a;
        } else 
        if (isdigit(p) || p == '-') {
          
        } else continue;
        all = all + p;
    }
    
    m = 0;
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(key, 0, sizeof(key));
}

int make(string q, int a) {
    if (q == "()") {
        key[a] = INF;
        return 0;
    }
    char p;
    int i = 1, b = 0;
    bool flagq = false;
    if (q[i] == '-') { 
        flagq = 1;
        ++i;
    }
    while (isdigit(q[i])) {
        b = b * 10 + q[i] - '0';
        ++i;
    }
    if (flagq) b = -b;
    key[a] = b;
    b = 0;
    string qq = "";
    while (b > 0 || qq == "") {
        qq = qq + q[i];
        if (q[i] == '(') ++b;
        if (q[i] == ')') --b;
        ++i;
    }
    ++m;
    l[a] = m;
    make(qq, m);
    b = 0;
    qq = "";
    while (b > 0 || qq == "") {
        qq = qq + q[i];
        if (q[i] == '(') ++b;
        if (q[i] == ')') --b;
        ++i;
    }
    ++m;
    r[a] = m;
    make(qq, m);
    return 0;
}

bool dfs(int val, int pos) {
    val -= key[pos];
    if (key[l[pos]] == INF && key[r[pos]] == INF) {
        if (val == 0) return true; else return false;
    }
    bool flag = false;
    if (l[pos] > 0) flag |= dfs(val, l[pos]);
    if (r[pos] > 0) flag |= dfs(val, r[pos]);
    return flag;
}


int main() {
    int ans;
    while(scanf("%d", &n) != -1) {
        init();
        make(all, 0);
        if (dfs(n, 0) && all != "()") printf("yes\n"); else printf("no\n");
    }
    return 0;
}
