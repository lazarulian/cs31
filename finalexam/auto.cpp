// Auto.cpp



#include <iostream>
using namespace std;

// Forward Declaration
class Engine;
class Auto;

// Engine Class
class Engine
{
public:
    Engine();

    void rev( ); 
    void intoGear( int gear);
    int getGear() const;
private:
     int myGear;
};


// Implementations

Engine::Engine( ) {
    myGear = 0;
}

void Engine::rev(){ 
    cout << "rev...." << endl;   
}
// Acessor

int Engine::getGear() const {
    return myGear;
}
void Engine::intoGear( int gear ) {  
    myGear = gear;  cout << "into gear " << myGear << endl;
}

// Auto Class

class Auto {

public:
void drive(Engine engine);
// puts it into first then second gear

};

void Auto::drive(Engine engine) {
    engine.intoGear(1);
    engine.rev();
    engine.intoGear(2);
    engine.rev();
}


int main() {

    Engine Battery;

    Auto Tesla;

    Battery.rev(); // 0 

    Tesla.drive(Battery);

    cout << Battery.getGear() << endl;


    return 0;
}