#include "human.hpp"
#include <string>
#include <vector>

// default constructor
Human::Human(){}
Human::Human(std::string fN, int a){
  this->firstName = fN;
  this->age = a;
//  this->uniqueID = genRandom();
}
// setters and getters
void Human::setAge(int a){ this->age = a; };
int  Human::getAge(){ return this->age; };
void Human::setFirstName(std::string fN){ this->firstName = fN; };
std::string  Human::getFirstName(){ return this->firstName; };
template <typename T>
void Human::setUniqueID(T u){ this->uniqueID = u; };
template <typename T>
T Human::getUniqueID(){ this->uniqueID; }
