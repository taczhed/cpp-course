#include <iostream>

using namespace std;

template<typename T>
class TSmartPtr {
private:
    T* ptr;

public:
    explicit TSmartPtr(T* p) : ptr(p) {}
    ~TSmartPtr() { delete ptr; }

    T* operator->() const { return ptr; }
    T& operator*() const { return *ptr; }
};

class Test {
public:
    void foo() {
        cout << "wywołano funkcję foo()! :)" << endl;
    }
};

int main() {
    TSmartPtr<Test> smartPtr(new Test);

    smartPtr->foo(); // wywołanie metody za pomocą operatora ->
    (*smartPtr).foo(); // wywołanie metody za pomocą operatora *

    return 0;
}