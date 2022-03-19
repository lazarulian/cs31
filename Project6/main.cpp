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
    sam_history.AddDonationEntry("3/19/22");
    sam_vacation.addVacationToAccount(sam, sam_history);
    sam_covid.report_positive("3/19/22");
    print_stuff(sam, sam_vacation, sam_history, sam_covid);
    sam_history.AddDonationEntry("3/19/22");
    sam_vacation.addVacationToAccount(sam, sam_history);
    print_stuff(sam, sam_vacation, sam_history, sam_covid);
    return 0;
}