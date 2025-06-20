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
            buyMenu();
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
        shop.printStock();
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
        shop.printClientList();
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
            shop.addClient();
            break;
        case 2:
            system("CLS");
            // adicionar metodo
            shop.removeFromclientlist();
            break;
        case 3:
            system("CLS");
            // adicionar metodo
            shop.setClientPhone();
            break;
        case 4:
            system("CLS");
            // adicionar metodo
            shop.setClientAddress();
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

void Menu::buyMenu()
{
    int option;
    do
    {
        system("CLS");
        shop.printCart();
        cout << endl
             << endl;
        cout << "[1] Adicionar ao Carrinho\n";
        cout << "[2] Remover do Carrinho\n";
        cout << "[3] Modificar Quantidade\n";
        cout << "[4] Checkout\n";
        cout << "[5] Cancelar Compra\n";
        cout << "[6] Voltar ao Menu\n";
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
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (option != 5); // Repete o menu até sair do programa
}

void Menu::reportMenu()
{
}

bool Menu::login()
{
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
    return false;
}
