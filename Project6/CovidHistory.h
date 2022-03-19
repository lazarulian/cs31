// CovidHistory.h

#ifndef CovidHistory_h
#define CovidHistory_h


#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <vector>

#include "DonationHistory.h"

using namespace std;

class CovidHistory {
    private: 
    int employee_id;
    vector<int> covid_history;

    public:

    // Constructor
    CovidHistory() {}
    CovidHistory(int actualID) {
        employee_id = verifyId(actualID);
    } // Constructor Overloading

    CovidHistory(string positive_date) : CovidHistory() {
            covid_history.push_back(string_to_date(positive_date));
    } // Constructor Delegation

    // Accessor

    void getCovidHistory(); 

    // Mutator

    void report_positive(string date);
    
};