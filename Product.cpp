#include "Product.h"
#include <sstream>

// Construtores
Product::Product()
{
}
int Product::nextIdProduct = 1;
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
    std::stringstream ss;
    ss << "ID: " << id
       << "\nName: " << name
       << "\nQuantity: " << quantity
       << "\nPrice WO/I: " << fixed << setprecision(2) << priceWoiva
       << endl;
    return ss.str();
}