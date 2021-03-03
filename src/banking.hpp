#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
//#include "player.hpp"
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

	Account(string uname, int index_bankarr);

	Account(Player* player, string account_number, double balance);

	// Account(Player* p, string accountName, Bank* b); => A constructor using 'Bank' class
	//~Account();

	double bal_account;
	string username; // => Should be Player now.
	string bank_name;
	vector <string> log;

	string time_stamp();

	void record_Account(string rec);
	void info_Account(Account a);
	void decreased_bal(double dprice);
	void increased_bal(double iprice);
	void transfer_Account(Account toAccount, double tmoney);

private:
	Player* player;
	string account_number;
	double balance;
};


class Bank_user {



};
