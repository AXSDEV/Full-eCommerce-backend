#ifndef SHOP_H
#define SHOP_H
#include "Product.h"

#define RESET "\033[0m"          // Define a cor de texto para padrão
#define RED "\033[31m"           // Define a cor de texto para vermelho
#define GREEN "\033[32m"         // Define a cor de texto para verde
#define BRIGHT_YELLOW "\033[93m" // Define a cor de texto amarelo brilhante

class Shop
{
    Product products[100];
    int sizeStock = 0;

public:
    Shop();
    void saveProduct(string name, int quantity, double priceWoiva);
    int searchProduct(string name);
    void printStock();
    void printProduct(int i);
    void removeProduct(string name);
    void addProductstock();
    void removeProductstock();

private:
};

#endif