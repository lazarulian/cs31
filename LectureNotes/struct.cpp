#include <iostream>
#include <string>

using namespace std;

struct citizen {


    string LastName;
    int age;
};

void getData(citizen& TheAccount) {
    cout << "What is your last name: " << endl;
    cin >> TheAccount.LastName;
    cout << TheAccount.LastName << endl;
}

int main() {

    citizen FatCrap;
    getData(FatCrap);


    return 0;
}