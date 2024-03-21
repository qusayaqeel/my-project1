// CS112_A2_T2_S7,8_20230205_20230179_20230722
// Calculator for rational numbers
// Abdelrhman Amgad Ali(S7)_Qossay Mohammed Mahmoud Aqil(S7)_Somaya Amr Abd El-ghfour(S8)
// Abdelrhman Amgad Ali(abdelrhmanwork589@gmail.com)_Qossay Mohammed Mahmoud Aqil(qsyqyl1000@gmail.com)_Somaya Amr Abd El-ghfour(Somayaamr857@gmail.com)
// ID1: 20230205 - Handling the input
// ID2: 20230722 - Addition and Subtraction
// ID3: 20230179 - Multiplication and Division

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include<algorithm>
using namespace std;

// Function to perform subtraction of rational numbers
void subtraction(string first_nomi, string first_deno, string second_nomi, string second_deno) {
    // Variables to store the result
    string result;
    // Calculate the numerator and denominator after subtraction
    int operation_nomi = (stoi(first_nomi) * stoi(second_deno)) - (stoi(first_deno) * stoi(second_nomi));
    int operation_deno = stoi(second_deno) * stoi(first_deno);
    // Find the greatest common divisor to simplify the result
    int gcd = __gcd(operation_nomi, operation_deno);
    operation_nomi /= gcd;
    operation_deno /= gcd;
    // Check if the result is an integer or a fraction and print accordingly
    if (operation_deno == 1) {
        cout << "Your result = " << operation_nomi << endl;
    } else {
        cout << "Your result = " << operation_nomi << "/" << operation_deno << endl;
    }
}

// Function to perform addition of rational numbers
void addition(string first_nomi, string first_deno, string second_nomi, string second_deno) {
    // Variables to store the result
    string result;
    // Calculate the numerator and denominator after addition
    int operation_nomi = (stoi(first_nomi) * stoi(second_deno)) + (stoi(first_deno) * stoi(second_nomi));
    int operation_deno = stoi(second_deno) * stoi(first_deno);
    // Find the greatest common divisor to simplify the result
    int gcd = __gcd(operation_nomi, operation_deno);
    operation_nomi /= gcd;
    operation_deno /= gcd;
    // Check if the result is an integer or a fraction and print accordingly
    if (operation_deno == 1) {
        cout << "Your result = " << operation_nomi << endl;
    } else {
        cout << "Your result = " << operation_nomi << "/" << operation_deno << endl;
    }
}

// Function to perform multiplication of rational numbers
void multiplication(string first_nomi, string first_deno, string second_nomi, string second_deno) {
    // Variables to store the result
    string result;
    // Calculate the numerator and denominator after multiplication
    int operation_nomi = stoi(first_nomi) * stoi(second_nomi);
    int operation_deno = stoi(second_deno) * stoi(first_deno);
    // Find the greatest common divisor to simplify the result
    int gcd = __gcd(operation_nomi, operation_deno);
    operation_nomi /= gcd;
    operation_deno /= gcd;
    // Check if the result is an integer or a fraction and print accordingly
    if (operation_deno == 1) {
        cout << "Your result = " << operation_nomi << endl;
    } else {
        cout << "Your result = " << operation_nomi << "/" << operation_deno << endl;
    }
}

// Main function
int main() {
    // Display welcome message
    cout << "================================\n== Rational Number Calculator ==\n================================\n";
    // Infinite loop until user exits
    while (true) {
        cout << "Please enter the operation (or press 'q' to exit): ";
        // Variables to store user input and fractions
        string input, first_nomi, first_deno, second_nomi, second_deno;
        // Read user input
        getline(cin, input);
        // Check if user wants to quit
        if(input == "q"){
            cout << "Exiting.....";
            break;
        }
        // Parse the input to extract fractions and operation
        istringstream v1(input);
        getline(v1, first_nomi, '/');
        getline(v1, first_deno, ' ');
        input.erase(0,(first_nomi.length() + first_deno.length() + 2));
        char operation = input[0];
        input.erase(0,2);
        istringstream v2(input);
        getline(v2, second_nomi, '/');
        getline(v2, second_deno, ' ');
        // Check for division by zero
        if(first_deno == "0" || second_deno == "0") {
            cout << "Please enter a valid input\nthe denominator should not be equal 0\nEnter your input here: ";
            continue;
        }
        // Check if input contains only digits and signs
        string array[4] = {first_nomi, first_deno, second_nomi, second_deno};
        bool valid = true;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < array[i].length(); ++j) {
                if (!isdigit(array[i][j]) && array[i][j] != '-') {
                    valid = false;
                    break;
                }
            }
        }
        // If input is invalid, ask for valid input
        if (!valid) {
            cout << "Please enter a valid input\nIt should be like this: 1/2 + 3/2\nEnter your input here: ";
            continue;
        }
        // Perform the appropriate operation based on the operator
        if (operation == '+') {
            addition(first_nomi, first_deno, second_nomi, second_deno);
        } else if (operation == '-') {
            subtraction(first_nomi, first_deno, second_nomi, second_deno);
        } else if (operation == '*') {
            multiplication(first_nomi, first_deno, second_nomi, second_deno);
        } else if (operation == '/') {
            if (stoi(second_nomi) == 0) {
                cout << "please input a valid operation";
            }
            else {
                multiplication(first_nomi, first_deno, second_deno, second_nomi);
            }
        } else {
            cout << "Please enter a valid input\nIt should be like this:1/2 + 3/2\nEnter your input here: ";
            continue;
        }
        cout << "thanks for using our calculator we hope that you find it useful";
    }
    return 0;
}

//1.	Display welcome message and instructions for the Rational Number Calculator.
//•	LOOP.
//•	Take your calculation from the user or let him exit by clicking” q”.
//•	Parse the input to extract the numerator and denominator of the first and second fractions and the operation.
//•	If any denominator in the calculation ==0 display an error message and let him take other chances.
//•	Let the operators at the calculation lead to the user's desired operation:
//•	Check if the input contains only digits and a possible sign.
//•	If the operation is '+', call the addition function.
//•	If the operation is '-', call the subtraction function.
//•	If the operation is '*', call the multiplication function.
//•	If the operation is '/', call the division function which is {the multiplication function with the second fraction's numerator and denominator swapped}.
//
//•	1: addition function
//•	Transform the input into integers.
//•	Perform the addition operation: (first numerator * second denominator) + (first denominator * second numerator).
//•	Simplify the result.
//•	Print the result when the function is called.
//•	2: subtraction function
//•	Transform the input into integers.
//•	Perform the addition operation: (first nominator * second denominator) - (first denominator * second nominator).
//•	Simplify the result.
//•	Print the result when the function is called.
//•	3: multiplication function
//•	Transform the input into integers.
//•	Perform the addition operation :(first nominator*second nominator)/(first denominator*second denominator)
//•	Simplify the result.
//•	Print the result when the function is called.
//•	4: division function
//•	It Is the multiplication function with the second fraction's numerator and denominator swapped.
//•	End loop.
//•	End program with a thanking message.