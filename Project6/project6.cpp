// Project 6: Designing your Own Function
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

// Declaring The Classes so they can identify each other in the main function
class BloodDonation;
class VacationAccount;
class DonationHistory;

// Helper function declarations to ensure that the proper parameters are being passed in:
int verifyId (int id_input);
int verifyAge (int age_input);
double verifyWeight (double weight_input);
void print_stuff (int id, int age, double weight);
bool verify_employee (BloodDonation method_name);

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
    bool addVacationToAccount(BloodDonation donation, int donation_date);
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
bool VacationAccount::addVacationToAccount(BloodDonation donation, int donation_date) {
    if (verify_employee(donation) == true) {
        mBalance = mBalance + 4.00;
        return true;
    }
    
    else {
        return false;
    }
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
    void getDonationHistory();

    // mutators
    void AddDonationEntry(int donation_date);

};
// Constructor
DonationHistory::DonationHistory(int actualID) {
    ./wr
}

// Accessor
void DonationHistory::getDonationHistory() {
    cout << "This donor has donated " << times_donated << " times on the following dates: ";
    for (int i = 0; i < dates_donated.size(); i++) {
        string temp = to_string(dates_donated[i]);
        cout << temp[0] << temp[1] << "/" << temp[2] << temp[3] << "/" << temp[4] << temp[5] << ", ";

    }
}

// Mutator
void DonationHistory::AddDonationEntry(int donation_date) {
    dates_donated.push_back(donation_date);
    times_donated++;
}

////////////
//  Main //
//////////

int main () {

    BloodDonation sam (705595, 22, 130);

    return 0;
}





// Helper function implementation for Blood Donation Class

int verifyId (int id_input) {
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
    
    if (age_input < 21 || age_input > 65 ) {
        return -1;
    }
    
    return age_input;
}

double verifyWeight (double weight_input) {
    
    if (weight_input < 101.00 || weight_input > 280.00) {
        return -1;
    }
    return weight_input;
}

bool verify_employee (BloodDonation method_name) {
    if (method_name.getID() != -1 && method_name.getAge() != -1 && method_name.getWeight() != -1) {
        return true;
    }
    else {
        return false;
    }
}

// Function to help test whether the main is working or not
void print_stuff (int id, int age, double weight) {
    cout << "ID: " << id << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
}