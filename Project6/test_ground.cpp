#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int slap_string(string date_input);
bool verify_date(string date_input);
bool verify_history(vector<int> dates_donated);
int convert_month_int (string input, int type);


int main() {

    vector<int> Score;

    Score.push_back(122221);
    Score.push_back(122226);

    cout << verify_history(Score) << endl;

    Score.push_back(012222);

    cout << verify_history(Score) << endl;


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


bool verify_history(vector<int> dates_donated) {
    int last = dates_donated[dates_donated.size()-1];
    int second_last = dates_donated[dates_donated.size()-2];

// Donated the same day 
    if (last == second_last) {
        return false;
    }

    string last_string = to_string(last);
    string second_last_string = to_string(second_last);

    // Verify That Employees Cannot Donate More than Once in Six Months

    if (abs(convert_month_int(last_string, 0)-convert_month_int(second_last_string, 0)) == 6) {
        if (convert_month_int(last_string, 0)<=convert_month_int(second_last_string, 0)) {
            return false;
        }
    }

    else if (abs(convert_month_int(last_string, 0)-convert_month_int(second_last_string, 0)) < 6) {
        return false;
    }

    return true;

}

int convert_month_int (string input, int type) {
    int value = 0;
    char month_last_first = 'd';
    char month_last_second = 'd';
    if (type == 0) {
            char month_last_first = input[0];
            char month_last_second = input[1];
            string last_month = string(1,month_last_first)+month_last_second;
    
            stringstream geek(last_month);
            geek >> value;
            return value;
    }
    else {
            char month_last_first = input[2];
            char month_last_second = input[3];
            string last_month = string(1,month_last_first)+month_last_second;

            stringstream geek(last_month);
            geek >> value;
            return value;
    }
}