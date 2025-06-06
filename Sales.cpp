#include "Sales.h"

Sales::Sales()
{
}

int Sales::nextIdCart = 1;
Sales::Sales(string name, int quantity, double price)
{
    this->id = nextIdCart++;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}
// Gets
int Sales::getCartId()
{
    return id;
}
string Sales::getCartName()
{
    return name;
}
int Sales::getCartQuantity()
{
    return quantity;
}
double Sales::getCartPrice()
{
    return price;
}

// Sets
void Sales::setCartName()
{
    this->name = name;
}
void Sales::setCartQuantity(int quantity)
{
    this->quantity = quantity;
}
void Sales::setCartPrice(double price)
{
    this->price = price;
}

// tostring ou Impressao
string Sales::tostring()
{
    std::stringstream ss;
    ss << left << setw(5) << id
       << setw(20) << name
       << setw(10) << quantity
       << setw(10) << fixed << setprecision(2) << price;
    return ss.str();
}