#include "VacationAccount.h"
#include "DonationHistory.h"

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

bool verify_employee (BloodDonation method_name) {
    // Verifies that a blood donation can occur
    if (method_name.getID() != -1 && method_name.getAge() != -1 && method_name.getWeight() != -1) {
        return true;
    }
    else {
        return false;
    }
}