#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int gcd(int a, int b)
{
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
}

int encrypt(int msg, int e, int n)
{
    int ciphertext = 1;
    for (int i = 0; i < e; i++) {
        ciphertext = (ciphertext * msg) % n;
    }
    return ciphertext;
}

int decrypt(int msg, int d, int n)
{
    int plaintext = 1;
    for (int i = 0; i < d; i++) {
        plaintext = (plaintext * msg) % n;
    }
    return plaintext;
}

int main()
{
    int p, q, msg; // defaultowe dane 17 19 

    cout << "Wpisz liczby w formacie -> p q : ";
    cin >> p >> q;
    cout << "Wiadomość do zaszyfrowania: ";
    cin >> msg;

    if (!isPrime(p) || !isPrime(q)) {
        cout << "Podane liczby nie są liczbami pierwszymi!" << endl;
        return 1;
    }

    if (p * q < msg) {
        cout << "Wiadomość musi być mniejsza niż iloczyn p * q, czyli " << p * q << endl;
        return 1;
    }


    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }
        e++;
    }

    int d = modInverse(e, phi);

    // Szyfrowanie
    int encrypted = encrypt(msg, e, n);
    cout << "Zaszyfrowana wiadomość: " << encrypted << endl;

    // Odszyfrowanie
    int decrypted = decrypt(encrypted, d, n);
    cout << "Odszyfrowana wiadomość: " << decrypted << endl;

    return 0;
}