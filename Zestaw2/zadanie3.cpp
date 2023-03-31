#include <iostream>
#include <initializer_list>
#include <numeric>

using namespace std;

auto fun(const auto& arg) {
    auto sum = *arg.begin();
    for (auto i = arg.begin() + 1; i != arg.end(); ++i) {
        sum += *i;
    }
    return sum;
}

int main() {

    auto intArgs = {1, 2, 3};
    auto doubleArgs = {1.0, 2.5, 3.75};

    cout << "Wynik typu int: " << fun(intArgs) << endl;
    cout << "Wynik typu double: " << fun(doubleArgs) << endl;

    // fun({1, 2, 3}); // Błąd

    return 0;
}