#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "portfolio.hpp"
using namespace std;

// takes user's first name sets up bank account and userShares
Portfolio::Portfolio(){
    unique_ptr<Account> bankAccount(new Account());
    vector<Share*> userShares;
}

Portfolio::~Portfolio(){ }


// add shares to userShares
// next >> link with transaction history
void Portfolio::buyShares(Share* share, int quantity, Date* gameDate){
    // validate quanitity input
    checkPosInt(quantity);
    // if user already have the stock in userShares
    if(isDuplicate(share)){
        // increment the position
        share->positions -= quantity;
        // game time passes by 30 min
        Date::AddGameTime(gameDate);
    }
    // if user purchases a new stock
    else
        this->userShares.push_back(share);
}


// remove shares from userShares
void Portfolio::sellShares(Share* share, int quantity, Stock* stock, Date* gameDate)
{
    checkPosInt(quantity);
    if(isDuplicate(share)){
        if(share->positions >= quantity){
            share->positions -= quantity;
            Date::AddGameTime(gameDate);
            // if user sells all the shares
            if(share->positions = 0)
                // remove Shares* from userShares
//                this->userShares[findShareIndex(share, stock)].erase;
                this->userShares[findShareIndex(share, stock)];
            // scoot userShares
            this->userShares.shrink_to_fit();
        }
        // if user tries to sell more than they have
        else
            cout << "The input quantity exceeds your positions.";
    }
    // if user does not own the share
    else
        cout << "The inpput shares not found in your portfolio";
    
}

// O()
bool Portfolio::isDuplicate(const Share* share) const
{
    int i = 0;
        while(sizeof(this->userShares) >= i)
            share->GetSymbol!=userShares[i])?i++:return true
        // once serch it up all the positions and still no found
        return false;
}


// returns index of the share or 0 if not found
// O(n)
int Portfolio::findShareIndex(const Share* share, const Stock* stock) const
{
    int i = 0;
        while(sizeof(this->userShares) >= i)
            share->GetSymbol!=userShares[i])?i++:return i
        // once serch it up all the positions and still no found
        return 0;
}



int Portfolio::checkPosInt(const int n){

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

void Portfolio::displayPortfolio(){
    
}

void Portfolio::displayPlayerInfo(){
    cout << "\nPlayer Name: " << this->playerName;
    cout << "\nPlayer Age: " << this->playerAge;
    cout << "\nBank Balance: $" << this->bankAccount->bal_account;
}


