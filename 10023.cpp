#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXL = 2010; 

class HP {
public:
    int len, s[MAXL];
    HP() {(*this) = 0;};
    HP(int inte) {(*this) = inte;};
    HP(const char *str) {(*this) = str;};
    friend istream &operator >> (istream &cin, HP &x);
    friend ostream &operator << (ostream &cout, const HP &x);
    HP operator = (int inte);
    HP operator = (const char *str);
    HP operator * (const HP &b);
    HP operator + (const HP &b);
    HP operator - (const HP &b);
    int Compare(const HP &b);
};

istream &operator >> (istream &cin, HP &x) {
    char p[MAXL];
    scanf("%s", p);
    x = p;
    return cin;
}

ostream &operator << (ostream &cout, const HP &x) {
    for (int i = x.len; i >= 1; --i) printf("%d", x.s[i]);
    return cout;
}

HP HP::operator = (const char *str) {
    len = strlen(str);
    for (int i = 1; i <= len; ++i) s[i] = str[len - i] - '0';
    return *this;
}

HP HP::operator = (int inte) {
    if (inte == 0) {
        len = 1;
        s[1] = 0;
        return (*this);
    }
    for (len = 0; inte > 0;) {
        s[++len] = inte % 10;
        inte /= 10;
    }
    return (*this);
}

HP HP::operator * (const HP &b) {
    int i, j;
    HP c;
    c.len = len + b.len;
    for (i = 1; i <= c.len; ++i) c.s[i] = 0;
    for (i = 1; i <= len; ++i) {
       for (j = 1; j <= b.len; ++j) c.s[i + j - 1] += s[i] * b.s[j];
    }
    for (i = 1; i < c.len; ++i) {
        c.s[i + 1] += c.s[i] / 10;
        c.s[i] %= 10;
    }
    while (c.s[i]) {
        c.s[i + 1] = c.s[i] / 10;
        c.s[i] %= 10; 
        ++i;
    }
    while (i > 1 && !c.s[i]) i--;
    c.len = i;
    return c;
}

HP HP::operator + (const HP &b) {
    int i;
    HP c;
    c.s[1] = 0;
    for (i = 1; i <= len || i <= b.len || c.s[i]; ++i) {
        if (i <= len) c.s[i] += s[i];
        if (i <= b.len) c.s[i] += b.s[i];
        c.s[i + 1] = c.s[i] / 10; 
        c.s[i] %= 10;
    }
    c.len = i - 1;
    if (c.len == 0) c.len = 1;
    return c;
}

HP HP::operator - (const HP &b) {
    int i, j;
    HP c;
    for (i = 1, j = 0; i <= len; ++i) {
        c.s[i] = s[i] - j;
        if (i <= b.len) c.s[i] -= b.s[i];
        if (c.s[i] < 0) {
            j = 1;
            c.s[i] += 10;
        } else {
            j = 0;
        }
    }
    c.len = len;
    while (c.len > 1 && !c.s[c.len]) c.len--;
    return c;
}

int Cmp(const HP &x, const HP &y) {
    if (x.len > y.len) return 1;
    if (x.len < y.len) return -1;
    for (int i = x.len; i > 0; --i) {
        if (x.s[i] > y.s[i]) return 1;
        if (x.s[i] < y.s[i]) return -1;
    }
    return 0;
}

int main() {
    int n, len, t;
    HP a, b, now, ans;
    cin >> n;
    while (n--) {
        cin >> a;
        a.s[a.len + 1] = 0;
        ans = 0;
        b = 0;
        len = (a.len + 1) / 2;
        ans.len = len;
        for (int i = len; i > 0; --i) {
            b = b * 100;
            b.s[2] = a.s[i * 2];
            b.s[1] = a.s[i * 2 - 1];
            if (b.len == 1 && b.s[2]) b.len = 2;
            now = ans;
            for (int j = i + 1; j <= len; ++j) now.s[j - i] = now.s[j];
            if (len - i) now.len = len - i; else now.len = 1;
            now = now * 20;
            for (int j = 0; j < 10; ++j) {
                now.s[1] = j;
                if (Cmp(now * j, b) != 1) {
                    t = j;
                } else break;
            }
            ans.s[i] = t;
            now.s[1] = t;
            b = b - (now * t);
        }
        cout << ans << endl;
        if (n) cout << endl;
    }
    return 0;
}
