#include "Client.h"
#include "Product.h"
#include "Client.h"
#include "Shop.h"
Shop products;
void mainMenu();
void stockMenu();

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
        cout << "[1] Stock\n";
        cout << "[2] Vendas\n";
        cout << "[3] Clientes\n";
        cout << "[4] Relatorios\n";
        cout << "[5] Sair\n";
        cout << "Escolha uma opcao: ";
        if (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Apenas pode inserir numeros. Por favor tente novamente.\n";
        }
        switch (option)
        {
        case 1:
            system("CLS"); // Limpa a tela
            stockMenu();
            break;
        case 2:
            system("CLS"); // Limpa a tela
            break;
        case 3:
            system("CLS"); // Limpa a tela
            break;
        case 4:
            system("CLS"); // Limpa a tela
            break;
        case 5:
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
    } while (option != 7); // Repete o menu até sair do programa
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
        cout << "[4] Voltar ao Menu\n";
        cout << "Escolha uma opcao: ";
        if (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Apenas pode inserir numeros. Por favor tente novamente.\n";
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
            // adicionar metodo
            break;
        case 4:
            break;
        default:
            // Opcao invalida
            cout << endl
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (option != 4); // Repete o menu até sair do programa
}

int main()
{
    mainMenu();
}
