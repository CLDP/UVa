#include <cstdio>
#include <cstring>
#include <cmath>

bool cz[10];
int x[10], y[10], z[10], ans[10];
double total;

double dist(int a, int b) {
    return sqrt((x[z[a]] - x[z[b]]) * (x[z[a]] - x[z[b]])
              + (y[z[a]] - y[z[b]]) * (y[z[a]] - y[z[b]])) + 16;
}

int find(int a, int n) {
    if (a == n) {
        double now = 0;
        for (int i = 0; i < n - 1; ++i) now += dist(i, i + 1);
        if (now < total) {
            total = now;
            for (int i = 0; i < n; ++i) ans[i] = z[i];
        }
    } else
    for (int i = 0; i < n; ++i) {
        if (!cz[i]) {
            cz[i] = true;
            z[a] = i;
            find(a + 1, n);
            cz[i] = false;
        }
    }
    return 0;
}


int main() {
    int n, num = 0;
    scanf("%d", &n);
    while (n) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
        total = 1e100;
        find(0, n);
        for (int i = 0; i < n; ++i) z[i] = ans[i];
        printf("**********************************************************\n");
        printf("Network #%d\n", ++num);
        for (int i = 0; i < n-1; ++i) 
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
                x[ans[i]], y[ans[i]], x[ans[i + 1]], y[ans[i + 1]], dist(i, i + 1));
        printf("Number of feet of cable required is %.2lf.\n", total);      
        scanf("%d", &n);
    }  
    return 0;
}
