#include "Sales.h"

Sales::Sales()
{
}
int Sales::nextidSale = 1;
Sales::Sales(int receiptNumber, int idClient, vector<Product> cart, double total)
{
    this->idSale = nextidSale++;
    this->receiptNumber = receiptNumber;
    this->idClient = idClient;
    this->cart = cart;
}
int Sales::getsalesId()
{
    return idSale;
}
int Sales::getreceiptNumber()
{
    return receiptNumber;
}
int Sales::getidClient()
{
    return idClient;
}
double Sales::getsalesTotal()
{
    return total;
}
// toString
string Sales::toString()
{
    stringstream oss;
    oss << left << setw(10) << idSale
        << setw(15) << receiptNumber
        << setw(10) << idClient
        << setw(12) << fixed << setprecision(2) << total;

    // mostrar os produtos do carrinho:
    oss << "\nProdutos:\n";
    for (auto &prod : cart)
    {
        oss << "  - " << prod.getName()
            << " x" << prod.getQuantity()
            << " (" << fixed << setprecision(2) << prod.getPrice() << "€ cada)\n";
    }

    return oss.str();
}