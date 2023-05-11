#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class TComplex {
public:
    TComplex(double re, double im) : re(re), im(im) {}

    TComplex operator()(double re, double im) {
        return TComplex(re, im);
    }

    TComplex operator+(const TComplex& other) {
        return TComplex(re + other.re, im + other.im);
    }

    TComplex operator-(const TComplex& other) {
        return TComplex(re - other.re, im - other.im);
    }

    TComplex operator*(const TComplex& other) {
        return TComplex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    TComplex operator/(const TComplex& other) {
        double denominator = other.re * other.re + other.im * other.im;
        double realPart = (re * other.re + im * other.im) / denominator;
        double imaginaryPart = (im * other.re - re * other.im) / denominator;
        return TComplex(realPart, imaginaryPart);
    }

    TComplex conj() const {
        return TComplex(re, -im);
    }

    double abs() const {
        return sqrt(re * re + im * im);
    }

    friend ostream& operator<<(ostream& os, const TComplex& complex) {
        os << "(" << complex.re << "," << complex.im << ")";
        return os;
    }

private:
    double re = 0, im = 0;
};

int main() {
    TComplex c1(2, 3);
    TComplex c2 = c1(4, 5);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    TComplex suma = c1 + c2;
    TComplex roznica = c1 - c2;
    TComplex iloczyn = c1 * c2;
    TComplex iloraz = c1 / c2;

    cout << "Suma: " << suma << endl;
    cout << "Różnica: " << roznica << endl;
    cout << "Iloczyn: " << iloczyn << endl;
    cout << "Iloraz: " << iloraz << endl;

    TComplex sprzezenie = c1.conj(); 
    double wartoscBezwzgledna = c1.abs();

    cout << "Sprzężenie liczby c1: " << sprzezenie << endl;
    cout << "Wartość bezwzględna liczby c1: " << wartoscBezwzgledna << endl;

    return 0;
}