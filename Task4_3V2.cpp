#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,;:'\"?!";

int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // Modular inverse doesn't exist
}

int main() {
    int a = 7, b = 2;

    string msg;
    getline(cin, msg); // Allowing input with spaces and multiple lines

    string deciphered;

    int aInverse = modInverse(a, 66); // 66 is the size of the alphabet array

    for (char ch : msg) {
        if (isalnum(ch) || ispunct(ch) || isspace(ch)) {
            size_t index = 0;
            while (ch != alphabet[index]) {
                index++;
            }
            deciphered += alphabet[(aInverse * (index - b + 66)) % 66];
        } else {
            deciphered += ch; // Keep non-alphanumeric characters unchanged
        }
    }

    cout << deciphered;

    return 0;
}
