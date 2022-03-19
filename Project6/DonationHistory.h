// DonationHistory.h

#ifndef DonationHistory_h
#define DonationHistory_h

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


class DonationHistory {
    private:
    int employee_id;
    int times_donated;
    vector<int> dates_donated;

    public:
    // constructor
    DonationHistory(int actualID); // should be called every donation or employee ID creation
    
    // accessors
    vector<int> return_hist();
    void getDonationHistory();

    // mutators
    void AddDonationEntry(string donation_date);

};

int string_to_date(string date_input);
bool verify_date(string date_input);
bool verify_history(vector<int> dates_donated);
int convert_month_int (string input, int type);