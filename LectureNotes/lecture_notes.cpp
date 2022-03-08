// Lecture Notes

#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){

    vector<int> Score; // specifiying the datatype and the name
     // defining an integer vector named score

   //  Score[0] = 1; // this doesnt necessarily work,
    // you have to use the pushback feature to initially 
    // initialize it

    for (int i = 0; i<=9; i++) {
        Score.push_back(i);
    }

    // Sice we initialized 9 elements, 16 elements are allocated

    for (int i = 0; i<=9; i++) {
        cout << Score[i] << endl;
    }

    // returns how many elements allocated
    cout << Score.capacity() << endl;
    // returns initalized elements
    cout << Score.size() << endl;

    return 0;
}