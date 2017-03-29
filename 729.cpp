#include <cstdio>

const int m2[18] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 
                    1 << 13, 1 << 14, 1 << 15, 1 << 16, 1 << 17};

int get(int a, int n) {
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a >= m2[i]) {
            a -= m2[i];
            ++ans;
        }
    }
    return ans;
}

int print(int a, int n) {
    for (int i = n - 1; i >= 0; --i) {
        if (a >= m2[i]) {
            a -= m2[i];
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}


int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        for (int j = 0; j < m2[a]; ++j)
            if (get(j, a) == b) print(j, a);
        if (i < n - 1) printf("\n");
    }
    
    return 0;
}
