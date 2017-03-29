#include <cstdio>
#include <algorithm>
using namespace std;

int x[1000010];

int get(long long n) {
    int ans = 1;
    long long m = n;
    while (n != 1) {
        if (n % 2) n = n * 3 + 1; else n >>= 1;
        if (n < m) {
            ans += x[n];
            break;
        }
        ++ans;
    }
    return ans;
}

int main() {
    int a, b, ans;
    x[1] = 1;
    for (int i = 2; i <= 1000000; ++i) x[i] = get(i);
    
    while (scanf("%d%d", &a, &b) != EOF) {
        ans = 0;
        if (a < b) 
            for (int i = a; i <= b; ++i) ans = max(ans, x[i]); 
        else 
            for (int i = b; i <= a; ++i) ans = max(ans, x[i]);    
        printf("%d %d %d\n", a, b, ans);
    }
    return 0;
}
