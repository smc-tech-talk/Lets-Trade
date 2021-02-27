#pragma once
#include "player.hpp"
#include "banking.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;



/*
class Bank {
	string bankName;
	string bankBalance;

};
*/

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


class Bank_user {



};
