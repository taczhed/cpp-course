#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int m, n, p;
    ifstream fileA("./files/macierz_A.txt");
    ifstream fileB("./files/macierz_B.txt");
    ofstream fileC("./files/macierz_C.txt");
    
    fileA >> m >> n;
    fileB >> n >> p;
    
    // macierze
    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(p));
    
    // Wczytywanie macierzy A i B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fileA >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            fileB >> B[i][j];
        }
    }
    
    // Mnożenie macierzy A i B
    vector<vector<int>> C(m, vector<int>(p));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    // Zapisywanie macierzy C do pliku
    fileC << m << " " << p << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            fileC << C[i][j] << " ";
        }
        fileC << endl;
    }
    
    fileA.close();
    fileB.close();
    fileC.close();
    
    return 0;
}