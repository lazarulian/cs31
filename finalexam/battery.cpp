#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Battery {
    private:
    double myVolts;
    public:
    int Year;
    
    // Constructors - Initially Populates the Data 
    Battery();
    Battery(double volts);
    Battery(double volts, int year);
    // Accessors - how to get the data from public and private types
    double getVolts() const; //accessor
    double getYear() const;
    // Mutators - altering data in the public and private types
    void setVolts(double volts);
};

// Constructor Implementation
    // Default Case
    Battery::Battery() {
        myVolts = 1.5;
    }

    // Overloaded Input
    Battery::Battery(double volts) {
        myVolts = volts;
    }

    Battery::Battery(double volts, int year) {
        myVolts = volts;
        Year = year;
    }

// Accessor Implementation
    double Battery::getVolts() const {
        return myVolts;
    }
    double Battery::getYear() const {
        return Year;
    }

// Mutator/Setters Implementation
    void Battery::setVolts(double volts) {
        myVolts = volts;
    }

int main(){

    Battery nineVolts( 9.0, 2000 );
    cout << nineVolts.getVolts( ) << " volts" << endl; // 9
    nineVolts.setVolts(13);
    cout << nineVolts.getVolts( ) << " volts" << endl; // 13


    return 0;
}