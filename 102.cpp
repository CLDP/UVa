#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int INF = 2100000000;
int x[3][3];
int ans, total;
string ansp;

int main() {
    while (scanf("%d", &x[0][0]) != -1) {
        scanf("%d%d",   &x[0][1], &x[0][2]);
        scanf("%d%d%d", &x[1][0], &x[1][1], &x[1][2]);
        scanf("%d%d%d", &x[2][0], &x[2][1], &x[2][2]);
        total = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) total += x[i][j];
        }
        ans = INF;
        if (ans >= total - x[0][1] - x[1][2] - x[2][0]) {
            ans = total - x[0][1] - x[1][2] - x[2][0];
            ansp = "GCB";
        }
        
        if (ans >= total - x[0][1] - x[1][0] - x[2][2]) {
            ans = total - x[0][1] - x[1][0] - x[2][2];
            ansp = "GBC";
        }
        
        if (ans >= total - x[0][2] - x[1][1] - x[2][0]) {
            ans = total - x[0][2] - x[1][1] - x[2][0];
            ansp = "CGB";
        }
        
        if (ans >= total - x[0][2] - x[1][0] - x[2][1]) {
            ans = total - x[0][2] - x[1][0] - x[2][1];
            ansp = "CBG";
        }
        
        if (ans >= total - x[0][0] - x[1][1] - x[2][2]) {
            ans = total - x[0][0] - x[1][1] - x[2][2];
            ansp = "BGC";
        }
        
        if (ans >= total - x[0][0] - x[1][2] - x[2][1]) {
            ans = total - x[0][0] - x[1][2] - x[2][1];
            ansp = "BCG";
        }
        cout << ansp << " " << ans << endl;
    }
    return 0;
}
