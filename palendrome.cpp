#include <iostream>

using namespace std;

int numberDigits(int number) {
    int number_digits = 0;
    while(number > 0) {
        number = number / 10;
        number_digits++;
    }
    return number_digits;
};

bool isPalendrome(int input) {
    bool palendrome;
    string string_input = to_string(input);
    
    for(int i = 0; i < numberDigits(input); i++) {
         // cout << "First string char: " << string_input[i] << endl;
         // cout << "Last string input: " << string_input[numberDigits(input)-(i+1)] << endl;
        if (string_input[i] != string_input[numberDigits(input)-(i+1)]) {
            palendrome = false;
        }
        else {
            palendrome = true;
        }
    }
        return palendrome;
};

int main() {
    int number;
    cout << "Input your number" << endl;
    cin >> number;
    cout << "The number of digits in your number is: " << numberDigits(number) << endl;
    
    bool value = isPalendrome(number);
    
    if(value == true) {
        cout << "This value is a palendrome." << endl;
    }
    
    else {
        cout << "This value is not a palendrome." << endl;
    }
    
    return 0;
}
