#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Battery {
    private:
    double myVolts;

    public:
    int Year;
    
    // Constructors
    Battery();
    Battery(double volts);

    // Accessors
    double getVolts() const; //accessor

    // Mutators
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
// Accessor Implementation
    double Battery::getVolts() const {
        return myVolts;
    }

// Mutator Implementation
    void Battery::setVolts(double volts) {
        myVolts = volts;
    }

int main(){

    Battery doubleA;
    cout << doubleA.getVolts( ) << " volts" << endl;
    Battery nineVolts( 9.0 );
    cout << nineVolts.getVolts( ) << " volts" << endl;

    return 0;
}