#pragma once
#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;



/*
class Bank {
	string bankName;
	string bankBalance;

};
*/
string list_bank[9]{
	"CIT Bank", "Bank of The West", "WELLS FARGO",
	"Washington Federal Savings and Loan", "Umpqua Bank",
	"Golden1 Credit Union", "EASTWEST BANK", "Charles Schwab", "CHASE"
};

char codebook[] = { 'a','A','b','B','c','C','d','D','e',
					'E','f','F','g','G','h','H','i','I','j','J','k','K',
					'l','L','m','M','n','N','o','O','p','P','q','Q','r',
					'R','s','S','t','T','u','U','v','V','w','W','x','X',
					'y','Y','z','Z','0','1','2','3','4','5','6','7','8','9',
					'!','@','#','$','%','&','*' };


class Account {

public:

	Account();

	Account(Player* a_player);

	Account(Player* player, string account_number, double balance);

	// Account(Player* p, string accountName, Bank* b); => A constructor using 'Bank' class
	//~Account();

	
	vector <string> log;


	void initialize_balance();
	double get_balance();
	void create_account_number();
	void print_record();
	void input_record(Transaction t, Date* d);
	void info_Account();
	

private:
	Player* player;
	string account_number;
	double balance;
	string bank_name;
};
