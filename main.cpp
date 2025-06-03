#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "Client.h"
#include "Product.h"
#include "Client.h"
#include "Shop.h"

Shop products;
void mainMenu();
void stockMenu();
void clientMenu();

void mainMenu()
{
    int option;
    do
    {
        system("CLS"); // Limpa a tela
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
            system("CLS"); // Limpa a tela
            // adicionar Menu de Compra
            break;
        case 2:
            system("CLS"); // Limpa a tela
            stockMenu();
            break;
        case 3:
            system("CLS"); // Limpa a tela
            // Adicionar Menu de Vendas
            break;
        case 4:
            system("CLS"); // Limpa a tela
            clientMenu();
            break;
        case 5:
            system("CLS"); // Limpa a tela
            // Adicionar Menu de Relatorios
            break;
        case 6:
            cout << RED << endl
                 << "A desligar o programa...\n"
                 << RESET;
            break;
        default:
            // Opcao invalida
            cout << endl
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (option != 6); // Repete o menu até sair do programa
}

void stockMenu()
{
    int option;
    do
    {
        system("CLS"); // Limpa a tela
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
            system("CLS"); // Limpa a tela
            products.addProductstock();
            break;
        case 2:
            system("CLS"); // Limpa a tela
            products.removeProductstock();
            break;
        case 3:
            system("CLS"); // Limpa a tela
            products.setProductPrice();
            break;

        case 4:
            system("CLS"); // Limpa a tela
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

void clientMenu()
{
    int option;
    do
    {
        system("CLS"); // Limpa a tela
        products.printClientList();
        cout << endl
             << endl;
        cout << "[1] Adicionar Cliente\n";
        cout << "[2] Remover Cliente\n";
        cout << "[3] Modificar Telefone\n";
        cout << "[4] Modificar Morada\n";
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
            system("CLS"); // Limpa a tela
            // adicionar metodo
            products.addClient();
            break;
        case 2:
            system("CLS"); // Limpa a tela
            // adicionar metodo
            products.removeFromclientlist();
            break;
        case 3:
            system("CLS"); // Limpa a tela
            // adicionar metodo
            products.setClientPhone();
            break;
        case 4:
            system("CLS"); // Limpa a tela
            // adicionar metodo
            products.setClientAddress();
            break;
        default:
            // Opcao invalida
            cout << endl
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (option != 5); // Repete o menu até sair do programa
}

int main()
{
    mainMenu();
}
