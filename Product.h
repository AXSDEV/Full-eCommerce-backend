#ifndef PRODUCT_H
#define PRODUCT_H

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <conio.h>

using namespace std;
class Product
{
private:
    static int nextIdProduct;
    int id;
    string name;
    int quantity;
    double price;
    double sellPrice;
    double iva;
    double total;

public:
    // Construtores
    Product();
    Product(string name, int quantity, double price);
    Product(int id, string name, int quantity, double price);
    // Gets
    int getId();
    string getName();
    int getQuantity();
    double getPrice();
    double getSellPrice();
    double getIva();
    double getTotal();
    // Sets
    void setName();
    void setQuantity(int quantity);
    void setPrice(double price);
    // to string
    string tostring();
    string toStringCart();
};

#endif