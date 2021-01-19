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

// sell stocks



