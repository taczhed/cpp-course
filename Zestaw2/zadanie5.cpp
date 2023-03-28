#include <iostream>
#include <string>

using namespace std;

const int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

string convertToRoman(int number) {

    string result;
    
    for (int i = 0; i < 13; i++) {
        while (number >= arabic[i]) {
            result += roman[i];
            number -= arabic[i];
        }
    }
    
    return result;
}

int main(int argc, char* argv[]) {

    int input;
    
    if (argc != 2) {
        cout << "Błąd! Podaj liczbę w zapisie arabskim, jako argument!\n";
        return 1;
    }
    
    input = stoi(argv[1]);
    
    if (input < 0 || input > 3999) {
        cout << "Liczba poza przedziałem\n";
        return 1;
    }
    
    cout << "Liczba " << input << " w zapisie arabskim to "<< convertToRoman(input) << " w zapisie rzymskim." << endl;
    
    return 0;
}