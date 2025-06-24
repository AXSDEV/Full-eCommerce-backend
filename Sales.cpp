#include "Sales.h"

Sales::Sales()
{
}
Sales::Sales(int receiptNumber, int idClient, vector<Product> cart, double total)
{
    this->idSale = nextidSale++;
    this->receiptNumber = receiptNumber;
    this->idClient = idClient;
    this->cart = cart;
}
