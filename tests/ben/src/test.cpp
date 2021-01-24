/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "transaction.cpp"
#include "share.cpp"

int main() {
    Date* d = new Date();
    cout << *d << endl;
    for (int i = 0; i < 50; i++)
        Date::AddGameTime(d);
    cout << *d << endl;
    for (int i = 0; i < 50; i++)
        Date::AddGameTime(d);
        cout << *d << endl;

    delete d;
    d = NULL;
    return 0;
}
