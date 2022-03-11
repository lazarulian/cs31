// A function that will return the largest and smallest value of an array


#include <iostream> 
#include <array>
#include <string>


using namespace std;

void locateMaximum( const int array[ ], int n, int &max, int &min);


int main() {
    int max;
    int doctor;
    int foo [5] = {16, 2, 77, 40, 12}; 

    for (int i = 0; i < 5; i++) {
        cout << foo[i] << endl;
    }

    locateMaximum(foo, 5, max, doctor);

    cout << "The maxmimum value is: " << max << endl;
    cout << "The minimum value is: " << doctor << endl;

    return 0;
}



void locateMaximum( const int array[ ], int n, int &max, int &min) {
    // Declaring Initial Variables
    max = array[0];
    min = array[0];
    for (int i = 0; i < n; i++) {
        if (max < array[i]) {
            max = array[i];
        }
        else {
            continue;
        }
    }

    for (int i = 0; i < n; i++) {
        if (min >= array[i]) {
            min = array[i];        }
        else {
            continue;
        }
    }
}