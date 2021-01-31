#include "portfolio.hpp"
using namespace std;

// default constructor
Portfolio::Portfolio(){}

// destructor
Portfolio::~Portfolio(){}


// add shares to sharesList
void Portfolio::buyShares(Stock* stock, const int quantity){
    // index of the equivalent existing stock
    int index = indexFinder(stock);
    // existing stock
    if(index!=-1){
        // increment the position
        sharesList[index]->position += quantity;
        // average price is maintained by share.cpp
        sharesList[index]->totalSpent += stock->GetCurrentPrice()*quantity;
        // game time passes by 30 min
        //Date::AddGameTime();
    }
    // new stock
    else if(index==-1){
        //this->sharesList.push_back(stock->toShare());
    }
    // invalid input
    else
        cout << "\nTransaction error.";
}

void Portfolio::sellShares(Stock* stock, const int quantity){

    // index of the equivalent existing stock
    int index = indexFinder(stock);
    // existing stock
    if(index!=-1){
;

        if(sharesList[index]->position>quantity)
        // increment the position
        sharesList[index]->position -= quantity;
        // average price is maintained by share.cpp
        sharesList[index]->totalSpent -= (stock->GetCurrentPrice())*quantity;
        // game time passes by 30 min
        //Date::AddGameTime();
    }

    // new stock
    else if(index==-1)
        cout << "\nThe share does not exist.";

    // invalid input
    else
        cout << "\nTransaction error.";
}

// 
int indexFinder(Stock* stock){

    // // goes through the loop until the symbols match
    // for(int i=0;i<v.size(); i++){
    //     if(stock->GetSymbol()!=v[i]->GetSymbol())
    //         break;
    //     else
    //         return i;
    // }

    // not found
    return -1;
}




// int Portfolio::checkPosInt(const int n){

//     while(true){
//         if(n >= 1)
//             return n;
//         else
//         {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             cout<<"Enter again: "<<endl;
//             cin>>n;
//         }
//     }
// }

/* ---------------------------------Display-------------------------------- */

void Portfolio::displayPortfolio() const {
    
}

// void Portfolio::displayPlayerInfo() const {
//     cout << "\nPlayer Name: " << this->playerName;
//     cout << "\nPlayer Age: " << this->playerAge;
//     cout << "\nBank Balance: $" << this->bankAccount->bal_account;
// }


