#include <iostream>
#include <cstring>

using namespace std;

class TKlasa {
public:
    TKlasa(const char* c) : str(c) {}
    
    const char* operator[](const char* s) const {
        if (strstr(str.c_str(), s) != nullptr) {
            return strstr(str.c_str(), s);
        } else {
            return nullptr;
        }
    }
    
    bool operator<=(const TKlasa& other) const {
        return str.length() <= other.str.length();
    }
    
private:
    string str;
};

int main() {
    TKlasa test1("Przykladowy tekst");

    const char* subStr = test1["klad"]; // Sprawdzenie czy obiekt includes "klad"
    if (subStr != nullptr) {
        cout << "Podciag znakow znaleziony: " << subStr << endl;
    } else {
        cout << "Podciag znakow nie znaleziony" << endl;
    }

    TKlasa test2("Inny tekst");
    if (test1 <= test2) {
        cout << "Obiekt obj jest mniejszy lub równy test2" << endl;
    } else {
        cout << "Obiekt obj jest większy od test2." << endl;
    }
    
    return 0;
}