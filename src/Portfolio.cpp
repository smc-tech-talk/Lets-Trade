#include "portfolio.hpp"
using namespace std;

// takes user's first name sets up bank account and userShares
Portfolio::Portfolio(){
  unique_ptr<Account> bankAccount(new Account());
  vector<Share*> userShares;
}

// destructor
Portfolio::~Portfolio(){}


// add shares to userShares
// next link with transaction history
void Portfolio::buyShares(Share* share, int quantity, Date* gameDate){
  // validate quanitity input
  checkPosInt(quantity);
  // if user already have the stock in userShares
  if(isDuplicate(share)){
      // increment the position
      share->GetPositions() -= quantity;
      // game time passes by 30 min
      Date::AddGameTime(gameDate);
  }
  // if user purchases a new stock
  else
      this->userShares.push_back(share);
}

void Portfolio::sellShares(Stock* stock, const int quantity){

// remove shares from userShares
void Portfolio::sellShares(Share* share, int quantity, Stock* stock, Date* gameDate){
  checkPosInt(quantity);
  if(isDuplicate(share)){
      if(share->GetPositions() >= quantity){
          share->GetPositions() -= quantity;
          Date::AddGameTime(gameDate);
          // if user sells all the shares
          if(share->SetPositions(0))
              // remove Shares* from userShares
//                this->userShares[findShareIndex(share, stock)].erase;
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

    // new stock
    else if(index==-1)
        cout << "\nThe share does not exist.";

bool Portfolio::isDuplicate(Share* share){
  int i = 0;
      while(sizeof(this->userShares) >= i)
          share->GetSymbol!=userShares[i])?i++:return true
      // once serch it up all the positions and still no found
      return false;
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

// returns index of the share or 0 if not found
int Portfolio::findShareIndex(Share* share, Stock* stock){
  int i = 0;
      while(sizeof(this->userShares) >= i)
          share->GetSymbol!=userShares[i])?i++:return i
      // once serch it up all the positions and still no found
      return 0;
}




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
