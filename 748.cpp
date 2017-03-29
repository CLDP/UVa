#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxlen = 310; 

class HP {
public:
    int len, dot, s[maxlen];
    HP() {(*this) = 0;};                  
    HP(int inte) {(*this) = inte;};      
    HP(const char *str) {(*this) = str;}; 
    friend istream &operator >> (istream &cin, HP &x);
    friend ostream &operator << (ostream &cout, const HP &x);
    HP operator = (int inte);
    HP operator = (const char *str);
    HP operator * (const HP &b);
};

istream &operator >> (istream &cin, HP &x) {
    char p[maxlen];
    scanf("%s", p);
    x = p;
    return cin;
}

ostream &operator << (ostream &cout, const HP &x) {
    int a = 1, b = x.len;
    while (x.s[a] == 0) ++a;
    while (x.s[b] == 0) --b;
    if (x.dot == 0 || x.dot == a - 1) {
        for (int i = b; i > x.dot; --i) printf("%d", x.s[i]); 
    } else {      
        if (b > x.dot) for (int i = b; i > x.dot; --i) printf("%d", x.s[i]);
        printf(".");
        for (int i = x.dot; i >= a; --i) printf("%d", x.s[i]);
    }
    return cout;
}

HP HP::operator = (const char *str) {
    len = strlen(str);
    bool flag = false;
    for (int i = 1; i <= len; ++i) {
        if (str[len-i] == '.') {
            dot = i - 1;
            flag = true;
        }
    }
    if (flag) {
        for (int i = 1; i <= dot; ++i) s[i] = str[len - i] - '0';
        for (int i = dot + 2; i <= len; ++i) s[i-1] = str[len - i] - '0';
        --len;
    } else {
        for (int i = 1; i <= len; ++i) s[i] = str[len - i] - '0'; 
        dot = 0;  
    }
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
    c.len = i;
    c.dot = b.dot + dot;
    return c;
}


int main() {
    HP a, b;
    int n;
    cin >> a;
    while (scanf("%d", &n) != EOF) {
        b = a;
        if (n > 0) {
           for (int i = 1; i < n; ++i) b = b * a;
           cout << b << endl;
        } else {
            cout << "1" << endl;
        }
        cin >> a;
    }
    return 0;
}
