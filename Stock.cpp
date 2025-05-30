#include "Stock.h"

void Stock::saveProduct(int id, string name, int quantity, double priceWoiva)
{
    if (tamanhoStock < 100)
    {
        Product product(id, name, quantity, priceWoiva);
        products[tamanhoStock] = product;
        tamanhoStock++;
    }
    else
    {
        cout << "Stock encontrasse cheio ! " << endl;
    }
}

int Stock::searchProduct(string name)
{
    for (int i = 0; i < tamanhoStock; i++)
    {
        if (name == products[i].getName())
        {
            return i;
        }
    }
    return -1;
}
void Stock::printStock()
{
    for (int i = 0; i < tamanhoStock; i++)
    {
        cout << endl
             << products[i].tostring();
    }
}
