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
    double price;

public:
    // Construtores
    Product();
    Product(string name, int quantity, double price);
    // Gets
    int getId();
    string getName();
    int getQuantity();
    double getPrice();
    // Sets
    void setName();
    void setQuantity(int quantity);
    void setPrice(double price);
    // to string
    string tostring();
};

#endif