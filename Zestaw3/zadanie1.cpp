#include <iostream>
#include <string>

class StringClass {
    std::string str;
public:
    // konstruktory
    StringClass() : str("") {
        #ifdef DEBUG
            std::cout << "Tworzenie obiektu StringClass bez argumentu" << std::endl;
        #endif
    }
    
    StringClass(const std::string& s) : str(s) {

        #ifdef DEBUG
        std::cout << "Tworzenie obiektu StringClass z napisem: " << str << std::endl;
        #endif
    }
    
    StringClass(const StringClass& other) : str(other.str) {

        #ifdef DEBUG
        std::cout << "Kopiowanie obiektu StringClass z napisem: " << str << std::endl;
        #endif
    }
    
    StringClass(StringClass&& other) noexcept : str(std::move(other.str)) {

        #ifdef DEBUG
        std::cout << "Przenoszenie obiektu StringClass z napisem: " << str << std::endl;
        #endif
    }
    
    // destruktor
    ~StringClass() {

        #ifdef DEBUG    
        std::cout << "Usuwanie obiektu StringClass z napisem: " << str << std::endl;
        #endif
    }
    
    // operator 
    StringClass& operator=(const StringClass& other) {
        if (this != &other) {
            str = other.str;
            #ifdef DEBUG
            std::cout << "Operator kopiujący obiektu StringClass z napisem: " << str << std::endl;
            #endif
        }
        return *this;
    }
    
    StringClass& operator=(StringClass&& other) noexcept {
        if (this != &other) {
            str = std::move(other.str);
            #ifdef DEBUG
            std::cout << "Operator przeniesienia obiektu StringClass" << str << std::endl;
            #endif
        }
        return *this;
    }
};

int main() {
    StringClass str1;  // domyślny konstruktor
    StringClass str2("Hello, world!");  // konstruktor z argumentem
    StringClass str3(str2);  // konstruktor kopiujący
    StringClass str4(std::move(str3));  // konstruktor przenoszący
    str4 = str2;  // operator przypisania kopiujący
    str2 = std::move(str3);  // operator przypisania przenoszący
    
    return 0;
}