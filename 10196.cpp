#include <cstdio>
#include <cstring>

const int rx[4] = {0, 0, 1, -1};
const int ry[4] = {1, -1, 0, 0};
const int bx[4] = {1, -1, 1, -1};
const int by[4] = {1, -1, -1, 1};
const int qx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int qy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int nx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int ny[8] = {-1, 1, -2, 2, -2, 2, -1, 1};


int check(const int a, const int b) {
    return 0 <= a && a < 8 && 0 <= b && b < 8;
}

int main() {
    int num = 0;
    char p[9][9];
    while (true) {
        bool flag = true;
        for (int i = 0; i < 8; ++i) scanf("%s", p[i]);
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) flag &= (p[i][j] == '.');
        }
        
        if (flag) break;
        
        bool white = false, black = false;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                switch (p[i][j]) {
                    case 'p':
                        if (check(i + 1, j - 1) && p[i + 1][j - 1] == 'K') white = true;
                        if (check(i + 1, j + 1) && p[i + 1][j + 1] == 'K') white = true;
                        break;
                    case 'P':
                        if (check(i - 1, j - 1) && p[i - 1][j - 1] == 'k') black = true;
                        if (check(i - 1, j + 1) && p[i - 1][j + 1] == 'k') black = true;
                        break;
                    case 'r':
                        for (int k = 0; k < 4; ++k) {
                            int a = i, b = j;
                            while (check(a + rx[k], b + ry[k]) && p[a + rx[k]][b + ry[k]] == '.') { a += rx[k]; b+= ry[k];}
                            if (p[a + rx[k]][b + ry[k]] == 'K') white = true;
                        }
                        break;
                    case 'R': 
                        for (int k = 0; k < 4; ++k) {
                            int a = i, b = j;
                            while (check(a + rx[k], b + ry[k]) && p[a + rx[k]][b + ry[k]] == '.') { a += rx[k]; b+= ry[k];}
                            if (p[a + rx[k]][b + ry[k]] == 'k') black = true;
                        }
                        break;
                    case 'b':
                        for (int k = 0; k < 4; ++k) {
                            int a = i, b = j;
                            while (check(a + bx[k], b + by[k]) && p[a + bx[k]][b + by[k]] == '.') { a += bx[k]; b+= by[k];}
                            if (p[a + bx[k]][b + by[k]] == 'K') white = true;
                        }
                        break;
                    case 'B':
                        for (int k = 0; k < 4; ++k) {
                            int a = i, b = j;
                            while (check(a + bx[k], b + by[k]) && p[a + bx[k]][b + by[k]] == '.') { a += bx[k]; b+= by[k];}
                            if (p[a + bx[k]][b + by[k]] == 'k') black = true;
                        }
                        break;
                    case 'q':
                        for (int k = 0; k < 8; ++k) {
                            int a = i, b = j;
                            while (check(a + qx[k], b + qy[k]) && p[a + qx[k]][b + qy[k]] == '.') { a += qx[k]; b+= qy[k];}
                            if (p[a + qx[k]][b + qy[k]] == 'K') white = true;
                        }
                        break;
                    case 'Q':
                        for (int k = 0; k < 8; ++k) {
                            int a = i, b = j;
                            while (check(a + qx[k], b + qy[k]) && p[a + qx[k]][b + qy[k]] == '.') { a += qx[k]; b+= qy[k];}
                            if (p[a + qx[k]][b + qy[k]] == 'k') black = true;
                        }
                        break;
                    case 'k':
                        for (int k = 0; k < 8; ++k) {
                            if (check(i + qx[k], j + qy[k]) && p[i + qx[k]][j + qy[k]] == 'K') white = true;
                        }
                        break;
                    case 'K':
                        for (int k = 0; k < 8; ++k) {
                            if (check(i + qx[k], j + qy[k]) && p[i + qx[k]][j + qy[k]] == 'k') black = true;
                        }
                        break;
                    case 'n':
                        for (int k = 0; k < 8; ++k) {
                            if (check(i + nx[k], j + ny[k]) && p[i + nx[k]][j + ny[k]] == 'K') white = true;
                        }
                        break;
                    case 'N':
                        for (int k = 0; k < 8; ++k) {
                            if (check(i + nx[k], j + ny[k]) && p[i + nx[k]][j + ny[k]] == 'k') black = true;
                        }
                        break;
                }
            }
        }
        printf("Game #%d: ", ++num);
        if (black) printf("black king is in check."); else
        if (white) printf("white king is in check."); else
        printf("no king is in check.");
        printf("\n");
    }
    return 0;
}
