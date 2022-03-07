// Vacation Account.cpp

#include "VacationAccount.h"
#include "BloodDonation.h"

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
bool VacationAccount::addVacationToAccount(BloodDonation donation) { // Variable has incomplete type 'BloodDonation'
    if (verify_employee(donation) == true) {
        mBalance = mBalance + 4.00;
        return true;
    }
    
    else {
        return false;
    }
}

bool verify_employee (BloodDonation method_name) { // Variable has incomplete type 'BloodDonation'
    if (method_name.getID() != -1 && method_name.getAge() != -1 && method_name.getWeight() != -1) {
        return true;
    }
    else {
        return false;
    }
}
