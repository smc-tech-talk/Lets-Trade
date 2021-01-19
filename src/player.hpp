#include <vector>
#include <string>
#include "banking.hpp"
using namespace std;

class Player{
    private:
        string playerName;
        double playerAge;
        Account* bankAccount;
        vector< pair <string, int> > portfolio;
        
        
    public:
        // default constructor
        Player();
        Player(string pN);
        ~Player();
        void setPlayerName(string pN);
        void setPlayerAge(int pA);
        string getPlayerName();
        int getPlayerAge();
 
};
