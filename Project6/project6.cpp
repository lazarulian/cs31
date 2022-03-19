// Project 6: Designing your Own Function
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

// Declaring The Classes so they can identify each other in the main function
class BloodDonation;
class DonationHistory;
class VacationAccount;
class CovidHistory;


// Helper function declarations to ensure that the proper parameters are being passed in:
int verifyId (int id_input);
int verifyAge (int age_input);
double verifyWeight (double weight_input);
void print_stuff (BloodDonation donor, VacationAccount account, DonationHistory history, CovidHistory covid);
bool verify_employee (BloodDonation method_name);
int string_to_date(string date_input);
bool verify_date(string date_input);
bool verify_history(vector<int> dates_donated);
int convert_month_int (string input, int type);

///////////////////////////
// BLOOD DONATION CLASS //
//////////////////////////

class BloodDonation {
    // The class bloodDonation stores employee information such as their ID, their Age, and their Weight
    private:
    int mID;
    int mAge;
    double mWeight;

    public:
    // constructor
    BloodDonation(int actualId, int actualAge, double actualWeight);
    
    // accessors
    int getID();
    int getAge();
    double getWeight();
    
    // mutators
    void setID(int id);
    void setAge(int age);
    void setWeight(double weight);
};

BloodDonation::BloodDonation(int actualId, int actualAge, double actualWeight) {
    mID = verifyId(actualId);
    mAge = verifyAge(actualAge);
    mWeight = verifyWeight(actualWeight);
}


// Accessor Implementations
int BloodDonation::getID() {
    return mID;
}

int BloodDonation::getAge() {
    return mAge;
}

double BloodDonation::getWeight() {
    return mWeight;
}


// Mutator Implementations
void BloodDonation::setID(int id) {
    mID = verifyId(id);
}
void BloodDonation::setAge(int age) {
    mAge = verifyAge(age);
}
void BloodDonation::setWeight(double weight) {
    mWeight = verifyWeight(weight);
}

/////////////////////////////
// Donation History Class //
///////////////////////////

class DonationHistory {
    private:
    int employee_id;
    int times_donated;
    vector<int> dates_donated;

    public:
    // constructor
    DonationHistory(int actualID); // should be called every donation or employee ID creation
    
    // accessors
    vector<int> return_hist();
    void getDonationHistory();

    // mutators
    void AddDonationEntry(string donation_date);

};
// Constructor
DonationHistory::DonationHistory(int actualID) {
    int employee_id = verifyId(actualID);
    int times_donated = 0;
}

// Accessor
vector<int> DonationHistory::return_hist() {
    return dates_donated;
}

void DonationHistory::getDonationHistory() {
    cout << "This donor has donated " << times_donated << " times on the following dates: ";
    for (int i = 0; i < dates_donated.size(); i++) {
        string temp = to_string(dates_donated[i]);
        cout << temp[0] << temp[1] << "/" << temp[2] << temp[3] << "/" << temp[4] << temp[5] << ", ";

    }
}

// Mutator
void DonationHistory::AddDonationEntry(string donation_date) {
    // Need to Implement if Date is in past six months or the same day
        int date_placeholder = string_to_date(donation_date);
        dates_donated.push_back(date_placeholder);
        times_donated++;
}

/////////////////////////////
// Vacation Account Class //
///////////////////////////

class VacationAccount {
    // The class VacationAccount stores the amount of vacation hours an employee has based off of the amount of blood they have donated in total
    
    private:
    int mID;
    double mBalance;

    public:
    // constructor
    VacationAccount(int actualID);
    
    // accessors
    int getID();
    double getBalance();
    
    // mutators
    bool addVacationToAccount(BloodDonation donation, DonationHistory history);
};

VacationAccount::VacationAccount(int actualId) {
    mID = verifyId(actualId);
    mBalance = 0.00;
}

// Accessor Functions
int VacationAccount::getID() {
    return mID;
}

double VacationAccount::getBalance() {
    return mBalance;
}

// Mutator Implementations
bool VacationAccount::addVacationToAccount(BloodDonation donation, DonationHistory history) {
    if (verify_employee(donation) == true || verify_history(history.return_hist())) {// add verify donation
        mBalance = mBalance + 4.00;
        return true;
    }
    
    else {
        return false;
    }
}

/////////////////////////////
// Covid History Class    //
///////////////////////////


class CovidHistory {
    private: 
    int employee_id;
    vector<int> covid_history;

    public:

    // Constructor
    CovidHistory() {}
    CovidHistory(int actualID) {
        employee_id = verifyId(actualID);
    } // Constructor Overloading

    // CovidHistory(string positive_date) : CovidHistory() {
    //     if (verify_date(positive_date) == true) {
    //         covid_history.push_back(string_to_date(positive_date));
    //     }
    // } // Constructor Delegation

    // Accessor

    void getCovidHistory(); 

    // Mutator

    void report_positive(string date);
    
};


// Accessor
void CovidHistory::getCovidHistory() {
    cout << "This employee has tested positive for covid-19 on the following dates: ";
    for (int i = 0; i < covid_history.size(); i++) {
        string temp = to_string(covid_history[i]);
        cout << temp[0] << temp[1] << "/" << temp[2] << temp[3] << "/" << temp[4] << temp[5] << ", ";
    }
}

