#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "player.hpp"
using namespace std;


Player::Player(){}
Player::Player(string pN, int pN, Account* aC, Portfolio* pO){
    this->playerName = get;
    this->playerAge = pA;
//  unique_ptr<Account> bankAccount = make_unique<Account>();
    unique_ptr<Account> bankAccount(new Account());
    unique_ptr<Portfolio> userPortfolio(new Portfolio());
}

Player::~Player(){ }


// setters
void Player::setPlayerName(string pN){ this->playerName = pN; };
void Player::setPlayerAge(int pA){ this->playerAge = pA; };

// getters
string Player::getPlayerName(){ return this->playerName; };
int Player::getPlayerAge(){ return this->playerAge; };




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

// not in use
// not recommended as it goes thru every single stock every time
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


/* ---------------------------------Ideas-------------------------------- */

/*
 
// 1d vector
// if 2d, it has to go thru the vector everytime to look for the corresponding symbol
// which is memory consuming
 
vector<Stock*> = portolio;
 
 <Stock*>

void Player::buyStocks(Stock* s, int n){
    s->AddShares(n);
}
 

void Player::sellStocks(Stock* s, int n){
    s->RemoveShares(n)
}

void Player::displayPortfolio(const vector<Stock*> s)
{
    copy(s.begin(), s.end(), ostream_iterator<Stock*>(cout, " "));
}
 
Purchase price * shares
in Plyaer.cpp
 
 pair <Stock*, shares>
 <MSFT*, 5>
 10
 
 
 
 
 
 */


