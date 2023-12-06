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

string decipherMessage(const string& msg, int a, int b) {
    string deciphered;
    int aInverse = modInverse(a, 66); // 66 is the size of the alphabet array

    for (char ch : msg) {
        if (isalpha(ch)) {
            size_t index = (isupper(ch) ? 0 : 26) + (toupper(ch) - 'A');
            deciphered += alphabet[(aInverse * (index - b + 66)) % 66];
        } else if (isdigit(ch)) {
            size_t index = 52 + (ch - '0'); // Mapping numbers to the second half of the alphabet
            deciphered += alphabet[(aInverse * (index - b + 14)) % 14];
        } else if (ispunct(ch) || isspace(ch)) {
            size_t index = 66 + (ch - ' ');
            deciphered += alphabet[(aInverse * (index - b + 22)) % 22];
        } else {
            deciphered += ch; // Keep non-alphanumeric characters unchanged
        }
    }

    return deciphered;
}

int main() {
    int a = 7, b = 2;

    string msg;
    getline(cin, msg); // Allowing input with spaces and multiple lines

    string decipheredMessage = decipherMessage(msg, a, b);

    cout << "Deciphered Message: " << decipheredMessage << endl;

    return 0;
}
