#include "Product.h"

// Construtores
Product::Product()
{
}
int Product::nextIdProduct = 0;
Product::Product(int id, string name, int quantity, double priceWoiva)
{
    this->id = nextIdProduct++;
    this->name = name;
    this->quantity = quantity;
    this->priceWoiva = priceWoiva;
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
double Product::getPriceWoiva()
{
    return priceWoiva;
}

// Sets
void Product::setName()
{
    this->name = name;
}
void Product::setQuantity()
{
    this->quantity = quantity;
}
void Product::setPriceWoiva()
{
    this->priceWoiva = priceWoiva;
}

// tostring ou Impressao
string Product::tostring()
{
    return "ID: \n" + to_string(id) + "Name: \n" + name + "Quantity: \n" + to_string(quantity) + "Price WO/I: \n" + to_string(priceWoiva);
}