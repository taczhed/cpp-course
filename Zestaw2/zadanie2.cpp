#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<int> quicksort(vector<int>& array) {
    if (array.size() <= 1) {
        return array;
    }

    int pivot = array[array.size() / 2];
    vector<int> left;
    vector<int> right;
    vector<int> equal;

    for (long unsigned int i = 0; i < array.size(); i++) {
        if (array[i] < pivot) {
            left.push_back(array[i]);
        }
        else if (array[i] > pivot) {
            right.push_back(array[i]);
        }
        else {
            equal.push_back(array[i]);
        }
    }

    left = quicksort(left);
    right = quicksort(right);

    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

vector<int> numbersGenerator(int amount = 10000) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10000);

    vector<int> array(amount);
    for (int i = 0; i < amount; ++i) {
        array[i] = dist(gen);
    }

    return array;
}

int main() {

    vector<int> shuffledNumbers = numbersGenerator();
    vector<int> sortedNumbers = quicksort(shuffledNumbers);

    cout << "Liczby przed posortowaniem:\n";
    
    for (int i = 0; i < 10000; ++i) {
        cout << shuffledNumbers[i] << " ";
    }

    cout << endl << endl;

    cout << "Posortowane liczby:\n";

    for (int i = 0; i < 10000; ++i) {
        cout << sortedNumbers[i] << " ";
    }

    cout << endl << endl;

    return 0;
}