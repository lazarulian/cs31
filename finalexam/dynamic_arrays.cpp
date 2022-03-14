#include<iostream>
using namespace std;

int main()
{
    int *entry;
    entry = new int[10];
    
    
    for (int i = 0; i < 10; i++) {
        int input;
        cout << "Enter number: ";
        cin >> input;
        entry[i] = input;
    }

    for (int i = 0; i < 10; i++) {
        cout << entry[i] << endl;
    }
       return 0;

}