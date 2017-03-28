#include <iostream>
#include <string>
using namespace std;

string P;

int main() {
    while (getline(cin, P)) {
        for (int i = 0; i < P.size(); ++i) P[i] = P[i] +'C' - 'J';
        cout << P << endl;
    }
    return 0;
}
