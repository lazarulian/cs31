#include "VacationAccount.h"
#include "BloodDonation.h"
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