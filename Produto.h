#ifndef PRODUTO_H
#define PRODUTO_H

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>

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
    Product(int id, string name, int quantity, double priceWoiva);
    // Gets
    int getId();
    string getName();
    int getQuantity();
    double getPriceWoiva();
    // Sets
    void setName();
    void setquantity();
    void setPriceWoiva();
    // to string
    string tostring();
};

#endif