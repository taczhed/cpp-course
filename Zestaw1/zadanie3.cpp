#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string sentence;
    cout << "Podaj zdanie: ";
    getline(cin, sentence);

    sentence.erase(remove_if(sentence.begin(), sentence.end(), [](char c) { return isspace(c); }), sentence.end()); // remove whitespaces
    transform(sentence.begin(), sentence.end(), sentence.begin(), [](char c) { return tolower(c); }); // toLowerCase

    bool is_palindrome = true;
    int len = sentence.length();
    for (int i = 0; i < len / 2; i++) {
        if (sentence[i] != sentence[len - i - 1]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) {
        cout << "Zdanie jest palindromem" << endl;
    } else {
        cout << "Zdanie nie jest palindromem" << endl;
    }

    return 0;
}