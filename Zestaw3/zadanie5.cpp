#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

// zainstalowany openssl + dodatkowe flagi kompilacji -lssl -lcrypto (u mnie na wsl)

const long int MAX_NONCE = 100000000000;

string SHA256(string text) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, text.c_str(), text.size());
    SHA256_Final(hash, &sha256);
    string result = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buf[3];
        sprintf(buf, "%02x", hash[i]);
        result += buf;
    }
    return result;
}

string mine(int block_number, string transactions, string previous_hash, int prefix_zeros) {
    string prefix_str = string(prefix_zeros, '0');
    for(int nonce = 0; nonce < MAX_NONCE; nonce++) {
        string text = to_string(block_number) + transactions + previous_hash + to_string(nonce);
        string new_hash = SHA256(text);
        if(new_hash.substr(0, prefix_zeros) == prefix_str) {
            cout << "Udało się wydobyć bitcoiny z wartością nonce równą: " << nonce << endl;
            return new_hash;
        }
    }
    throw runtime_error("Nie udało się znaleźć poprawnego hasha po " + to_string(MAX_NONCE) + " próbach");
}

int main() {
    string transactions = "Dhaval->Bhavin->20,Mando->Cara->45";
    int difficulty = 5; // dla 6 czas to 9.67 sekund, dla 5 czas to 0.24

    cout << "Rozpoczęcie wydobywania..." << endl;
    auto start = chrono::system_clock::now();

    string new_hash = mine(5, transactions, "0000000xa036944e29568d0cff17edbe038f81208fecf9a66be9a2b8321c6ec7", difficulty);

    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Zakończono wydobywanie. Czas wydobycia: " << elapsed_seconds.count() << " sekund" << endl;
    cout << "Hash: " << new_hash << endl;
    return 0;
}