// Mutator

void CovidHistory::report_positive(string date) {
        covid_history.push_back(string_to_date(date));
}

////////////
//  Main //
//////////

int main () {
    // Testing Blood Donation
   BloodDonation sam (705595, 22, 130);
    VacationAccount sam_vacation (705595);
    DonationHistory sam_history (705595);
    CovidHistory sam_covid (705595);
    sam_history.AddDonationEntry("12/19/22");
    sam_vacation.addVacationToAccount(sam, sam_history);
    sam_covid.report_positive("12/19/22");
    assert(to_string(sam.getID()) == "705595"); // Tests if Accurate ID is Given
    assert(to_string(sam.getAge()) == "22"); // Accurate Age
    assert(sam_vacation.getBalance() == 4); // accurate 

    sam_history.AddDonationEntry("12/19/22");
    assert(sam_vacation.getBalance() == 4); // Correct Because the dates are the same and should not be able to add more
    sam_history.AddDonationEntry("01/18/22");
    sam_covid.report_positive("12/29/22");
    sam_covid.getCovidHistory(); // Accurate response, cannot be compared to string literal
    assert(sam_vacation.getBalance() == 4); // Correct because sam has donated within the last six months and cannot donate any more to balance
    sam_history.AddDonationEntry("11/18/22");
    assert(sam_vacation.getBalance() == 4); // Correct Because still six months in the future
    sam_history.AddDonationEntry("12/18/93");
    sam_vacation.addVacationToAccount(sam, sam_history);
    assert(sam_vacation.getBalance() == 8); // Correct because old date

    sam_covid.report_positive("12/29/22");
    sam_covid.getCovidHistory(); // Accurate response, cannot be compared to string literal

    sam_history.AddDonationEntry("12/19/22");
    assert(sam_vacation.getBalance() == 8); // Correct Because the dates are the same and should not be able to add more
    sam_history.AddDonationEntry("12/18/22");
    assert(sam_vacation.getBalance() == 8); // Correct because sam has donated within the last six months and cannot donate any more to balance
    sam_history.AddDonationEntry("12/18/22");
    assert(sam_vacation.getBalance() == 8); // Correct Because still six months in the future
    sam_history.AddDonationEntry("12/18/93");
    sam_vacation.addVacationToAccount(sam, sam_history);
    assert(sam_vacation.getBalance() == 12); // Correct because old date

    sam_history.getDonationHistory();
    sam_covid.report_positive("12/29/22");
    sam_covid.getCovidHistory(); // Accurate response, cannot be compared to string literal

    BloodDonation jeff (26, 1, 22);
    assert(to_string(jeff.getID()) == "-1"); // Tests if Accurate ID is Given
    assert(to_string(jeff.getAge()) == "-1"); // Accurate Weight
    assert(jeff.getWeight() == -1); // Accurate Weight

    return 0;
}























// Helper function implementation for Blood Donation Class

int verifyId (int id_input) {
    // Verifies that the input ID is correct
    string employee_id;
    
    employee_id = to_string(id_input);
    
    // Test Case 1: Length of Employee ID
    if (employee_id.size() != 6){
        return -1;
    }
    
    // Test Case 2: The Digits Within The String
    
    for (int i = 0; i < employee_id.size(); i++) {
        if (employee_id[i] < int('0') || employee_id[i] > int('9')) {
            return -1;
            break;
        }
        else {
            continue;
        }
    }
    return id_input;
}

int verifyAge (int age_input) {
    // Verifies that the age parameters are correct
    
    if (age_input < 21 || age_input > 65 ) {
        return -1;
    }
    
    return age_input;
}

double verifyWeight (double weight_input) {
    // Verifies that the weight parameters are correct
    
    if (weight_input < 101.00 || weight_input > 280.00) {
        return -1;
    }
    return weight_input;
}

bool verify_employee (BloodDonation method_name) {
    // Verifies that a blood donation can occur
    if (method_name.getID() != -1 && method_name.getAge() != -1 && method_name.getWeight() != -1) {
        return true;
    }
    else {
        return false;
    }
}

// Function to help test whether the main is working or not
void print_stuff (BloodDonation donor, VacationAccount account, DonationHistory history, CovidHistory covid) {
    cout << "ID: " << donor.getID() << endl;
    cout << "Age: " << donor.getAge() << endl;
    cout << "Weight: " << donor.getWeight() << endl;

    cout << "Balance: " << account.getBalance() << endl;
    history.getDonationHistory();
    covid.getCovidHistory();
}

int string_to_date(string date_input) {
    int date = 0;
    date_input.erase(date_input.begin()+2);
    date_input.erase(date_input.begin()+4);
    stringstream geek(date_input);
    
    geek >> date;

    return date;
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
        if (int(date_input[i]) >= int('0') && int(date_input[i]) <= int('9')) {
            counter++;
        }
    }

    if (counter != 6) {
        return false;
    }

    return true;
}

bool verify_history(vector<int> dates_donated) {
    int last = dates_donated[dates_donated.size()-1];
    int second_last = dates_donated[dates_donated.size()-2];

// Donated the same day 
    if (dates_donated.size() == 0) {
        return true;
    }

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