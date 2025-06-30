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
Product::Product(int id, string name, int quantity, double price)
{
    this->id = id;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}
// Gets
int Product::getId()
{
    return id;
}
string Product::getName() const
{
    return name;
}
int Product::getQuantity() const
{
    return quantity;
}
double Product::getPrice() const
{
    return price;
}
double Product::getSellPrice()
{
    return sellPrice = price * 1.30;
}
double Product::getIva()
{
    return iva = price * 0.23;
}
double Product::getTotal()
{
    return total = (sellPrice * 1.23) * quantity;
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
    double refreshSellPrice = getSellPrice();
    double refreshIva = getIva();
    double refreshTotal = getTotal();

    stringstream ss;
    ss << left << setw(5) << id
       << setw(20) << name
       << setw(10) << quantity
       << setw(10) << fixed << setprecision(2) << sellPrice
       << setw(10) << iva << setw(10) << total;
    return ss.str();
}