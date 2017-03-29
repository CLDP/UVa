#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int count = 0, temp;
    int m = 2, odd = 3;
    int n[10], k[10];
    
    while (true) {
        if (count == 10) break;
        
        temp = sqrt(double((odd * odd + 1) / 2));
        if (2 * temp * temp == odd * odd + 1) {
            k[count] = temp * odd;
            n[count++] = odd * odd;
        }
        odd += 2;
        temp = sqrt(double(2 * m * m + 1));
        if (temp * temp == 2 * m * m + 1) {
            k[count] = m * temp;
            n[count++] = 2 * m * m;
        }    
        ++m;
    }
    for (int i = 0; i < 10; ++i) {
        cout << setw(10) << k[i] << setw(10) << n[i] << endl;
    }
    return 0;
}
