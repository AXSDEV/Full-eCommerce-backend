#include "Menu.h"

int main()
{
    Menu menu;
    while (menu.login() == false)
    {
        cout << RED
             << "Tente novamente.\n"
             << RESET;
    }
    menu.mainMenu();
    return 0;
}