#include <iostream>
#include <format>
using namespace std;

int main()
{
    int outerSize, innerSize;

    cout << "Podaj rozmiar zewnetrzny: ";
    cin >> outerSize;

    cout << "Podaj rozmiar wewnetrzny: ";
    cin >> innerSize;

    if (innerSize >= outerSize) {
        cerr << "Rozmiar wewnetrzny musi byc mniejszy niz zewnetrzny!\n";
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