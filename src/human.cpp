#include <string>
#include "human.hpp"
using namespace std;


Human();
Human(string fN, int a){
private:
    this->firstName = fN;
    this->age = a;
    
}
void Human::setAge(int a){ this->age = a; };
int  Human::getAge(){ return this->age; };
void Human::setFirstName(string fN){ this->firstName = fN; };
int  Human::getFirstName(){ return this->age; };
void Human::setUniqueID(auto u){ this->uniqueID = u };
string Human::getUniqueID(){ this->uniqueID; }
