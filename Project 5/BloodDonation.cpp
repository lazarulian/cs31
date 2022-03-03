// Apurva Shah: CS 31 Project 5

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

// Helper function declarations to ensure that the proper parameters are being passed in:
int verifyId (int id_input);
int verifyAge (int age_input);
double verifyWeight (double weight_input);
void print_shit (int id, int age, double weight);

// Class Declaration
class bloodDonation {
    // The class bloodDonation stores employee information such as their ID, their Age, and their Weight
    private:
    int mID;
    int mAge;
    double mWeight;

    public:
    // constructor
    bloodDonation(int actualId, int actualAge, double actualWeight);
    
    // accessors
    int getID();
    int getAge();
    double getWeight();
    
    // mutators
    void setID(int id);
    void setAge(int age);
    void setWeight(double weight);
};

bloodDonation::bloodDonation(int actualId, int actualAge, double actualWeight) {
    mID = verifyId(actualId);
    mAge = verifyAge(actualAge);
    mWeight = verifyWeight(actualWeight);
}


// Accessor Implementations
int bloodDonation::getID() {
    return mID;
}

int bloodDonation::getAge() {
    return mAge;
}

double bloodDonation::getWeight() {
    return mWeight;
}


// Mutator Implementations
void bloodDonation::setID(int id) {
    mID = verifyId(id);
}
void bloodDonation::setAge(int age) {
    mAge = verifyAge(age);
}
void bloodDonation::setWeight(double weight) {
    mWeight = verifyWeight(weight);
}

// MAIN FUNCTION
int main() {
    
    
    bloodDonation employee1(267899, 24, 269.34);
    
    print_shit(employee1.getID(), employee1.getAge(), employee1.getWeight());
    
    return 0;
}





// Helper function implementation

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


void print_shit (int id, int age, double weight) {
    cout << "ID: " << id << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
}
