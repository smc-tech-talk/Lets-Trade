#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "player.hpp"
using namespace std;


Player::Player(){}
Player::Player(){
    this->playerName = getFirstName();
    this->playerAge = getAge();
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
