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


// add shares to userShares
void Player::buyShares(Share* share, int quantity){
    // validate quanitity input
    checkPosInt(quantity);
    // if user already have the stock in userShares
    if(isDuplicate){
        // increment the position
        s->positions -= quantity;
        // game time passes by 30 min
        timePasses(30);
    }
    // if user purchases a new stock
    else
        userShares.push_back(share);
}


// remove shares from userShares
void Player::sellShares(Share* s, int quantity){
    checkPosInt(quantity);
    if(isDuplicate){
        if(s->positions >= quantity){
            s->positions -= quantity;
            timePasses(30);
            // if user sells all the shares
            if(s->positions = 0)
                // remove Shares* from userShares
                userShares[findShareIndex].erase;
                // scoot userShares
                userShares.shrink_to_fit;
        }
        // if user tries to sell more than they have
        else
            cout << "The input quantity exceeds your positions."
    }
    // if user does not own the share
    else
        cout << "The inpput shares not found in your portfolio";
    
}


bool Player::isDuplicate(Share* s){
    int i = 0;
        while(positios.sizeof()) >= i)
            s->GetSymbol!=positions[i])?i++:return true
        // once serch it up all the positions and still no found
        return false;
}


// returns index of the share or 0 if not found
int Player::findShareIndex(Share* s, Stock* st){
    int i = 0;
        while(positios.sizeof()) >= i)
            s->GetSymbol!=positions[i])?i++:return i
        // once serch it up all the positions and still no found
        return 0;
}


int Player::showPortfolioSize(){
    return userShares.size();
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


int Player::checkPosInt(int n){

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
 
 
 
 */
