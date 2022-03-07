// Vacation Account.H

#ifndef VacationAccount_h
#define VacationAccount_h

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>
#include "BloodDonation.h"

using namespace std;

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
};

bool verify_employee (BloodDonation method_name);


#endif /* VacationAccount_h */
