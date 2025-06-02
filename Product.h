#ifndef PRODUCT_H
#define PRODUCT_H

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;
class Product
{
private:
    static int nextIdProduct;
    int id;
    string name;
    int quantity;
    double priceWoiva;

public:
    // Construtores
    Product();
    Product(string name, int quantity, double priceWoiva);
    // Gets
    int getId();
    string getName();
    int getQuantity();
    double getPriceWoiva();
    // Sets
    void setName();
    void setQuantity();
    void setPriceWoiva();
    // to string
    string tostring();
};

#endif