// CS31 Temperature Average


#include <iostream>

using namespace std;


double average(int data[], int size) {
    if (size <= 0) {
        return 0.00;
    }

    int sum = 0;
    int *current = data; // Value of position 0 in the array
    for (int pos = 0; pos < size; pos++) {
        sum = sum + *current; // 
        current++;
    }
    return(double(sum)/size);
}

// By Value

void sum(int i, int j) {
    // Changes The Value of i to i+j
    i = i+j;
    cout << "The changed value of i is: " << i << endl;
}

// By Reference
void ref_sum(int &i, int j) {
    // Changes The Value of i to i+j
    i = i+j;
    j = i+j;
}

int main() {

    int i = 5;
    int j = 1;

    cout << "The value of i is: " << i << endl; // 5
    
    sum(i, j);

    cout << "The value of i is still: " << i << endl; // 5

    ref_sum(i, j);

    cout << "The value of i is now: " << i << endl; // 6
    cout << "The value of j is now: " << j << endl; // 1




    return 0;
}