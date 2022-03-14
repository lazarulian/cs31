#include <iostream>
#include <string>

using namespace std;

class Plane_Class;

class Flight_Class
{
  private:
    int mcode;
    string mphrase;

  public:
    friend class Plane_Class;

    int msharecode;    

    Flight_Class (int icode, string iphrase, int isharecode);        
    float cntrl(Plane_Class &pln);
        
};


class Plane_Class 
{
  private:
    float mscore;

  public:

    friend float Flight_Class::cntrl(Plane_Class &pln);  

    int myear;   

    Plane_Class(float score, int theyear); 
        
    float getmscore();  
    void setmscore(float rscore); 
};
   


int main() 
{
    cout << "cool!" << endl;

    return 0;
}


Plane_Class::Plane_Class(float score, int theyear)
{
    mscore = score;
    myear = theyear;
}

Flight_Class::Flight_Class (int icode, string iphrase, int isharecode)
{
  mcode = icode;
  mphrase = iphrase;
  msharecode = isharecode;
}

float Plane_Class::getmscore() 
{
  return mscore;
}

void Plane_Class::setmscore ( float rscore )
{
  mscore = mscore + rscore;
}


float Flight_Class::cntrl(Plane_Class &pln)
{
  pln.mscore = pln.mscore + 1000;
  return pln.mscore;
}