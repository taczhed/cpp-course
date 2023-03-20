#include <iostream>

using namespace std;

int main() {
    unsigned long long k = 40;
    int a = 0, b = 1, n = 0;

    for (unsigned long long i = 0; i <= k; i++) {

        if (i == 0) {
            cout << 0 << endl; 
        }else if (i == 1) {
            cout << 1 << endl; 
        } else {
            n = a + b;
            a = b;
            b = n;
            cout << n << endl; 
        }
    }
}