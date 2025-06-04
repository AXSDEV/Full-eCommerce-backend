#include "ShopCart.h"

ShopCart::ShopCart()
{
}
int ShopCart::nextIdCart = 1;
ShopCart::ShopCart(string name, int quantity, double priceWoiva)
{
    this->id = nextIdCart++;
    this->name = name;
    this->quantity = quantity;
    this->priceWoiva = priceWoiva;
}
// Gets
int ShopCart::getCartId()
{
    return id;
}
string ShopCart::getCartName()
{
    return name;
}
int ShopCart::getCartQuantity()
{
    return quantity;
}
double ShopCart::getCartPriceWoiva()
{
    return priceWoiva;
}

// Sets
void ShopCart::setCartName()
{
    this->name = name;
}
void ShopCart::setCartQuantity(int quantity)
{
    this->quantity = quantity;
}
void ShopCart::setCartPriceWoiva(double price)
{
    this->priceWoiva = price;
}

// tostring ou Impressao
string ShopCart::tostring()
{
    std::stringstream ss;
    ss << left << setw(5) << id
       << setw(20) << name
       << setw(10) << quantity
       << setw(10) << fixed << setprecision(2) << priceWoiva;
    return ss.str();
}