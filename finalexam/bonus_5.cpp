// Project 5: Apurva Shah

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

// Declaring The Classes so they can identify each other in the main function
class BloodDonation;
class VacationAccount;

// Helper function declarations to ensure that the proper parameters are being passed in:
int verifyId (int id_input);
int verifyAge (int age_input);
double verifyWeight (double weight_input);
void print_stuff (int id, int age, double weight);
bool verify_employee (BloodDonation method_name);
bool verify_bonus_employee (BloodDonation method_name);

// Class Declaration Blood Donation
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



// Class Declaration VacationAccount

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
    bool addVacationToAccount(BloodDonation donation);
    bool bonusHours(BloodDonation donation);
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
bool VacationAccount::addVacationToAccount(BloodDonation donation) {
    if (verify_employee(donation) == true) {
        mBalance = mBalance + 4.00;
        return true;
    }
    
    else {
        return false;
    }
}

bool VacationAccount::bonusHours(BloodDonation donation) {
    if (verify_bonus_employee(donation) == true) {
        mBalance = mBalance + 10;
        return true;
    }
    else {
        return false;
    }
}


// MAIN FUNCTION
int main () {
    

VacationAccount account100 (314122);
BloodDonation doner100(314122, 56, 164.77);
assert(account100.addVacationToAccount(doner100) == true);
assert(account100.getBalance() == 4.000000);
assert(account100.bonusHours(doner100) == true);
assert(account100.getBalance() == 14.000000);

// Here is an example of no bonus because of doner's age:
VacationAccount account101 (315122);
BloodDonation doner101(315122, 35, 141.07);
assert(account101.addVacationToAccount(doner101) == true);
assert(account101.getBalance() == 4.000000);
assert(account101.bonusHours(doner101) == false);
assert(account101.getBalance() == 4.000000);

// Here is an example of no bonus because of an invalid employee ID:
VacationAccount account102 (315);
BloodDonation doner102(315, 59, 142.18);
assert(account102.bonusHours(doner102) == false);
    
    
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

bool verify_bonus_employee (BloodDonation method_name) {
    if (method_name.getID() != -1 && method_name.getAge() != -1 && method_name.getWeight() != -1) {
        if (method_name.getAge() > 55 && method_name.getAge() < 65) {
            return true;
        }
        else {
            return false;
        }
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