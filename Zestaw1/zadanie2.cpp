#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char sentence1[100], sentence2[100];
    cout << "Podaj pierwszy ciag znakow: ";
    cin.getline(sentence1, 100);
    cout << "Podaj drugi ciag znakow: ";
    cin.getline(sentence2, 100);
    
    for (int i = 0; i < sizeof(sentence1); i++) {
        sentence1[i] = tolower(sentence1[i]);
    }

    for (int i = 0; i < sizeof(sentence2); i++) {
        sentence2[i] = tolower(sentence2[i]);
    }
    
    if (strcmp(sentence1, sentence2) == 0) {
        cout << "Ciągi znaków są identyczne." << endl;
    } else {
        cout << "Ciągi znaków są różne." << endl;
    }
    
    return 0;
}