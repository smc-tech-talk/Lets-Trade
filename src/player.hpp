#ifdef PLAYER_H
#def PLAYER_H

#include <vector>
#include <string>
#include "human.hpp"
#include "portfolio.hpp"
#include "banking.hpp"
#include "stock.hpp"
using namespace std;

class Player: public Human{
    protected:
        string playerName;
        int playerAge;
        
    public:
        // default constructor
        Player();
        ~Player();
        // setter
        void setPlayerName(string pN);
        void setPlayerAge(int pA);
        // getter
        string getPlayerName();
        int getPlayerAge();
        void displayPortfolio();
        void displayPlayerInfo();
};
#endif
