#include <iostream>
#include <filesystem>

using namespace std;

// /home/taczhed/Systemy/Zadanie1/src

int main() {
    string path;
    bool isEmpty = true;

    cout << "Podaj sciezke do katalogu: ";
    cin >> path;

    filesystem::path dirPath(path);

    if (!filesystem::exists(dirPath)) {
        cout << "Podany katalog nie istnieje" << endl;
        return 1;
    }

    if (!filesystem::is_directory(dirPath)) {
        cout << "Podana sciezka nie jest katalogiem" << endl;
        return 1;
    }

    for (auto file : filesystem::directory_iterator(dirPath)) {
        if (filesystem::is_regular_file(file)) {
            cout << file.path().filename().string() << "\t" << filesystem::file_size(file) << " bytes" << endl;
            isEmpty = false;
        }
    }   

    if (isEmpty) {
        cout << "W podanym katalogu nie ma zwyklych plikow" << endl;
    }

    return 0;
}