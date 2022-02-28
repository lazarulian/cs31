// Apurva Shah: CS 31 Project 4

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cassert>

using namespace std;

int locateMaximum( const string array[ ], int n );
bool checkCapitals(string input);
bool hasNoCapitals( const string array[ ], int n );
bool checkFloating(string input);
bool doesContain(string input, char needle);
int countFloatingPointValues( const string array[ ], int  n );
int shiftLeft( string array[ ], int n, int amount, string placeholder );

int main()
{
    return 0;
}

bool checkCapitals(string input) {
    // Checks a string for capital inputs
    int capital_counter = 0;
    for (int i = 0; i < input.size(); i++) {
        if (int(input[i]) > 64 && int(input[i]) < 91) {
            capital_counter++;
            break;
        }
        else {
            continue;
        }
    }
    if (capital_counter != 0) {
        return false;
    }
    else {
        return true;
    }
}

bool hasNoCapitals( const string array[ ], int n ) {
    // Checks for Capital Values Through Iteration
    if (n <= 0) {
        return true;
    }
    
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (checkCapitals(array[i]) == false) {
            counter++;
            break;
        }
        else {
            continue;
        }
    }
    if (counter != 0) {
        return false;
    }
    else {
        return true;
    }
}


bool doesContain(string input, char needle) {
    // Checks if a string contains a value
    bool value_found = false;
    for (int i = 0; i < input.size(); i++) {
        if (int(input[i]) == int(needle)) {
            value_found = true;
            break;
        }
    }
    return value_found;
}


bool checkFloating(string input) {
    // Will Check the values for a floating point
    // If statement to process non-numerical values + decimal points
    bool isfloating = true;
    int decimal_counter = 0;
    // Checks for non-numerical values and non-decimal values
    for (int i = 0; i < input.size(); i++) {
        if (int(input[i]) < 48 || int(input[i]) > 57) {
            if (int(input[i]) != 46) {
                isfloating = false;
                break;
            }
        }
    }
    
    // Checks for Empty String
    if (input.size() == 0) {
        isfloating = false;
    }
    
    // Checks for Multiple Decimal Points
    for (int i = 0; i < input.size(); i++) {
        if (int(input[i]) == 46) {
            decimal_counter++;
        }
    }
    if(decimal_counter > 1) {
        isfloating = false;
    }
    
    // Checks for the Position of the Decimal Points
    if (doesContain(input, '.') == true) {
        size_t pos = input.find(int('.'));
        if (input.size()-(pos+1) > 7) {
            isfloating = false;
        }
    }
    
    return isfloating;
}

int countFloatingPointValues( const string array[ ], int  n ) {
    if (n<= 0) {
        return -1;
    }
    
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (checkFloating(array[i]) == true) {
            counter++;
        }
        else {
            continue;
        }
    }
    return counter;
}

int shiftLeft( string array[ ], int n, int amount, string placeholder ) {
    // Testing for Values that are invalid
    if (n <= 0 || amount <0) {
        return -1;
    }
    
    // Shifting the Elements Left
    int i = 1;
    for (int k = 1; k <= amount; k++) {
        for (int j = 1; j < n; j++) {
            array[j-1] = array[j]; // Shifts the elements left k times
        }
    }
    
    // Filling Values with Placeholders
    for (int k = (n-1); k >= 0; k--) {
        if (i <= amount) {
            array[k] = placeholder;
            i++;
        }
 }
    if(amount > n) {
        return n;
    }
    
    if (amount == 0) {
        return 0;
    }
 return amount;
}
