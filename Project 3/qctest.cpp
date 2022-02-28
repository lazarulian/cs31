// Apurva Shah: CS 31 Project 3
// Very limited functionality for this one.

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

bool isValidQC(string results);
// This function returns true if its parameter is a well-formed test result string described above or false otherwise.

bool isValidQC1(string results);

int passQC(string results);
// If the parameter is a well-formed test result string, this function should return the total number of pass test results from all the batches reported in the string. If the parameter is not valid, return -1 .

int defectQC(string results);
// If the parameter is a well-formed test result string, this function should return the total number of defect test results from all the batches reported in the string. If the parameter is not valid, return -1.

int totalQC(string results);
// If the parameter is a well-formed test result string, this function should return the total number of tests being reported from all the batches in the string. If the parameter is not a valid, return -1.

int batches(string results);
// If the parameter is a well-formed QC test result string, this function should return the total number of batches reported in the string. If the parameter is not a valid, return -1.



int main() {
    string input = "Q5d2p3Q5d2p3Q5d2p3Q5d2p3Q5d2p3";
    if (isValidQC(input) == false) {
        cout << "Your string is invalid." << endl;

    }
    else {
        cout << "Your string is valid" << endl;
        cout << "You passed " << passQC(input) << " QC checks." << endl;
        cout << "You failed " << defectQC(input) << " QC checks." << endl;
        cout << "You conducted  " << totalQC(input) << " QC checks in total." << endl;
        cout << "We processed  " << batches(input) << " batches in this round." << endl;

    }
    
    return 0;
}


bool isValidQC(string results) {
    
    // The purpose of this function is to return whether the code for QC is a valid entry or not. We do this by going through
    // test cases and seeing if we catch any errors.
    
    //Test Case: Variable Declaration for Function
    bool valid_return = false;
    long string_size = results.size();
    int test_cases_passed = 0;
    int test_cases_failed = 0;
    
    // Test Cases
    
    // Checing to see if the input is an empty string
    if (string_size > 0) {
        test_cases_passed++;
    }
    else {
        test_cases_failed++;
    }
    
    //Test Case: Invalid Length of String
    
    if (string_size % 6 == 0) {
        test_cases_passed++;
    }
    
    else {
        test_cases_failed++;
    }
    
    // Test Case: Q not in the right location
    // Q is located in intervals of 6 index locations: [0] [6] [12]
    
    for (size_t pos = 0; pos < string_size; pos = pos+6) {
        // Modified for Loop to Parse & Jump by 6 values
        if (results[pos] != 'Q') {
            test_cases_failed++;
        }
        else {
            test_cases_passed++;
        }
    }
    
    // Test Case: Checking if a number follows Q (always in positions [1] [7] [13])
    
    for (size_t pos = 1; pos < string_size; pos = pos+6) {
        // Modified for Loop to Parse & Jump by 6 values
        if (isdigit(results[pos]) == 0) {
            test_cases_failed++;
        }
        else {
            test_cases_passed++;
        }
        
        if (results[pos] == '0') {
            test_cases_failed++;
        }
        
        else {
            test_cases_passed++;
        }
    }
    
    // Test Case: Checking if d or p is present in the right positions [3]-[5] [9]-[10]
    for (size_t pos = 2; pos < string_size; pos = pos+6) {
        // Modified for Loop to Parse & Jump by 6 values
        if (results[pos] == 'p' || results[pos] == 'd') {
            if (results[pos] == results[pos+2]) {
                test_cases_failed++;
            }
            else {
                test_cases_passed++;
            }
        }
        else {
            test_cases_failed++;
        }
    }
    
    // Test Case: Checking if the numbers of p and d add up to the number of items QC checked
    
    for (size_t pos = 1; pos < string_size; pos = pos+6) {
        // Modified for Loop to Parse & Jump by 6 values
        if ((int)results[pos]-48 != (((int)results[pos+2]-48) + ((int)results[pos+4]-48))) {
            test_cases_failed++;
        }
        else {
            test_cases_passed++;
        }
    }
    
    // Returning the Boolean Value Based off of the Test Cases:
    if (test_cases_failed == 0) {
        valid_return = true;
    }
    else {
        valid_return = false;
    }
    
    return valid_return;
} // End Function Declaration


int passQC(string results) {
    
    // Variable Declaration
    int number_passed_test = 0;
    
    if (isValidQC(results) == false) {
        return -1;
    }
    
    else {
        for (size_t pos = 0; pos < results.size(); pos++) {
            // Modified for Loop to Parse & Jump by 6 values
            if (results[pos] == 'p') {
                number_passed_test = number_passed_test + (int)results[pos+1]-48;
            }
            else {
                continue;
            }
        } // end for loop
        
        return number_passed_test;
    }

} // end function declaration

int defectQC(string results) {
    // Variable Declaration
    int number_failed_test = 0;
    
    if (isValidQC(results) == false) {
        return -1;
    }
    
    else {
        for (size_t pos = 0; pos < results.size(); pos++) {
            // Modified for Loop to Parse & Jump by 6 values
            if (results[pos] == 'd') {
                number_failed_test = number_failed_test + (int)results[pos+1]-48;
            }
            else {
                continue;
            }
        } // end for loop
        
        return number_failed_test;
    }
} // End Function Declaration

int totalQC(string results) {
    // Variable Declaration
    int total_tests = 0;
    
    if (isValidQC(results) == false) {
        return -1;
    }
    
    else {
        for (size_t pos = 0; pos < results.size(); pos++) {
            // Modified for Loop to Parse & Jump by 6 values
            if (results[pos] == 'Q') {
                total_tests = total_tests + (int)results[pos+1]-48;
            }
            else {
                continue;
            }
        } // end for loop
        
        return total_tests;
    }
} // End Function Declaration


int batches(string results) {
    if (isValidQC(results) == false) {
        return -1;
    }

    else {
        int counted = 0;
        for (size_t pos = 0; pos < results.size(); pos++) {
            if (results[pos] == 'Q') {
                counted++;
            }
        }
        return counted;
    }
}
