/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"
#include "player.cpp"
#include "transaction.cpp"
//#include "player.cpp"

int main(){
    /* Initializing Data */
    srand(time(NULL));

    Player* p = new Player("Ben");

    delete p;
    p=NULL;
    return 0;
}
