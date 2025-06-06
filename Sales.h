#ifndef SALES_H
#define SALES_H

#include "Product.h"
#include "Client.h"

class Sales
{
private:
    static int nextIdCart;
    int id;
    string name;
    int quantity;
    double price;

public:
    Sales();
    Sales(string name, int quantity, double price);

    //  Gets
    int getCartId();
    string getCartName();
    int getCartQuantity();
    double getCartPrice();
    // Sets
    void setCartName();
    void setCartQuantity(int quantity);
    void setCartPrice(double price);
    // to string
    string tostring();
};

#endif