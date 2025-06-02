#include "Client.h"
#include "Product.h"
#include "Client.h"
#include "Shop.h"

int main()
{
    Shop shop;
    shop.printStock();
    // int option;
    // do
    // {
    //     system("CLS"); // Limpa a tela
    //     cout << endl
    //          << BRIGHT_YELLOW << "|=============| "
    //          << "Papelaria Note & Book"
    //          << " |==============|\n"
    //          << RESET;
    //     cout << endl;
    //     cout << "[1] Produtos Disponiveis\n";
    //     cout << "[2] Carrinho\n";
    //     cout << "[3] Checkout\n";
    //     cout << "[4] Adicionar Produto\n";
    //     cout << "[5] Eliminar Produto\n";
    //     cout << "[6] Modificar Preco\n";
    //     cout << "[7] Sair\n";
    //     cout << "Escolha uma opcao: ";

    //     if (!(cin >> option))
    //     {
    //         cin.clear();
    //         cin.ignore(1000, '\n');
    //         cout << "Apenas pode inserir numeros. Por favor tente novamente.\n";
    //     }

    //     switch (option)
    //     {
    //     case 1:
    //         // Mostrar produtos disponíveis
    //         system("CLS"); // Limpa a tela
    //         // adicionar metodo
    //         break;
    //     case 2:
    //         // Comprar produto
    //         system("CLS"); // Limpa a tela
    //         // adicionar metodo
    //         break;
    //     case 3:
    //         // Carrinho
    //         system("CLS"); // Limpa a tela
    //                        // adicionar metodo
    //         break;
    //     case 4:
    //         // Adicionar produto
    //         system("CLS"); // Limpa a tela
    //         // adicionar metodo
    //         break;
    //     case 5:
    //         // Eliminar produto
    //         system("CLS"); // Limpa a tela
    //         // adicionar metodo
    //         break;
    //     case 6:
    //         // Modificar preço do produto
    //         system("CLS"); // Limpa a tela
    //         // adicionar metodo
    //         break;
    //     case 7:
    //         cout << RED << endl
    //              << "A desligar o programa...\n"
    //              << RESET;
    //         break;
    //     default:
    //         // Opcao invalida
    //         cout << endl
    //              << "Opcao invalida. Tente novamente.\n";
    //         break;
    //     }
    //     if (option != 7)
    //     {
    //         cout << endl
    //              << "Pressione Enter para voltar ao menu.";
    //         cin.ignore();
    //         cin.get(); // Espera o utilizador pressionar Enter
    //     }
    // } while (option != 7); // Repete o menu até sair do programa
}