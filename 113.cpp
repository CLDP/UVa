#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxlen = 210; 

class HP {
public:
    int len, s[maxlen];
    HP() {(*this) = 0;};                  
    HP(int inte) {(*this) = inte;};      
    HP(const char *str) {(*this) = str;}; 
    friend istream &operator >> (istream &cin, HP &x);
    friend ostream &operator << (ostream &cout, const HP &x);
    HP operator = (int inte);
    HP operator = (const char *str);
    HP operator * (const HP &b);
    HP operator + (const HP &b);
    HP operator / (const int &b);
    bool operator < (const HP &b);
};

istream &operator >> (istream &cin, HP &x) {
    char p[maxlen];
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


HP HP::operator / (const int &b) {
    int i, j, d = 0;
    HP c;
    for (i = len; i > 0; --i) {
        d = d * 10 + s[i];
        c.s[i] = d / b;
        d %= b;
    }
    c.len = len;
    while ((c.len > 1) && (c.s[c.len] == 0)) --c.len;
    return c;
}

bool HP::operator < (const HP &b) {
    if (len < b.len) return true;
    if (b.len < len) return false;
    for (int i = len; i > 0; --i) {
        if (s[i] < b.s[i]) return true;
        if (b.s[i] < s[i]) return false; 
    }
    return false;          
}


int main() {
    int n;
    HP a, b, c, d, temp;
    while (scanf("%d", &n) != EOF) {
        cin >> d;
        a = 1;
        b = d;
        while (a < b) {
            c = (a + b) / 2;
            temp = c;
            for (int i = 1; i < n; ++i) {
                temp = temp * c;
                if (d < temp) break;
            }
            if (temp < d) a = c + 1; else b = c;
        }
        cout << b << endl;
    }
    return 0;
}
