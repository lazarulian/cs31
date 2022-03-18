#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int slap_string(string date_input);
bool verify_date(string date_input);


int main() {


    // string date = "12/22/21";

    // int date_converted = slap_string(date);

    // cout << date_converted << endl;

    cout << verify_date("12/22/21") << endl;


    return 0;
} 


bool verify_date(string date_input) {
    int counter = 0;
    // String Size Is Incorrect
    if (date_input.size() != 8) {
        return false;
    }

    // Slashes are in the correct space

    if (date_input[2] != int('/') || date_input[5] != int('/')) {
        return false;
    }

    for (int i = 0; i < date_input.size(); i++) {
        if (date_input[i] >= int('0') && date_input[i] <= int('9')) {
            counter++;
        }
    }

    if (counter != 6) {
        return false;
    }

    return true;
}

int slap_string(string date_input) {
    int date = 0;
    date_input.erase(date_input.begin()+2);
    date_input.erase(date_input.begin()+4);
    stringstream geek(date_input);
    
    geek >> date;

    return date;
}

