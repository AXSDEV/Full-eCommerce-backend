#ifndef MENU_H
#define MENU_H
#include "Stock.h"
#include "ClientList.h"
#include "Sales.h"
#include "Shop.h"

class Menu
{

public:
    Menu();
    void mainMenu();
    void stockMenu();
    void clientMenu();
    void salesMenu();
    void buyMenu();
    void reportMenu();

private:
    ClientList list;
    Stock products;
};

#endif