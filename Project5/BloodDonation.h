// Blood Donation.H

#ifndef BloodDonation_h
#define BloodDonation_h


#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

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

int verifyId (int id_input);
int verifyAge (int age_input);
double verifyWeight (double weight_input);

#endif /* BloodDonation_h */
