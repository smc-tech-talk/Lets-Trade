#include <string>
#include "human.hpp"
using namespace std;


Human();
Human(string fN, int a){
private:
    this->firstName = fN;
    this->age = a;
//    this->uniqueID = genRandom();
}
// setters and getters
void Human::setAge(int a){ this->age = a; };
int  Human::getAge(){ return this->age; };
void Human::setFirstName(string fN){ this->firstName = fN; };
int  Human::getFirstName(){ return this->age; };
template <typename T>
void Human::setUniqueID(T u){ this->uniqueID = u };
template <typename T>
T Human::getUniqueID(){ this->uniqueID; }
