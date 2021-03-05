#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "player.hpp"

Player::Player(){
    this->playerName = getFirstName();
    this->playerAge = getAge();
    unique_ptr<Account> bankAccount(new Account());
    unique_ptr<Portfolio> playerPortfolio(new Portfolio());
}
Player::Player(string pN, int pA, Portfolio* p){
    setFirstName(pN);
    setAge(pA);
    setPortfolio(p);
    // keep-> unique_ptr<Account> bankAccount(new Account());
    // keep-> unique_ptr<Portfolio> playerPortfolio(new Portfolio());
}

Player::~Player(){}


// setters
void Player::setPlayerName(string pN){ this->playerName = pN; };
void Player::setPlayerAge(int pA){ this->playerAge = pA; };

// getters
string Player::getPlayerName(){ return this->playerName; };
int Player::getPlayerAge(){ return this->playerAge; };
