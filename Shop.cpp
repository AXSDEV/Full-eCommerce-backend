#include "Shop.h"
#include "Product.h"
#include "Client.h"
Shop::Shop()
{
    saveProduct(1, "Lapis", 20, 0.20);
    saveProduct(2, "Caneta", 20, 0.40);
    saveProduct(3, "Caderno", 20, 1.50);
    saveProduct(4, "Borracha", 15, 0.30);
    saveProduct(5, "Apontador", 10, 0.50);
    saveProduct(6, "Regua", 12, 0.80);
    saveProduct(7, "Marcador", 18, 1.20);
    saveProduct(8, "Bloco Notas", 8, 2.00);
    saveProduct(9, "Estojo", 5, 3.50);
    saveProduct(10, "Mochila", 3, 12.00);
}

void Shop::saveProduct(int id, string name, int quantity, double priceWoiva)
{
    if (sizeStock < 100)
    {
        Product product(id, name, quantity, priceWoiva);
        products[sizeStock] = product;
        sizeStock++;
    }
    else
    {
        cout << "Stock encontrasse cheio ! " << endl;
    }
}

int Shop::searchProduct(string name)
{
    for (int i = 0; i < sizeStock; i++)
    {
        if (name == products[i].getName())
        {
            return i;
        }
    }
    return -1;
}
void Shop::printStock()
{
    cout << left << setw(5) << "ID"
         << setw(20) << "Nome"
         << setw(10) << "Qnt"
         << setw(10) << "Preco" << endl;
    for (int i = 0; i < sizeStock; i++)
    {
        cout << endl
             << products[i].tostring();
    }
}
void Shop::printProduct(int i)
{
    if (i > 0 && i < sizeStock)
    {
        cout << endl
             << products[i].tostring();
    }
    else
    {
        cout << endl
             << "Nao existe esse Produto";
    }
}
void Shop::removeProduct(string name)
{
    int position = searchProduct(name);
    for (int i = position; i < sizeStock; i++)
    {
        products[i] = products[i + 1];
    }
    sizeStock--;
}

// Shop::Shop()
