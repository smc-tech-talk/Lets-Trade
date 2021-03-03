#pragma once
#include <memory>
#include <vector>
#include <string>
#include "human.hpp"
#include "portfolio.hpp"

using namespace std;

class Player: public Human{
    protected:
        string playerName;
        int playerAge;
        Portfolio* portfolio;
    public:
        // default constructor
        Player();
        ~Player();
        // setter
        void setPlayerName(string pN);
        void setPlayerAge(int pA);
        void setPortfolio(Portfolio* portfolio);
        // getter
        string getPlayerName();
        int getPlayerAge();
};
