#include <iostream>

using namespace std;

class A {
private:
    int i;

public:
    A(int value = 0) : i(value) {}

    A operator++() {
        ++i;
        return *this;
    }

    A operator++(int) {
        A temp = *this;
        ++(*this);
        return temp;
    }

    A operator--() {
        --i;
        return *this;
    }

    A operator--(int) {
        A temp = *this;
        --(*this);
        return temp;
    }

    A operator+() const {
        return *this;
    }

    A operator-() const {
        return A(-i);
    }

    A operator+(const A& other) const {
        return A(i + other.i);
    }

    A operator-(const A& other) const {
        return A(i - other.i);
    }

    int getValue() const {
        return i;
    }
};

int main() {
    A obj1(5);
    A obj2(3);

    A obj3 = +obj1;
    cout << "obj3: " << obj3.getValue() << endl;

    A obj4 = -obj1; 
    cout << "obj4: " << obj4.getValue() << endl;

    A obj5 = obj1 + obj2; 
    cout << "obj5: " << obj5.getValue() << endl;

    A obj6 = obj1 - obj2; 
    cout << "obj6: " << obj6.getValue() << endl;

    ++obj1;
    cout << "obj1 po preinkrementacji: " << obj1.getValue() << endl;

    obj2++;
    cout << "obj2 po postinkrementacji: " << obj2.getValue() << endl;

    --obj1;
    cout << "obj1 po predekrementacji: " << obj1.getValue() << endl;

    obj2--;
    cout << "obj2 po postdekrementacji: " << obj2.getValue() << endl;

    A obj(5);
    A result = ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++obj; // i jest 65 w sumie
    cout << "obj po multipreinkrementacji: " << result.getValue() << endl;


    return 0;
}