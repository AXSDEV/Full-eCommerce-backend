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

void Menu::mainMenu()
{
    int option;
    do
    {
        system("CLS");
        cout << BRIGHT_YELLOW << "|=============| "
             << "The Game Vault"
             << " |==============|\n"
             << RESET;
        cout << endl;
        cout << "[1] Venda\n";
        cout << "[2] Stock\n";
        cout << "[3] Clientes\n";
        cout << "[4] Relatorios\n";
        cout << "[5] Sair\n";

        option = shop.intInputValidation("Escolha uma opcao: ");

        switch (option)
        {
        case 1:
            system("CLS");
            // adicionar Menu de Compra
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
            cout << RED << endl
                 << "A desligar o programa...\n"
                 << RESET;
            break;
        default:
            // Opcao invalida
            cout << endl
                 << RED
                 << "Opcao invalida. Tente novamente.\n"
                 << RESET;
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
        cout << BRIGHT_YELLOW << "|==============| "
             << "Menu Stock"
             << " |===============|\n"
             << RESET;
        shop.printStock();
        cout << endl
             << endl;
        cout << "[1] Adicionar Produto\n";
        cout << "[2] Remover Produto\n";
        cout << "[3] Modificar Preco\n";
        cout << "[4] Modificar Quantidade\n";
        cout << "[5] Voltar ao Menu\n";

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
            // Opcao invalida
            cout << endl
                 << RED
                 << "Opcao invalida. Tente novamente.\n"
                 << RESET;
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

        cout << BRIGHT_YELLOW << "|=====================================| "
             << "Menu Cliente"
             << " |=====================================|\n"
             << RESET;
        shop.printClientList();
        cout << endl
             << endl;
        cout << "[1] Adicionar Cliente\n";
        cout << "[2] Remover Cliente\n";
        cout << "[3] Modificar Telefone\n";
        cout << "[4] Modificar Morada\n";
        cout << "[5] Modificar Nome\n";
        cout << "[6] Voltar ao Menu\n";

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
            // Opcao invalida
            cout << endl
                 << RED
                 << "Opcao invalida. Tente novamente.\n"
                 << RESET;
            Sleep(2000);
            break;
        }
    } while (option != 6); // Repete o menu até sair do programa
}

void Menu::buyMenu()
{
    int option;
    do
    {
        system("CLS");
        shop.printCart();
        cout << BRIGHT_YELLOW << endl
             << "|========================| "
             << "Menu Venda"
             << " |=========================|\n"
             << RESET;
        cout << endl;
        cout << "[1] Adicionar ao Carrinho\n";
        cout << "[2] Remover do Carrinho\n";
        cout << "[3] Modificar Quantidade\n";
        cout << "[4] Checkout\n";
        cout << "[5] Cancelar Compra\n";
        cout << "[6] Voltar ao Menu\n";

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
            // Opcao invalida
            cout << endl
                 << RED
                 << "Opcao invalida. Tente novamente.\n"
                 << RESET;
            Sleep(2000);
            break;
        }
    } while (option != 6); // Repete o menu até sair do programa
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
        cout << BRIGHT_YELLOW << "|=============| "
             << "Menu Relatorios"
             << " |==============|\n"
             << RESET;
        cout << endl;
        cout << "[1] Imprimir Vendas\n";
        cout << "[2] Produto Mais Vendido\n";
        cout << "[3] Produto Menos Vendido\n";
        cout << "[4] Valor de Lucro do Produto mais Vendido\n";
        cout << "[5] Cliente que mais Comprou\n";
        cout << "[6] Estatisticas de Produto\n";
        cout << "[7] Stock Total\n";
        cout << "[8] Voltar ao Menu\n";

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
            // Opcao invalida
            cout << endl
                 << RED
                 << "Opcao invalida. Tente novamente.\n"
                 << RESET;
            Sleep(2000);
            break;
        }
    } while (option != 8); // Repete o menu até sair do programa
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