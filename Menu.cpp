#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <windows.h>
#include <conio.h>
#include "Menu.h"
#include "Sales.h"
#include "Shop.h"

#define RESET "\033[0m"          // Define a cor de texto para padrão
#define RED "\033[31m"           // Define a cor de texto para vermelho
#define GREEN "\033[32m"         // Define a cor de texto para verde
#define BRIGHT_YELLOW "\033[93m" // Define a cor de texto amarelo brilhante

Shop shop;

Menu::Menu()
{
}
const int MENU_WIDTH = 50;

void printCentered(const string &text, int width = MENU_WIDTH)
{
    int len = static_cast<int>(text.length());
    int left = (width - len) / 2;
    if (left < 0)
        left = 0;
    cout << setw(left + len) << text << endl;
}

void Menu::mainMenu()
{
    int option;
    do
    {
        system("CLS");
        cout << BRIGHT_YELLOW;
        printCentered("+------------------------------------------------+");
        printCentered("|              THE GAME VAULT MENU               |");
        printCentered("+------------------------------------------------+");
        printCentered("| [1] Venda                                      |");
        printCentered("| [2] Stock                                      |");
        printCentered("| [3] Clientes                                   |");
        printCentered("| [4] Relatorios                                 |");
        printCentered("| [5] Sair                                       |");
        printCentered("+------------------------------------------------+");
        cout << RESET << endl;

        option = shop.intInputValidation("Escolha uma opcao: ");

        switch (option)
        {
        case 1:
            system("CLS");
            buyMenu();
            break;
        case 2:
            system("CLS");
            stockMenu();
            break;
        case 3:
            system("CLS");
            clientMenu();
            break;
        case 4:
            system("CLS");
            salesMenu();
            break;
        case 5:
            cout << RED;
            printCentered("A desligar o programa...");
            cout << RESET;
            break;
        default:
            cout << RED;
            printCentered("Opcao invalida. Tente novamente.");
            cout << RESET;
            Sleep(2000);
            break;
        }
    } while (option != 5); // Repete o menu até sair do programa
}

