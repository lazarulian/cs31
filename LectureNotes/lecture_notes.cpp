// Lecture Notes

#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){

   char blocks[ 3 ] = {'A','B','C'};
   char *ptr = &blocks[0]; 
   cout << ptr << endl;
   char temp;
    temp = blocks[ 0 ];
    cout << temp << endl;
    temp = *ptr;
cout << temp << endl;




    return 0;
}