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
    string playerName = pN;
    double bankBalance = 5000;
    vector<Stock> portfolio;
}
// player name + set bank balance
Player::Player(string pN){
	cout << "constructor has been called\n";
    string playerName = pN;
    double bankBalance = 5000;
    vector<Stock> portfolio;
}


Player::~Player(){ }


// setters
void Player::setPlayerName(string pN){ playerName = pN; };
void Player::setBankBalance(double bB){ bankBalance = bB; };

// getters
string Player::getPlayerName(){ return playerName; };
double Player::getBankBalance(){ return bankBalance; };


// portfolio //


