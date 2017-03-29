#include <cstdio>

const int MAXN = 510;
int x[MAXN];
bool y[MAXN];


int main() {
    int n, m, t, now, mm;
    long long l, r, mid;
    bool flag;
    scanf("%d", &t);
    while (t) {
        scanf("%d%d", &n, &m);
        l = 0; r = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
            r += x[i];
        }
        while (l < r) {
            mid  = (l + r) >> 1;
            flag = true;
            mm = m;
            now = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (now + x[j] <= mid) {
                    now += x[j];
                } else {
                    now = x[j];
                    --mm;
                    if (x[j] > mid) mm = 0;
                    if (mm == 0) break;
                }
            }
            
            if (mm > 0) r = mid; else l = mid+1;
        }
        
        now = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (m == j + 2 && m > 1) {
                y[j] = true;
                --m;
                continue;
            }
            if (now + x[j] <= l) {
                now += x[j];
                y[j] = false;
            } else {
                now = x[j];
                y[j] = true;
                --m;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", x[i]);
            if (y[i]) printf(" /");
        }
        
        printf("\n");
        --t;
    }
    return 0;
}
