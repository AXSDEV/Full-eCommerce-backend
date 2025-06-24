#ifndef SALES_H
#define SALES_H

#include "Product.h"
#include "Client.h"

class Sales
{
private:
    int idSale;
    int receiptNumber;
    int idClient;
    double total;
    static int nextidSale;

public:
    Sales();
    Sales(int receiptNumber, int idClient, Product cart, double total);
};

#endif