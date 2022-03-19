//CovidHistory.cpp

#include "CovidHistory.h"

// Accessor
void CovidHistory::getCovidHistory() {
    cout << "This employee has tested positive for covid-19 on the following dates: ";
    for (int i = 0; i < covid_history.size(); i++) {
        string temp = to_string(covid_history[i]);
        cout << temp[0] << temp[1] << "/" << temp[2] << temp[3] << "/" << temp[4] << temp[5] << ", ";
    }
}

// Mutator

void CovidHistory::report_positive(string date) {
    if (verify_date(date) == true) {
        covid_history.push_back(string_to_date(date));
    }
}