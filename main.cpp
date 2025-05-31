#include "Client.h"
#include "Product.h"
#include "Stock.h"
#include "Client.h"
#include "Shop.h"

int main()
{
    /*
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
        cout << "[1] Produtos Disponiveis\n";
        cout << "[2] Carrinho\n";
        cout << "[3] Checkout\n";
        cout << "[4] Adicionar Produto\n";
        cout << "[5] Eliminar Produto\n";
        cout << "[6] Modificar Preco\n";
        cout << "[7] Sair\n";
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
            // Mostrar produtos disponíveis
            system("CLS"); // Limpa a tela
            // adicionar metodo
            break;
        case 2:
            // Comprar produto
            system("CLS"); // Limpa a tela
            // adicionar metodo
            break;
        case 3:
            // carrinho
            system("CLS"); // Limpa a tela
                           // adicionar metodo
            break;
        case 4:
            // Adicionar produto
            system("CLS"); // Limpa a tela
            // adicionar metodo
            break;
        case 5:
            // Eliminar produto
            system("CLS"); // Limpa a tela
            // adicionar metodo
            break;
        case 6:
            // Modificar preço do produto
            system("CLS"); // Limpa a tela
            // adicionar metodo
            break;
        case 7:
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
        if (option != 7)
        {
            cout << endl
                 << "Pressione Enter para voltar ao menu.";
            cin.ignore();
            cin.get(); // Espera o utilizador pressionar Enter
        }
    } while (option != 7); // Repete o menu até sair do programa
*/
    // Preenchimento do Objeto
    Stock products;
    products.saveProduct(1, "Lapis", 20, 0.20);
    products.saveProduct(2, "Caneta", 20, 0.40);
    products.saveProduct(3, "Caderno", 20, 1.50);
    products.saveProduct(4, "Borracha", 15, 0.30);
    products.saveProduct(5, "Apontador", 10, 0.50);
    products.saveProduct(6, "Regua", 12, 0.80);
    products.saveProduct(7, "Marcador", 18, 1.20);
    products.saveProduct(8, "Bloco Notas", 8, 2.00);
    products.saveProduct(9, "Estojo", 5, 3.50);
    products.saveProduct(10, "Mochila", 3, 12.00);

    products.printStock(); // Impressao do Stock
}