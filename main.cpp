#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "Client.h"
#include "Product.h"
#include "Client.h"
#include "Shop.h"

#include "Menu.h"

Shop products;

int main()
{
    Menu menu;
    menu.mainMenu();
    return 0;
}
