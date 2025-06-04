#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "Menu.h"
#include "Stock.h"
#include "ClientList.h"
#define RESET "\033[0m"          // Define a cor de texto para padrão
#define RED "\033[31m"           // Define a cor de texto para vermelho
#define GREEN "\033[32m"         // Define a cor de texto para verde
#define BRIGHT_YELLOW "\033[93m" // Define a cor de texto amarelo brilhante

Menu::Menu()
{
}

void Menu::mainMenu()
{
    int option;
    do
    {
        system("CLS");
        cout << endl
             << BRIGHT_YELLOW << "|=============| "
             << "Papelaria Note & Book"
             << " |==============|\n"
             << RESET;
        cout << endl;
        cout << "[1] Comprar\n";
        cout << "[2] Stock\n";
        cout << "[3] Vendas\n";
        cout << "[4] Clientes\n";
        cout << "[5] Relatorios\n";
        cout << "[6] Sair\n";
        cout << "Escolha uma opcao: ";
        if (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Apenas pode inserir numeros. Por favor tente novamente.\n";
            Sleep(2400);
        }
        switch (option)
        {
        case 1:
            system("CLS");
            // adicionar Menu de Compra
            break;
        case 2:
            system("CLS");
            stockMenu();
            break;
        case 3:
            system("CLS");
            // Adicionar Menu de Vendas
            break;
        case 4:
            system("CLS");
            clientMenu();
            break;
        case 5:
            system("CLS");
            // Adicionar Menu de Relatorios
            break;
        case 6:
            cout << RED << endl
                 << "A desligar o programa...\n"
                 << RESET;
            break;
        default:
            cout << endl
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (option != 6); // Repete o menu até sair do programa
}

void Menu::stockMenu()
{
    int option;
    do
    {
        system("CLS");
        products.printStock();
        cout << endl
             << endl;
        cout << "[1] Adicionar Produto\n";
        cout << "[2] Remover Produto\n";
        cout << "[3] Modificar Preco\n";
        cout << "[4] Modificar Quantidade\n";
        cout << "[5] Voltar ao Menu\n";
        cout << "Escolha uma opcao: ";
        if (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Apenas pode inserir numeros. Por favor tente novamente.\n";
            Sleep(2400);
        }
        switch (option)
        {
        case 1:
            system("CLS");
            products.addProductstock();
            break;
        case 2:
            system("CLS");
            products.removeProductstock();
            break;
        case 3:
            system("CLS");
            products.setProductPrice();
            break;

        case 4:
            system("CLS");
            products.setProductQuantity();
            break;
        case 5:
            break;
        default:
            // Opcao invalida
            cout << endl
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (option != 5); // Repete o menu até sair do programa
}
void Menu::clientMenu()
{
    int option;
    do
    {
        system("CLS");
        list.printClientList();
        cout << endl
             << endl;
        cout << "[1] Adicionar Cliente\n";
        cout << "[2] Remover Cliente\n";
        cout << "[3] Modificar Telefone\n";
        cout << "[4] Modificar Telefone\n";
        cout << "[5] Voltar ao Menu\n";
        cout << "Escolha uma opcao: ";
        if (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Apenas pode inserir numeros. Por favor tente novamente.\n";
            Sleep(2400);
        }
        switch (option)
        {
        case 1:
            system("CLS");
            // adicionar metodo
            list.addClient();
            break;
        case 2:
            system("CLS");
            // adicionar metodo
            list.removeFromclientlist();
            break;
        case 3:
            system("CLS");
            // adicionar metodo
            list.setClientPhone();
            break;
        case 4:
            system("CLS");
            // adicionar metodo
            list.setClientAddress();
            break;
        default:
            // Opcao invalida
            cout << endl
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (option != 5); // Repete o menu até sair do programa
}

void Menu::buyMenu()
{
}

void Menu::reportMenu()
{
}