void Menu::stockMenu()
{
    int option;
    do
    {
        system("CLS");
        shop.printStock();
        cout << endl
             << endl;
        cout << BRIGHT_YELLOW;
        printCentered("+----------------------------------------------+");
        printCentered("|               MENU DE STOCK                  |");
        printCentered("+----------------------------------------------+");
        printCentered("| [1] Adicionar Produto                        |");
        printCentered("| [2] Remover Produto                          |");
        printCentered("| [3] Modificar Preco                          |");
        printCentered("| [4] Modificar Quantidade                     |");
        printCentered("| [5] Voltar ao Menu                           |");
        printCentered("+----------------------------------------------+");
        cout << RESET << endl;
        cout << endl;

        option = shop.intInputValidation("Escolha uma opcao: ");

        switch (option)
        {
        case 1:
            system("CLS");
            shop.addProductstock();
            break;
        case 2:
            system("CLS");
            shop.removeProductstock();
            break;
        case 3:
            system("CLS");
            shop.setProductPrice();
            break;

        case 4:
            system("CLS");
            shop.setProductQuantity();
            break;
        case 5:
            break;
        default:
            cout << RED;
            printCentered("Opcao invalida. Tente novamente.");
            cout << RESET;
            Sleep(2000);
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
        shop.printClientList();
        cout << endl
             << endl;
        cout << BRIGHT_YELLOW;
        printCentered("+----------------------------------------------+");
        printCentered("|              MENU DE CLIENTES                |");
        printCentered("+----------------------------------------------+");
        printCentered("| [1] Adicionar Cliente                        |");
        printCentered("| [2] Remover Cliente                          |");
        printCentered("| [3] Modificar Telefone                       |");
        printCentered("| [4] Modificar Morada                         |");
        printCentered("| [5] Modificar Nome                           |");
        printCentered("| [6] Voltar ao Menu                           |");
        printCentered("+----------------------------------------------+");
        cout << RESET << endl;

        cout << endl;

        option = shop.intInputValidation("Escolha uma opcao: ");

        switch (option)
        {
        case 1:
            system("CLS");
            shop.addClient();
            break;
        case 2:
            system("CLS");
            shop.removeFromclientlist();
            break;
        case 3:
            system("CLS");
            shop.setClientPhone();
            break;
        case 4:
            system("CLS");
            shop.setClientAddress();
            break;
        case 5:
            system("CLS");
            shop.setclientName();
            break;
        case 6:
            break;
        default:
            cout << RED;
            printCentered("Opcao invalida. Tente novamente.");
            cout << RESET;
            Sleep(2000);
            break;
        }
    } while (option != 6);
}

void Menu::buyMenu()
{
    int option;
    do
    {
        system("CLS");
        shop.printCart();
        cout << endl
             << endl;
        cout << BRIGHT_YELLOW;
        printCentered("+----------------------------------------------+");
        printCentered("|                 MENU DE VENDA                |");
        printCentered("+----------------------------------------------+");
        printCentered("| [1] Adicionar ao Carrinho                    |");
        printCentered("| [2] Remover do Carrinho                      |");
        printCentered("| [3] Modificar Quantidade                     |");
        printCentered("| [4] Checkout                                 |");
        printCentered("| [5] Cancelar Compra                          |");
        printCentered("| [6] Voltar ao Menu                           |");
        printCentered("+----------------------------------------------+");
        cout << RESET << endl;

        option = shop.intInputValidation("Escolha uma opcao: ");

        switch (option)
        {
        case 1:
            system("CLS");
            shop.addProductInCart();
            break;
        case 2:
            system("CLS");
            shop.removefromCart();
            break;
        case 3:
            system("CLS");
            shop.modifyqntCart();
            break;
        case 4:
            system("CLS");
            shop.checkout();
            break;
        case 5:
            system("CLS");
            shop.clearCart();
            break;
        case 6:
            break;
        default:
            cout << RED;
            printCentered("Opcao invalida. Tente novamente.");
            cout << RESET;
            Sleep(2000);
            break;
        }
    } while (option != 6); // Repete o menu até sair do menu de venda
}

void Menu::reportMenu()
{
}

void Menu::salesMenu()
{
    int option;
    do
    {
        system("CLS");
        cout << BRIGHT_YELLOW;
        printCentered("+----------------------------------------------+");
        printCentered("|             MENU DE RELATORIOS               |");
        printCentered("+----------------------------------------------+");
        printCentered("| [1] Imprimir Vendas                          |");
        printCentered("| [2] Produto Mais Vendido                     |");
        printCentered("| [3] Produto Menos Vendido                    |");
        printCentered("| [4] Valor de Lucro do Produto mais Vendido   |");
        printCentered("| [5] Cliente que mais Comprou                 |");
        printCentered("| [6] Estatisticas de Produto                  |");
        printCentered("| [7] Stock Total                              |");
        printCentered("| [8] Voltar ao Menu                           |");
        printCentered("+----------------------------------------------+");
        cout << RESET << endl;

        option = shop.intInputValidation("Escolha uma opcao: ");

        switch (option)
        {
        case 1:
            system("CLS");
            shop.printSales();
            break;
        case 2:
            system("CLS");
            shop.printBestSeller();
            break;
        case 3:
            system("CLS");
            shop.printWorstProduct();
            break;
        case 4:
            system("CLS");
            shop.printBestProductProfit();
            break;
        case 5:
            system("CLS");
            shop.printBestClient();
            break;
        case 6:
            system("CLS");
            shop.salesSearch();
            break;
        case 7:
            system("CLS");
            shop.printTotalStock();
            break;
        case 8:
            break;
        default:
            cout << RED;
            printCentered("Opcao invalida. Tente novamente.");
            cout << RESET;
            Sleep(2000);
            break;
        }
    } while (option != 8);
}

bool Menu::login()
{
    system("CLS");
    string utilizador, senha, senhaEscondida;
    char caracter;

    cout << "====== LOGIN ADMIN ======";
    cout << "\n Utilizador: ";
    getline(cin, utilizador); // Lê a linha inteira, mesmo com espaços (ex: "admin arroz")
    cout << "\n Palavra-Passe: ";

    // Ler a senha sem mostrá-la
    while ((caracter = _getch()) != 13) // Repete até carregar ENTER (ASCII 13)
    {
        if (caracter == 8 && !senhaEscondida.empty()) // BACKSPACE (ASCII 8) apaga último char
        {
            senhaEscondida.pop_back();
            cout << "\b \b"; // Apaga último caracteres no terminal
        }
        else if (caracter != 8)
        {
            senhaEscondida.push_back(caracter); // Adiciona os caracteres digitados na string senhaEscondida
            cout << "*";                        // Mostra * por cada caracter digitado
        }
    }

    senha = senhaEscondida;

    if (utilizador == "admin" && senha == "admin123")
    {
        system("CLS");
        cout << GREEN
             << "Bem-Vindo!"
             << RESET;
        Sleep(3000);

        return true;
    }
    cout << RED << endl
         << "\nAs credenciais sao invalidas!\n"
         << RESET;
    Sleep(3000);
    return false;
}

void Menu::asciiArt()
{
    cout << BRIGHT_YELLOW << endl
         << R"(
_________  ___  ___  _______
|\___   ___\\  \|\  \|\  ___ \
\|___ \  \_\ \  \\\  \ \   __/|
     \ \  \ \ \   __  \ \  \_|/__
      \ \  \ \ \  \ \  \ \  \_|\ \
       \ \__\ \ \__\ \__\ \_______\
        \|__|  \|__|\|__|\|_______|
                                                    
                                                    
                                                    
 ________  ________  _____ ______   _______
|\   ____\|\   __  \|\   _ \  _   \|\  ___ \
\ \  \___|\ \  \|\  \ \  \\\__\ \  \ \   __/|
 \ \  \  __\ \   __  \ \  \\|__| \  \ \  \_|/__
  \ \  \|\  \ \  \ \  \ \  \    \ \  \ \  \_|\ \
   \ \_______\ \__\ \__\ \__\    \ \__\ \_______\
    \|_______|\|__|\|__|\|__|     \|__|\|_______|
                                                    
                                                    
                                                    
 ___      ___ ________  ___  ___  ___   _________
|\  \    /  /|\   __  \|\  \|\  \|\  \ |\___   ___\
\ \  \  /  / | \  \|\  \ \  \\\  \ \  \\|___ \  \_|
 \ \  \/  / / \ \   __  \ \  \\\  \ \  \    \ \  \
  \ \    / /   \ \  \ \  \ \  \\\  \ \  \____\ \  \
   \ \__/ /     \ \__\ \__\ \_______\ \_______\ \__\
    \|__|/       \|__|\|__|\|_______|\|_______|\|__|
       )" << endl
         << RESET;
    Sleep(3000);
}