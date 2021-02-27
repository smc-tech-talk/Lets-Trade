#include "banking.hpp"


Account::Account(Player* a_player) {

	player = a_player;
	bank_name = list_bank[rand()%9];
	create_account_number();
	initialize_balance();

}

Account::Account(Player* player, string account_number, double balance)
	:player(player),
	account_number(account_number),
	balance(balance){};


void Account::initialize_balance(){
	this->balance = 100000.00;
}

double Account::get_balance(){

	return balance;
}

void Account::create_account_number(){
	
	char address[8];

     for(int i =0; i<8; i++){

		 address[i] = codebook[rand()%69];

	 }

	 this->account_number = address;
 
}

void Account::input_record(Transaction t, Date* d){

	if (t.GetTransactionType() == "Buy Stock"){

		balance -= t.GetAmount();
		string tmp = account_number+to_string(d->GetMonth())+":"+to_string(d->GetDay())+":"+to_string(d->GetYear())+",		Description:"+t.GetTransactionType()+", Amount:"+to_string(t.GetAmount())+", current balance:"+ to_string(balance);
		log.push_back(tmp);
	}
	else if (t.GetTransactionType() == "Sell Stock"){

		balance += t.GetAmount();
		string tmp = account_number+to_string(d->GetMonth())+":"+to_string(d->GetDay())+":"+to_string(d->GetYear())+",		Description:"+t.GetTransactionType()+", Amount:"+to_string(t.GetAmount())+", current balance:"+ to_string(balance);
		log.push_back(tmp);
	}
	else if (t.GetTransactionType() == "Bank Account Deposit"){

		balance += t.GetAmount();
		string tmp = account_number+to_string(d->GetMonth())+":"+to_string(d->GetDay())+":"+to_string(d->GetYear())+",		Description:"+t.GetTransactionType()+", Amount:"+to_string(t.GetAmount())+", current balance:"+ to_string(balance);
		log.push_back(tmp);
	}
	else if (t.GetTransactionType() == "Bank Account Withraw"){

		balance -= t.GetAmount();
		string tmp = account_number+to_string(d->GetMonth())+":"+to_string(d->GetDay())+":"+to_string(d->GetYear())+",		Description:"+t.GetTransactionType()+", Amount:"+to_string(t.GetAmount())+", current balance:"+ to_string(balance);
		log.push_back(tmp);
	}

}


void Account::print_record() {

	if(log.empty()){
		cout << "There is no transaction yet." << endl;
	}

	else{

	for(int i=0; i<log.size();i++){
		cout<<log.at(i);
	}
	}

}

void Account::info_Account(){

	cout << "User "<< player->getPlayerName() << "'s account" << endl;
	cout << "Bank fo transaction : " << bank_name << endl;
	cout << "Account number : " << account_number << endl;
	cout << "Current balance : " << get_balance() << endl;
	print_record();

}


