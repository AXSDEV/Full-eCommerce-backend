#ifndef STOCK_H
#define STOCK_H
#include "Product.h"

class Stock
{

public:
    // Criacao do Vector do Objecto Products
    Product products[100];
    int sizeStock = 0;
    Stock();
    void saveProduct(string name, int quantity, double priceWoiva);
    int searchProduct(int id);
    void printStock();
    void printProduct(int i);
    void removeProduct(int id);
    void addProductstock();
    void removeProductstock();
    void setProductPrice();
    void setProductQuantity();

private:
};

#endif