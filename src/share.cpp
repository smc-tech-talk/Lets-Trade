#include "share.hpp"

Share::Share(){};
Share::Share(Stock* s, int a)
    :stock(s),
    position(a){};

// Methods
void Share::IncreaseAmount(int a)
{
    double current = ( this->stock )->GetCurrentPrice();
    Stock* s = this->stock;
    cout << *s << endl;
    this->position += a;
    SetValue(current * this->position);
};
void Share::DecreaseAmount(int a)
{
    double current = ( this->stock )->GetCurrentPrice();
    if(this->position > 0)
        this->position -= a;
    SetValue(current * this->position);
    Transaction newTransaction = Transaction(STOCK_SELL);
    Transaction::AddTransaction(this->transactionHistory, newTransaction);
};

// Getter
Stock Share::GetStock()
    { return *(this->stock); };
Stock* Share::GetStockPtr()
    { return this->stock; };
int Share::GetPosition()
    { return this->position; };
std::vector<Transaction> Share::GetTransactionHistory()
    { return this->transactionHistory; };

// Settter
void Share::SetValue(double v)
    { this->value = v; };
