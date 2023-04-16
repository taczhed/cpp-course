#include <string>
#include <algorithm>
#include <iostream>

class BigInt {

std::string number;

public:
    BigInt(const std::string& initialValue) : number(initialValue) {}

    BigInt& operator=(const BigInt& other) {
        number = other.number;
        return *this;
    }

    BigInt add(const BigInt& other) const {
        std::string result;
        int carry = 0;
        int i = number.size() - 1;
        int j = other.number.size() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int digit_sum = carry;
            if (i >= 0) {
                digit_sum += number[i] - '0';
                i--;
            }
            if (j >= 0) {
                digit_sum += other.number[j] - '0';
                j--;
            }
            carry = digit_sum / 10;
            result.push_back(digit_sum % 10 + '0');
        }

        std::reverse(result.begin(), result.end());

        while (result[0] == '0') {
            result.erase(0, 1);
        }

        return BigInt(result);
    }

    BigInt subtract(const BigInt& other) const {
        std::string result;
        int borrow = 0;
        int i = number.size() - 1;
        int j = other.number.size() - 1;
        while (i >= 0 || j >= 0) {
            int digit_diff = borrow;
            if (i >= 0) {
                digit_diff += number[i] - '0';
                i--;
            }
            if (j >= 0) {
                digit_diff -= other.number[j] - '0';
                j--;
            }
            if (digit_diff < 0) {
                digit_diff += 10;
                borrow = -1;
            } else {
                borrow = 0;
            }
            result.push_back(digit_diff + '0');
        }

        std::reverse(result.begin(), result.end());

        while (result[0] == '0') {
            result.erase(0, 1);
        }

        return BigInt(result);
    }

    void print() const {
        std::cout << number << std::endl;
    }
};

int main() {
    BigInt number1("1000");
    BigInt number2("1906");

    BigInt sum = number1.add(number2);
    sum.print();

    BigInt sub = number2.subtract(number1);
    sub.print();

    number1 = number2;
    number1.print();

    return 0;
}