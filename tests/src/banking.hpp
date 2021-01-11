#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Account {

public:

	Account();

	Account(string uname, int index_bankarr);

	~Account();

	double bal_account;
	string username;
	string bank_name;
	vector <string> log;


	string time_stamp();

	void record_Account(string rec);
	void info_Account(Account a);
	void decreased_bal(double dprice);
	void increased_bal(double iprice);
	void transfer_Account(Account toAccount, double tmoney);
	

	
	
private:

	string account_number;


};


class Bank_user {
	


};