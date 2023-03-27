#include <iostream>
#include <initializer_list>
#include <numeric>

using namespace std;
template<typename T>

auto fun(const initializer_list<T>& arg) {
    T sum = 0;
    for (auto i = arg.begin(); i != arg.end(); ++i) {
        sum += *i;
    }
    return sum;
}

int main() {

    auto intArgs = {1, 2, 3};
    auto doubleArgs = {1.0, 2.5, 3.75};

    auto intResult = fun(intArgs);
    auto doubleResult = fun(doubleArgs);

    cout << "Wynik typu int: " << intResult << endl;
    cout << "Wynik typu double: " << doubleResult << endl;

    // fun({1, 2, 3}); // Błąd kompilacji

    return 0;
}