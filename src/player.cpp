#include "player.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// constructors
Player::Player(){}
// player name only
Player::Player(string pN){
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


/* -------------------------------------------------------------------------- */
/*                                Portfolio                                   */
/* -------------------------------------------------------------------------- */


/* ---------------------------------Trade------------------------------------ */
// WORK IN PROGRESS
// checks duplicate and if found add it to the pos
// if not add to a new pos
// shares can not be zero or negative

// important coocept
/* each stock obj can have different info (shares + price)*/

// buy stocks
void Player::buyShares(string tradeSymbol, int tradeShares){
    // validator function
    // portfolio.push_back(make_pair(tradeSymbol, tradeShares));
    
}

// sell shares
void Player::sellShares(string tradeSymbol, int tradeShares){
    
}



// main function for trading stocks. Takes Stock pointer
void Player::tradeStocks(Stock& sS, int tC, int tS){
    
    // validation required ie tC cannot be negative
    int tradeChoice = tC;
    int tradeShares = tS;
    
    // portfolio has to take in string in order to check the duplicate?
    // can acutally compare by sS->GetSymbol() = for loop portfolio[i]
    // portfolio.first
    
    
    
    // declared for test purpose
    string tradeSymbol;

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

/* ---------------------------------Validate ------------------------------ */

bool Player::isNewStock(Stock& s){
    for(int i; i<portfolio.size(); i++)
         return (s.GetSymbol().compare(portfolio[i].first->GetSymbol()) ? true : false);
}

int Player::isPosInt(int n){

    while(true){
        if(n >= 1)
            return n;
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter again: "<<endl;
            cin>>n;
        }
    }
}

/* ---------------------------------Display-------------------------------- */

void Player::displayPortfolio(){
    for (const auto& p : portfolio)
      cout << p.first->GetSymbol() << " | " << p.second << endl;
}

void Player::displayPlayerInfo(){
    cout << "\nPlayer Name: " << this->playerName;
    cout << "\nPlayer Age: " << this->playerAge;
    cout << "\nBank Balance: $" << this->bankAccount->bal_account;
}
