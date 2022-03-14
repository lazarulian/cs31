#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct University {
    string mName;
    string mAddress;
    int mCapacity;

    University(string name, string address, int capacity) {
    mName = name;
    mAddress = address;
    mCapacity = capacity;
    }
};

int main() {


    University UCLA("UCLA", "405 Hilgard Avenue", 44947);

    cout << UCLA.mName << endl;
    cout << UCLA.mAddress << endl;
    cout << UCLA.mCapacity << endl;


    return 0;
}