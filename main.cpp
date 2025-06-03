#include "Client.h"
#include "Product.h"
#include "Client.h"
#include "Shop.h"
#include "Menu.h"
#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

Shop products;

int main()
{
    Menu menu;
    menu.mainMenu();
    return 0;
}
