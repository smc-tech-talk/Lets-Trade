#pragma once
#include "human.hpp"
#include "portfolio.hpp"
#include "banking.hpp"
#include "portfolio.hpp"
#include "share.hpp"
#include <vector>
#include <string>

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
};
