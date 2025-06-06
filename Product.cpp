#include "Product.h"

// Construtores
Product::Product()
{
}
int Product::nextIdProduct = 1;
Product::Product(string name, int quantity, double price)
{
    this->id = nextIdProduct++;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}
// Gets
int Product::getId()
{
    return id;
}
string Product::getName()
{
    return name;
}
int Product::getQuantity()
{
    return quantity;
}
double Product::getPrice()
{
    return price;
}

// Sets
void Product::setName()
{
    this->name = name;
}
void Product::setQuantity(int quantity)
{
    this->quantity = quantity;
}
void Product::setPrice(double price)
{
    this->price = price;
}

// tostring ou Impressao
string Product::tostring()
{
    std::stringstream ss;
    ss << left << setw(5) << id
       << setw(20) << name
       << setw(10) << quantity
       << setw(10) << fixed << setprecision(2) << price;
    return ss.str();
}