#include <vector>
#include <string>
using namespace std;

class Human{
    
protected:
    string firstName;
    string lastName;
    double height;
    double weight;
    string gender;
    string nationality;
    int age;
    int birthYear;
    int birthMonth;
    int birthDate;
    int SSN;
    int uniqueID;
    
public:
    void setAge(int a);
    int getAge();
    void setFirstName(string fN);
    string getFirstName();
    
    template <typename T>
    void setUniqueID(T u);
    template <typename T>
    T getUniqueID(){};
};
