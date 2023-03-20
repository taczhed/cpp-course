#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> fib = {0, 1};
    int k = 40;
    for (int i = 0; i <= k; i++) {

        if (i == 0 || i == 1) {
            cout << fib[i] << endl; 
        } else {
            fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
            cout << fib[fib.size() - 1] << endl; 
        }
    }
}