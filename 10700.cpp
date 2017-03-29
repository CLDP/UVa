#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;


int main() {
    int n;
    int x[15], y[15];
    long long z[15];
    char p[1000];
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        gets(p);
        int j = 0, num = 0;
        while (j < strlen(p)) {
            int a = 0;
            while (isdigit(p[j])) a = a * 10 + p[j++] - '0';
            x[num] = a;
            if (p[j++] == '+') y[num] = 0; else y[num] = 1;
            ++num;
        }
        int m = 0;
        for (int k = 0; k < num; ++k) {
            if (k) {
                if (!y[k - 1]) {
                    z[m] += x[k];
                } else {
                    z[++m] = x[k];
                }
            } else {
                z[0] = x[0];
            }
        }
        long long max = 1;
        for (int k = 0; k <= m; ++k) max *= z[k];
        
        m = 0;
        for (int k = 0; k < num; ++k) {
            if (k) {
                if (y[k - 1]) {
                    z[m] *= x[k];
                } else {
                    z[++m] = x[k];
                }
            } else {
                z[0] = x[0];
            }
        }
        long long min = 0;
        for (int k = 0; k <= m; ++k) min += z[k];
        cout << "The maximum and minimum are " << max 
             << " and " << min << "." << endl;
    }
    return 0;
}
