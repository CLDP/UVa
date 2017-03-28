#include <string>
#include <iostream>
using namespace std;

string P;

int main() {
    while (getline(cin, P)) {
        int ans = 0;
        bool word = true;
        for (int i = 0; i < P.size(); ++i) {
            if (!isalpha(P[i])) 
                word = true;
            else {
                if (word) {
                    ++ans;
                    word = false;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
