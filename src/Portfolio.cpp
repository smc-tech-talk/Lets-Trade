#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "player.hpp"
using namespace std;

// takes user's first name sets up bank account and userPortfolio
Player::Portfolio(){
    unique_ptr<Account> bankAccount(new Account());
    vector<Shares* s>;
}

Player::~Portfolio(){ }

/* ---------------------------------Trade------------------------------------ */
// WORK IN PROGRESS
// checks duplicate and if found add it to the pos
// if not add to a new pos
// shares can not be zero or negative

// buy stocks
void Player::buyShares(string tradeSymbol, int tradeShares){
    // validator function
    if(isPosInt(tradeShares)){
        portfolio.push_back(make_pair(tradeSymbol, tradeShares));
    }
    else{
        cout << "/nTransaction incomplete";
    }
}

// sell shares
void Player::sellShares(string tradeSymbol, int tradeShares){
    for(int i; i<portfolio.size(); i++)

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
