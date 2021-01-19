#include <vector>
#include <string>
using namespace std;

class Player{
    private:
        string playerName;
        double bankBalance;
        vector< pair <string, int> > portfolio;
        
        
    public:
        // default constructor
        Player();
        Player(string pN);
        ~Player();
        void setPlayerName(string pN);
        void setBankBalance(double bB);
        string getPlayerName();
        double getBankBalance();
 
};
