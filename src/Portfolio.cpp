#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "portfolio.hpp"
using namespace std;

// takes user's first name sets up bank account and userPortfolio
Player::Portfolio(){
    unique_ptr<>;
    unique_ptr<Account> bankAccount(new Account());
    vector<Share*> userShares;
}

Player::~Portfolio(){ }

/* ---------------------------------Trade------------------------------------ */
// WORK IN PROGRESS
// checks duplicate and if found add it to the pos
// if not add to a new pos
// shares can not be zero or negative

// add shares to userShares
void Player::buyShares(Share* share, int quantity){
    // validate quanitity input
    isPosInt(quantity);
    // if user already have the stock in userShare
    if(isDuplicate){
        // increment the position
        s->positions -= quantity;
        // game time passes
        timePasses(30);
    }
    // if user purchases a new stock
    else
        userShares.push_back(share);
}

// remove shares from userShares
void Player::sellShares(Share* s, int quantity){
    if(isDuplicate){
        if(s->positions >= quantity)
            s->positions -= quantity;
            timePasses(30);
            if(s->positions = 0)
                userShares[findShareIndex].erase;
                userShares.shrink_to_fit;
        else
            cout << "The input quantity exceeds your positions."
    }
    else
        cout << "The inpput shares not found in your portfolio";
    
}


bool Player::isDuplicate(Share& buyingShare){
    int i;
        while(i<=sizeof(positios))){
            while(buyingShare.GetSymbol != positions[i]){
                i++;
            }
            else
        }
        // can go beyond
        
    }
}

int Player::findShareIndex(Share* sh, const Stock* st){
    int* first = &(s1->begin);
    int* last = &(s1->end);
    {
      while (*first!=*last) {
        if (*first==*val) return *first;
        ++*first;
      }
      return *last;
    }
}

int Player::showPortfolioSize(Portfolio* p1){
    return p1.size();
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



// no need as all stocks will be handled by the stock address
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
