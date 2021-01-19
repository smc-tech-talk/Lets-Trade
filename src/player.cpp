#include "player.hpp"
#include "stock.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// constructors
Player::Player(){}
// player name only
Player::Player(string pN){
	cout << "constructor has been called\n";
    this->playerName = pN;
    this->bankAccount = new Account();
    this->portfolio;
}


Player::~Player(){ }


// setters
void Player::setPlayerName(string pN){ this->playerName = pN; };
void Player::setPlayerAge(int pA){ this->playerAge = pA; };


// getters
string Player::getPlayerName(){ return this->playerName; };
int Player::getPlayerAge(){ return this->playerAge; };


// portfolio //

// buy shares
// checks duplicate and if found add it to the pos
// if not add to a new pos
// shares can not be zero or negative

void Player::buyShares(string tSymbol, int tShares){
    
}

// sell shares
void Player::sellShares(Stock* tS, int shares){

}



void Player::tradeStocks(Stocks* sS, int tC, int tS){
    // tC = trade choice(buy = 0, sell = 1)
    // tS = trade shares
    
    // after validating for tC and tS
    int tradeChoice = tC;
    int tradeShares = tS;
    
    // avoid possible redundant code for buyStocks and sellStocks
    string tradeSymbol = sS->GetSymbok();
    
    
    switch(tC){
        case 0:
            buyShares(tradeSymbol, tradeShares);
            break;
        case 1:
            buyShares(tradeSymbol, tradeShares);
            break;
        default:
            cout << "Error, invalid input";
            break;
    }
}



