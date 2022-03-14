#include <iostream>
#include <string>
#include <cassert>
#include <typeinfo>

using namespace std;


int main() {
    bool b = (true || false) && (false && true);
    cout << true << endl;
    cout << b << endl;
    return 0;
}