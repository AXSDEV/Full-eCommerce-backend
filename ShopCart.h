#ifndef SHOPCART_H
#define SHOPCART_H
#include "Product.h"

class ShopCart
{
private:
    static int nextIdCart;
    int id;
    string name;
    int quantity;
    double priceWoiva;

public:
    ShopCart();
    ShopCart(string name, int quantity, double priceWoiva);

    //  Gets
    int getCartId();
    string getCartName();
    int getCartQuantity();
    double getCartPriceWoiva();
    // Sets
    void setCartName();
    void setCartQuantity(int quantity);
    void setCartPriceWoiva(double price);
    // to string
    string tostring();
};

#endif