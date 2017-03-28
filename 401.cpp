#include <cstdio>
#include <cstring>

char p[1000];

int main() {
    char map[130];
    map['A'] = 'A';
    map['E'] = '3';
    map['H'] = 'H';
    map['I'] = 'I';
    map['J'] = 'L';
    map['L'] = 'J';
    map['M'] = 'M';
    map['O'] = 'O';
    map['S'] = '2';
    map['T'] = 'T';
    map['U'] = 'U';
    map['V'] = 'V';
    map['W'] = 'W';
    map['X'] = 'X';
    map['Y'] = 'Y';
    map['Z'] = '5';
    map['1'] = '1';
    map['2'] = 'S';
    map['3'] = 'E';
    map['5'] = 'Z';
    map['8'] = '8';
    while (gets(p)) {
        bool a = true, b = true;
        for (int i = 0, j = strlen(p) - 1; i <= j; ++i, --j) {
            a &= (p[i] == p[j]);
            b &= (map[p[i]] == p[j]);
        }
        switch (a + 2 * b) {
            case 0: printf("%s -- is not a palindrome.\n\n", p); break;
            case 1: printf("%s -- is a regular palindrome.\n\n", p); break;
            case 2: printf("%s -- is a mirrored string.\n\n", p); break;
            case 3: printf("%s -- is a mirrored palindrome.\n\n", p); break;
        }
    }
    return 0;
}
