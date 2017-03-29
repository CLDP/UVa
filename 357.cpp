#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 30010;
const int MAXM = 5;
int W[MAXM] = {1, 5, 10, 25, 50};
long long f[MAXN];


int main() {
    int n;
    f[0] = 1;
    for (int i = 0; i < MAXM; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            if (j >= W[i]) f[j] += f[j - W[i]];
        }
    }
    
    while (scanf("%d", &n) != EOF) {
         if (f[n] == 1) {
             cout << "There is only 1 way to produce " << n << " cents change." << endl;
         } else {
             cout << "There are " << f[n] << " ways to produce " << n << " cents change." << endl;
         }
    }
    return 0;
}
