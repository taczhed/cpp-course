#include <iostream>
#include <format>
using namespace std;

// https://godbolt.org/
// x86-64 gcc (trunk) -std=c++2b

int main()
{
    int outerSize, innerSize;

    cout << "Podaj rozmiar zewnetrzny: ";
    cin >> outerSize;

    cout << "Podaj rozmiar wewnetrzny: ";
    cin >> innerSize;

    if (innerSize >= outerSize || ((outerSize % 2 == 0 && innerSize % 2 != 0) || (outerSize % 2 != 0 && innerSize % 2 == 0))) {
        cerr << "Rozmiar wewnetrzny musi byc mniejszy niz zewnetrzny oraz posiadać identyczną parzystość (symetria)!\n";
        return 1;
    }

    int borderSize = ((outerSize - innerSize) / 2);

    cout << "" << endl;

    for (int y = 0; y < outerSize; y++) {
        if ((y >= 0 && y < borderSize) || (y >= innerSize + borderSize && y < outerSize)) {
            cout << format("{:*^{}}", "", outerSize) << endl;
        } else {
            cout << format("{:*^{}}{:^{}}{:*^{}}", "", borderSize, "", innerSize, "", borderSize) << endl;
        }
    }

    return 0;
}