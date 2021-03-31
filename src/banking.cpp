#include "banking.hpp"

Account::Account(Player* a_player) {

	player = a_player;
	bank_name = list_bank[rand()%9];
	create_account_number();
	initialize_balance();

}
// 트랜스액션 함수로 돈 조절하는거 따로 만들기!
// 텍스트

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

void Account::bal_change(Transaction t){
	if(t.GetTransactionType()=="Buy Stock"||"Bank Account Withraw"){
		balance -= t.GetAmount();
	}
	else if (t.GetTransactionType() == "Sell Stock"||"Bank Account Deposit"){
		balance += t.GetAmount();
	}
}

string Account::create_log(Transaction t, Date* d){
	string tmp = account_number+to_string(d->GetMonth())+":"+to_string(d->GetDay())+":"+to_string(d->GetYear())+",	Description:"+t.GetTransactionType()+", Amount:"+to_string(t.GetAmount())+", current balance:"+ to_string(balance);
	return tmp;
}

void Account::input_record(Transaction t, Date* d){

		bal_change(t);
		string tmp = create_log(t,d);
		log.push_back(tmp);

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

	cout << "User "<< player->GetName() << "'s account" << endl;
	cout << "Bank fo transaction : " << bank_name << endl;
	cout << "Account number : " << account_number << endl;
	cout << "Current balance : " << get_balance() << endl;
	print_record();

}