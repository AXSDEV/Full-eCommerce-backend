#ifndef MENU_H
#define MENU_H
#include "Client.h"
#include "Product.h"
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
    bool login();

private:
    Shop list;
    Shop products;
    Shop cart;
};

#endif