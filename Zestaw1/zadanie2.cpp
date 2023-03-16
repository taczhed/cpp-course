#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    const int MAX_SIZE = 100; // maksymalna długość ciągu znaków
    char str1[MAX_SIZE], str2[MAX_SIZE]; // deklaracja tablic char na ciągi znaków
    cout << "Podaj pierwszy ciag znakow: ";
    cin.getline(str1, MAX_SIZE); // wczytanie pierwszego ciągu znaków
    cout << "Podaj drugi ciag znakow: ";
    cin.getline(str2, MAX_SIZE); // wczytanie drugiego ciągu znaków
    
    // zamiana liter na małe litery
    for (int i = 0; i < strlen(str1); i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; i < strlen(str2); i++) {
        str2[i] = tolower(str2[i]);
    }
    
    // porównanie ciągów znaków
    if (strcmp(str1, str2) == 0) {
        cout << "Ciągi znaków są identyczne." << endl;
    } else {
        cout << "Ciągi znaków są różne." << endl;
    }
    
    return 0;
}