#include <iostream>
#include <string>
using namespace std;

const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,;:'\"?!";

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
    getline(cin, msg);

    string deciphered;

    int aInverse = modInverse(a, 72); // 72 is the size of the alphabet array

    for (int i = 0; i < msg.length(); i++) {
        char ch = msg[i];
        int index = 0;
        for (int j = 0; j < 72; j++) {
            if (ch == alphabet[j]) {
                index = j;
                break;
            }
        }
        deciphered += alphabet[(aInverse * (index - b + 72)) % 72];
    }
    
    
    

    cout << deciphered<<endl;
    
    
    
    
    
    
    
    string ciphered;
    
    for (int i = 0; i < msg.length(); i++) {
        char ch = deciphered[i];
        int index = 0;
        for (int j = 0; j < 72; j++) {
            if (ch == alphabet[j]) {
                index = j;
                break;
            }
        }
        ciphered += alphabet[(a * (index) +b) % 72];
    }
    
        cout << ciphered<<endl;

    

    return 0;
}
