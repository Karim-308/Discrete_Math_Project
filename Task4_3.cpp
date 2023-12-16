#include <iostream>
#include <string>
using namespace std;



/*  This is task 4 code for team 3
*   Done by Karim Ibrahim Saad Abd-Elrazek
*   ID: 20011118
*
*   Our keys are a = 7 and b = 7
* 
*   Our input msg is ELYPCOGLIOGOXOQTGXDF
* 
*   the output before extending more the space
*   character and Capital letter is 
* 
*   ---STRIKE THE ENEMY NOW---
* 
*   after extending to small , digits and 
*   special characters the output is 
* 
*   ---MN(>Zo N=o ocob2 c%0---
*   
*/


// This is our supported list of Capital characters with th space character as the letter with number 0
// The size of this array is 27 character
char alphabet[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";


// This is our supported list of Capital characters with th space character as the letter with number 0
// in addition  to small , digits and special characters
// The size of this array is 93 character
const char alphabet_Exented[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&'()*+,-./:;<=>?@[]^_`{|}~";




/**
 * @brief Calculate the modular inverse of a number 'base' under modulo 'mod'.
 *
 * The modular inverse of 'base' under modulo 'mod' is an integer 'result' such that (base * result) % mod = 1.
 * This function uses a brute-force approach to find the modular inverse.
 *
 * @param base The number for which the modular inverse is to be calculated.
 * @param mod The modulus.
 * @return The modular inverse of 'base' under modulo 'mod', or -1 if no such inverse exists.
 */
int modInverse(int base, int mod) {
    // Iterate through possible values of 'result' from 1 to 'mod - 1'.
    for (int result = 1; result < mod; result++) {
        // Check if (base * result) % mod equals 1, indicating a modular inverse is found.
        if ((base * result) % mod == 1) {
            return result; // Return the found modular inverse 'result'.
        }
    }
    
    // If the loop completes without finding a modular inverse, return -1.
    return -1; // Modular inverse doesn't exist
}




/**
 * @brief Decipher a message using the Affine Cipher with the given parameters.
 *
 * The Affine Cipher is a type of monoalphabetic substitution cipher, where each letter
 * in the plaintext is mapped to its numeric equivalent, encrypted, and then converted back to a letter.
 * This function performs the decryption using the Affine Cipher with parameters 'a' and 'b'.
 *
 * @param msg The message to be deciphered.
 * @param a The multiplicative key in the Affine Cipher.
 * @param b The additive key in the Affine Cipher.
 * @return The deciphered message.
 */
string decipher(string msg, int a, int b) {
    string deciphered;

    // Calculate the modular inverse of 'a' under modulo 27.
    int aInverse = modInverse(a, 27);

    // Iterate through each character in the message.
    for (int i = 0; i < msg.length(); i++) {
        int index = 0;

        // Find the index of the current character in the alphabet.
        while (msg[i] != alphabet[index]) {
            index++;
        }

        // Apply the Affine Cipher decryption formula and append the result to the deciphered message.
        deciphered += alphabet[aInverse * (index - b +27 ) % 27];
    }

    // Return the deciphered message.
    return deciphered;
}

/**
 * @brief Decipher an extended message using the Affine Cipher with the given parameters.
 *
 * This function does the same functionality for the previous one
 * but it uses the alphabet_Exented character array which includes
 * space character , calculated , small, and special characters.
 *
 * @param msg The extended message to be deciphered.
 * @param a The multiplicative key in the Affine Cipher.
 * @param b The additive key in the Affine Cipher.
 * @return The deciphered extended message.
 */
string decipherExtended(string msg, int a, int b) {
    string deciphered;

    // Calculate the modular inverse of 'a' under modulo 93.
    int aInverse = modInverse(a, 93);

    // Iterate through each character in the extended message.
    for (int i = 0; i < msg.length(); i++) {
        int index = 0;

        // Find the index of the current character in the extended alphabet.
        while (msg[i] != alphabet_Exented[index]) {
            index++;
        }

        // Apply the Affine Cipher decryption formula and append the result to the deciphered message.
        deciphered += alphabet_Exented[aInverse * (index - b + 93) % 93];
    }

    // Return the deciphered extended message.
    return deciphered;
}

int main() {
    // Define the Affine Cipher parameters.
    int a = 7, b = 7;
    
    // Asking the user to enter the message
    cout<<"Enter the message to be deciphered\n";
    
    // Get the message from the user.
    // in our case, it should be ELYPCOGLIOGOXOQTGXDF
    string msg;
    getline(cin, msg);

    // Decipher the message using the standard Affine Cipher.
    string deciphered = decipher(msg, a, b);

    // Print the deciphered message.
    // ---STRIKE THE ENEMY NOW---
    cout << "Deciphered: " << deciphered << endl;

    // Decipher the message using the extended Affine Cipher on the extended alphabet.
    string decipheredExtended = decipherExtended(msg, a, b);

    // Print the deciphered extended message.
    //---MN(>Zo N=o ocob2 c%0---
    cout << "Deciphered Extended: " << decipheredExtended << endl;

    return 0;
}
