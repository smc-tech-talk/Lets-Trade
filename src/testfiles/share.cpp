#include "share.hpp"

Share::Share(){};
Share::Share(Stock* s, int a)
    :stock(s),
    position(a){};

// Methods
void Share::IncreaseAmount(int a)
    { this->position += a; };
void Share::DecreaseAmount(int a)
    { this->position -= a; };

// Getter
Stock Share::GetStock()
    { return *(this->stock); };
Stock* Share::GetStockPtr()
    { return this->stock; };
int Share::GetPosition()
    { return this->position; };
