#ifndef STOCK_H
#define STOCK_H
#include "Product.h"

class Stock
{
    Product products[100];
    int sizeStock = 0;

public:
    void saveProduct(int id, string name, int quantity, double priceWoiva);
    int searchProduct(string name);
    void printStock();
    void printProduct(int i);
    void removeProduct(string name);

private:
};

#endif