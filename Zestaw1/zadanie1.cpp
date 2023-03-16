#include <iostream>
#include <iomanip>
using namespace std;

// int main()
// {
//     int outerSize, innerSize;
//     cout << "Podaj rozmiar zewnętrznego kwadratu: ";
//     cin >> outerSize;
//     cout << "Podaj rozmiar wewnętrznego kwadratu: ";
//     cin >> innerSize;

//     if (outerSize <= 0 || innerSize <= 0 || innerSize >= outerSize) {
//         cout << "Nieprawidłowe rozmiary!" << endl;
//         return 1;
//     }

//     // Rysowanie kwadratu

//     for (int y = 0; y < outerSize; y++) {

//         if ((y >= 0 && y <= outerSize) || (y <= outerSize && y <= outerSize - innerSize)) {
//             cout << setfill('*') << setw(outerSize) << endl;
//         }
        
//         else if ((y >= outerSize && y >= outerSize - innerSize)) {
//             cout << setfill('*') << setw((outerSize - innerSize) / 2) << setfill(' ') << setw(innerSize) << setfill('*') << setw((outerSize - innerSize) / 2) << endl;
//         }
//     }

//     return 0;
// }

int main()
{
    int outerSize, innerSize;

    std::cout << "Podaj rozmiar zewnetrzny: ";
    std::cin >> outerSize;

    std::cout << "Podaj rozmiar wewnetrzny: ";
    std::cin >> innerSize;

    if (innerSize >= outerSize) {
        std::cerr << "Rozmiar wewnetrzny musi byc mniejszy niz zewnetrzny!\n";
        return 1;
    }

    int borderSize = ((outerSize - innerSize) / 2);

    for (int y = 0; y < outerSize; y++) {
        if ((y >= 0 && y < borderSize) || (y >= innerSize + borderSize && y < outerSize)) {
            std::cout << std::setfill('*') << std::setw(outerSize) << "" << endl;
        } else {
            std::cout << std::setfill('*') << std::setw(borderSize) << "" << 
            std::setfill(' ') << std::setw(innerSize) << "" << 
            std::setfill('*') << std::setw(borderSize) << "" << endl;
        }
    }

    return 0;
}