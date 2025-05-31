#include "Stock.h"

void Stock::saveProduct(int id, string name, int quantity, double priceWoiva)
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

int Stock::searchProduct(string name)
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
void Stock::printStock()
{
    for (int i = 0; i < sizeStock; i++)
    {
        cout << endl
             << products[i].tostring();
    }
}
void Stock::printProduct(int i)
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
void Stock::removeProduct(string name)
{
    int position = searchProduct(name);
    for (int i = position; i < sizeStock; i++)
    {
        products[i] = products[i + 1];
    }
    sizeStock--;
}
