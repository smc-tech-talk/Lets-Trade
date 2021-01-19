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


void Player::tradeStocks(Stocks* sS, int buyOrSell){
    // buy = 0, sell = 1
    int tradeShares;
    string tradeSymbol = sS->GetSymbok();
    switch(buyOrSell){
        case 0:
            cout << "Enter the number of shares to buy: ";
            cin >> tradeShares;
            buyShares(tradeSymbol, tradeShares);
            break;
        case 1:
            cout << "Enter the number of shares to sell: ";
            cin >> tradeShares;
            buyShares(tradeSymbol, tradeShares);
            break;
            
        default:
            cout << "Error, invalid input";
            break;
    }
}
//void Player::buyShares(Stock* tS, int shares){
//
//}
//
//// sell shares
//void Player::sellShares(Stock* tS, int shares){
//
//}




