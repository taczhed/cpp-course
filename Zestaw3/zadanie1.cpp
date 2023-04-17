#include <iostream>
#include <string>

using namespace std;

class StringClass {
    string str;
public:
    // konstruktory
    StringClass() : str("") {
        #ifdef DEBUG
            cout << "Tworzenie obiektu StringClass bez argumentu" << endl;
        #endif
    }
    
    StringClass(const string& s) : str(s) {

        #ifdef DEBUG
        cout << "Tworzenie obiektu StringClass z napisem: " << str << endl;
        #endif
    }
    
    StringClass(const StringClass& other) : str(other.str) {

        #ifdef DEBUG
        cout << "Kopiowanie obiektu StringClass z napisem: " << str << endl;
        #endif
    }
    
    StringClass(StringClass&& other) noexcept : str(move(other.str)) {

        #ifdef DEBUG
        cout << "Przenoszenie obiektu StringClass z napisem: " << str << endl;
        #endif
    }
    
    // destruktor
    ~StringClass() {

        #ifdef DEBUG    
        cout << "Usuwanie obiektu StringClass z napisem: " << str << endl;
        #endif
    }
    
    // operator 
    StringClass& operator=(const StringClass& other) {
        if (this != &other) {
            str = other.str;
            #ifdef DEBUG
            cout << "Operator kopiujący obiektu StringClass z napisem: " << str << endl;
            #endif
        }
        return *this;
    }
    
    StringClass& operator=(StringClass&& other) noexcept {
        if (this != &other) {
            str = move(other.str);
            #ifdef DEBUG
            cout << "Operator przeniesienia obiektu StringClass" << str << endl;
            #endif
        }
        return *this;
    }
};

int main() {
    StringClass str1;  // domyślny konstruktor
    StringClass str2("Hello, world!");  // konstruktor z argumentem
    StringClass str3(str2);  // konstruktor kopiujący
    StringClass str4(move(str3));  // konstruktor przenoszący
    str4 = str2;  // operator przypisania kopiujący
    str2 = move(str3);  // operator przypisania przenoszący
    
    return 0;
}