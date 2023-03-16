#include <iostream>
#include <iomanip>
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

    for (int y = 0; y < outerSize; y++) {
        if ((y >= 0 && y < borderSize) || (y >= innerSize + borderSize && y < outerSize)) {
            cout << setfill('*') << setw(outerSize) << "" << endl;
        } else {
            cout << setfill('*') << setw(borderSize) << "" << setfill(' ') << setw(innerSize) << "" << setfill('*') << setw(borderSize) << "" << endl;
        }
    }

    return 0;
}