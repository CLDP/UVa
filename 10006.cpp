#include <cstdio>

int Power(long long a, int b, const int n) {
    long long c = 1;
    while (b) {
        if (b % 2 == 1) c = ((a % n) * (c % n)) % n;
        b >>= 1;
        a = ((a % n) * (a % n)) % n;
    }
    return c;
}

bool iscar(const int a) {
    for (int i = 2; i < a; ++i) {
        if (Power(i, a, a) != i) return false;
    }
    return true;
}

bool isprime(const int a) {
    for (int i = 2; i * i < a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}


int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (!n) break;
         
        if (!isprime(n) && iscar(n)) {
            printf("The number %d is a Carmichael number.\n", n);
        } else {
            printf("%d is normal.\n", n);
        }
    }
    return 0;
}
