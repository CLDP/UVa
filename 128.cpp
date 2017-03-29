#include <cstdio>
#include <cstring>

const int KM = 256;
const int PM = 34943;
const int MAXN = 2010;

int main() {
    int len, ans;
    long long now;
    char s[MAXN];
    char output[7];
    while (true) {
        gets(s);
        if (s[0] == '#') break;
        len = strlen(s);
        now = 0;
        for (int i = 0; i < len; ++i) now = (now * KM + s[i]) % PM;
        now = now * KM * KM % PM;
          
        if (now) ans = PM - now; else ans = 0;
        sprintf(output, "%04x\n", ans);
        for (int i = 0; i < 4; ++i) {
            if (output[i] >= 'a' && output[i] <= 'z')
                output[i] = output[i] - 'a' + 'A';
        }
          
        printf("%c%c %c%c\n", output[0], output[1], output[2], output[3]);
    }
    return 0;
}
