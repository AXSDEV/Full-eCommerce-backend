#ifndef MENU_H
#define MENU_H
#include "Shop.h"
#include "Product.h"
#include "Client.h"

class Menu
{
public:
    Menu();
    void mainMenu();
    void stockMenu();
    void clientMenu();
    void salesMenu();
    void buyMenu();
    void relatoryMenu();

private:
    Shop products;
    Shop list;
};

#endif