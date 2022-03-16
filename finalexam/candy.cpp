#include <iostream>
#include <string>


using namespace std;


// Define a structure Candy with the data fields kind (a string such as "M & M's"), 
// maker (a string such as "Mar's") and cost (a double such as 0.99).  Create a variable c of type Candy that 
// represents a snicker's bar made by Mar's that costs $1.25.  Print to cout each of the fields of the variable c.  
// Create a pointer variable and give it the address of c.  Print to cout each of the fields of this pointer variable.  
// Will this pointer variable need to be delete'd when you are finished working with it


struct Candy {
    string candy_name;
    string maker;
    double cost;
    Candy(string name, string maker, double cost);
};


int main(){

    Candy c("Snickers", "Mar's", 1.25);
    struct Candy *name;
    name = &c;

    cout << name->candy_name << endl;

    delete name;



    return 0;
}