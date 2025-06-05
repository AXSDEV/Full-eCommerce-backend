#ifndef SHOP_H
#define SHOP_H
#include "Stock.h"
#include "ClientList.h"
#include "ShopCart.h"

#define RESET "\033[0m"          // Define a cor de texto para padrão
#define RED "\033[31m"           // Define a cor de texto para vermelho
#define GREEN "\033[32m"         // Define a cor de texto para verde
#define BRIGHT_YELLOW "\033[93m" // Define a cor de texto amarelo brilhante

class Shop
{
    Stock product;
    // Criacao do Vector do Objeto ShopCart
    ShopCart cart[100];
    int sizeCart = 0;

public:
    Shop();
    void saveCart(string name, int quantity, double priceWoiva);
    int searchProduct(int id);
    void printShopCart();
    void removeProduct(int id);
    void addProductCart();
    void removeProductCart();
    void setCartQuantity();

private:
};

#endif