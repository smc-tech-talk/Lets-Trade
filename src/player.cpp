#include "player.hpp"
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

// returns true if a new stock is passed
bool Player::isNewStock(Stock& s){
    for(int i; i<portfolio.size(); i++){
        // string comparison between the new stock s and s
        if(s.GetSymbol().compare(portfolio[i].first->GetSymbol())){
            return true;
        }
        else
            return false;
        
        // can be written as the following
        // retrun (s.GetSymbol().compare(portfolio[i].first->GetSymbol()) ? true : false);
    }
}

// buy shares
// checks duplicate and if found add it to the pos
// if not add to a new pos
// shares can not be zero or negative

void Player::buyShares(string tradeSymbol, int tradeShares){
//    portfolio.push_back(make_pair(tradeSymbol, tradeShares));
}

// sell shares
void Player::sellShares(string tradeSymbol, int tradeShares){
    
}

// print function
void Player::displayPortfolio(){
    for (const auto& p : portfolio)
    {
      cout << p.first->GetSymbol() << "\t | " << p.second << endl;
    }
}

int Player::isPosInt(int n){
    cin >> input;
    while(1){
        if(cin.fails()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n\);
            cout << "\nError, try again: ";
            cin >> input;
        }
        else{
            cout << "\nSuccessful input";
            return n;
        }
    }
}

// main function for trading stocks. Takes Stock pointer, Trade choice(tC) and Trade shares(tS)
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



