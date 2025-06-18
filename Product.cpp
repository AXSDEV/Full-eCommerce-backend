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
    this->sellPrice = price * 1.30;
    this->iva = sellPrice * 0.23;
    this->total = quantity * (sellPrice + iva);
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
double Product::getSellPrice()
{
    return sellPrice;
}
double Product::getIva()
{
    return iva;
}
double Product::getTotal()
{
    return total;
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
    stringstream ss;
    ss << left << setw(5) << id
       << setw(20) << name
       << setw(10) << quantity
       << setw(10) << fixed << setprecision(2) << price;
    return ss.str();
}

string Product::toStringCart()
{
    stringstream ss;
    ss << left << setw(5) << id
       << setw(20) << name
       << setw(10) << quantity
       << setw(10) << fixed << setprecision(2) << sellPrice
       << setw(10) << iva << setw(10) << total;
    return ss.str();
}