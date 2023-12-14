#include <iostream>
#include <string>
using namespace std;

char alphabet[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
    int a = 7, b = 7;

    string msg;
    getline(cin,msg);

    string deciphered;

    int aInverse = modInverse(a, 27);

    for (int i = 0; i < msg.length(); i++) {
        if (isalpha(msg[i])) {
            char ch = toupper(msg[i]);
            int index = 0;
            while (ch != alphabet[index]) {
                index++;
            }
            deciphered += alphabet[(aInverse * ((index - b +27)) % 27)];
        } else {
            deciphered += msg[i]; // Keep non-alphabetic characters unchanged
        }
    }

    cout << deciphered;

    return 0;
}
