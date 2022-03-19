#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <vector>

#include "BloodDonation.h"
#include "DonationHistory.h"
#include "VacationAccount.h"
#include "CovidHistory.h"

using namespace std;

// MAIN FUNCTION
int main () {
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