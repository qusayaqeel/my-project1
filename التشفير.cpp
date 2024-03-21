// CS112_A2_T2_S7,8_20230205_20230179_20230722
// To secure user's information
// Abdelrhman Amgad Ali(S7)_Qossay Mohammed Mahmoud Aqil(S7)_Somaya Amr Abd El-ghfour(S8)
// Abdelrhman Amgad Ali(Simple Substitution cipher)_Qossay Mohammed Mahmoud Aqil(Atbash Cipher)_Somaya Amr Abd El-ghfour(Rail-fence Cipher)
// Abdelrhman Amgad Ali(abdelrhmanwork589@gmail.com)_Qossay Mohammed Mahmoud Aqil(qsyqyl1000@gmail.com)_Somaya Amr Abd El-ghfour(Somayaamr857@gmail.com)
// 20230205(Simple Substitution cipher)_20230179(Rail-fence Cipher)_20230722(Atbash Cipher)
// REGARDING "Rail-fence Cipher" the author of the program(Somaya Amr Abd El-ghfour)had some problems while coding it, and will send the corrected program surely as soon as possible.

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to perform encryption using a simple cipher
string cryption() {
    string sentence;
    cout << "Enter the sentence you want to encrypt :";
    getline(cin, sentence);
    for (int i = 0; i < sentence.length(); ++i) {
        // Encrypt alphabetic characters using Atbash Cipher
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
            char base = (sentence[i] >= 'a' && sentence[i] <= 'z') ? 'a' : 'A';
            sentence[i] = char(base + 'z' - sentence[i]);
        }
    }
    return sentence;
}
// Function to perform decryption using the Atbash Cipher
string Decryption_v1() {
    string sentence;
    cout << "Enter the sentence you want to decode: ";
    getline(cin, sentence);
    for (int i = 0; i < sentence.length(); ++i) {
        // Decrypt alphabetic characters using Atbash Cipher
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
            char base = (sentence[i] >= 'a' && sentence[i] <= 'z') ? 'a' : 'A';
            sentence[i] = char(base + 'z' - sentence[i]);
        }
    }
    return sentence;
}
// Function to perform decryption using the Atbash Cipher (alternative version)
string Decryption_v2() {
    string sentence;
    cout << "Enter the sentence you want to decrypt: ";
    getline(cin, sentence);
    for (int i = 0; i < sentence.length(); ++i) {
        // Decrypt alphabetic characters using Atbash Cipher
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
            char base = (sentence[i] >= 'a' && sentence[i] <= 'z') ? 'a' : 'A';
            sentence[i] = char(base + 'z' - sentence[i]);
        }
    }
    return sentence;
}
// Function to encrypt a message using the Substitution Cipher
string encryptWithSubstitutionCipher(string keyword, string plaintext) {
    char plain_alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string encrypted = "";
    char cipher_alphabets[26];
    int x = 0;
    // Generate the cipher alphabet based on the keyword
    for (char ch : keyword) {
        cipher_alphabets[x++] = tolower(ch);
    }
    for (char ch : plain_alphabets) {
        if (find(cipher_alphabets, cipher_alphabets + x, ch) == cipher_alphabets + x) {
            cipher_alphabets[x++] = ch;
        }
    }
    // Encrypt the plaintext message
    for (char ch : plaintext) {
        char character1 = tolower(ch);
        auto it = find(plain_alphabets, plain_alphabets + 26, character1);
        if (it != plain_alphabets + 26) {
            char character2 = cipher_alphabets[it - plain_alphabets];
            encrypted += character2;
        } else {
            encrypted += character1;
        }
    }
    return encrypted;
}
// Function to decrypt a message using the Substitution Cipher
string decryptWithSubstitutionCipher(string keyword, string ciphertext) {
    char plain_alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string decrypted = "";
    char cipher_alphabets[26];
    int x = 0;
    // Generate the cipher alphabet based on the keyword
    for (char ch : keyword) {
        cipher_alphabets[x++] = tolower(ch);
    }
    for (char ch : plain_alphabets) {
        if (find(cipher_alphabets, cipher_alphabets + x, ch) == cipher_alphabets + x) {
            cipher_alphabets[x++] = ch;
        }
    }
    // Decrypt the ciphertext message
    for (char ch : ciphertext) {
        char character1 = tolower(ch);
        auto it = find(cipher_alphabets, cipher_alphabets + 26, character1);
        if (it != cipher_alphabets + 26) {
            char character2 = plain_alphabets[it - cipher_alphabets];
            decrypted += character2; // Keep the case of the original character
        } else {
            decrypted += character1;
        }
    }
    return decrypted;
}
// Main function to handle user input and interactions
int main() {
    string keyword, plaintext, ciphertext;
    cout << "Welcome to the Cipher Toolbox" << endl;
    string choice;
    while (true){
        cout << "\nMain Menu:" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == "1") {
            string encryptChoice;
            cout << "\nEncryption Menu:" << endl;
            cout << "1. Atbash Cipher" << endl;
            cout << "2. Substitution Cipher" << endl;
            cout << "3. Rail-fence Cipher" << endl;
            cout << "4. Main Menu" << endl;
            cout << "\nEnter your choice: ";
            cin >> encryptChoice;
            if (encryptChoice == "1") {
                getline(cin, plaintext);
                string encryptedtext = cryption();
                cout << "encrypted text: " << encryptedtext << endl;
            } else if (encryptChoice == "2") {
                cout << "Enter the keyword: ";
                cin >> keyword; // Prompt user to enter the keyword
                cout << "Enter the line you want to encrypt: ";
                cin.ignore();
                getline(cin, plaintext);
                string encryptedtext = encryptWithSubstitutionCipher(keyword, plaintext);
                cout << "encrypted text: " << encryptedtext << endl;
            } else if (encryptChoice == "3") {
                cout << "This code is under development";
            } else if (encryptChoice == "4") {
                cout << "Returning to Main Menu..." << endl;
            } else {
                cout << "Please enter a valid choice" << endl;
            }
        } else if (choice == "2") {
            string decryptChoice;
            cout << "\nDecryption Menu:" << endl;
            cout << "1. Atbash Cipher" << endl;
            cout << "2. Substitution Cipher" << endl;
            cout << "3. Rail-fence Cipher" << endl;
            cout << "4. Main Menu" << endl;
            cout << "\nEnter your choice: ";
            cin >> decryptChoice;
            if(decryptChoice == "1"){
                while(true){
                    cout << "\nAtbash Cipher:" << endl;
                    cout << "1. Decrypt v1.0" << endl;
                    cout << "2. Decrypt v2.0" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if(choice == "1"){
                        getline(cin, ciphertext);
                        string decryptedText = Decryption_v1();
                        cout << "Decrypted text: " << decryptedText << endl;
                        break;
                    } else if(choice == "2") {
                        getline(cin, ciphertext);
                        string decryptedText = Decryption_v2();
                        cout << "Decrypted text: " << decryptedText << endl;
                        break;
                    } else {
                        cout << "Please enter a valid choice";
                    }
                }
            }else if (decryptChoice == "2") {
                cout << "Enter the keyword: ";
                cin >> keyword; // Prompt user to enter the keyword
                cout << "Enter the line you want to decrypt: ";
                cin.ignore();
                getline(cin, ciphertext);
                string decryptedText = decryptWithSubstitutionCipher(keyword, ciphertext);
                cout << "Decrypted text: " << decryptedText << endl;
            }else if(decryptChoice == "3"){
                cout << "This code is under development";
            }
        } else if (choice == "3") {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Please enter a valid choice";
        }
    }
    return 0;
}
