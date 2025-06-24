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
    vector<Product> cart;

public:
    // Constructors
    Sales();
    Sales(int receiptNumber, int idClient, vector<Product> cart, double total);
    // Gets
    int getreceiptNumber();
    int getidClient();
    double getsalesTotal();
    int getsalesId();
    string toString();
};

#endif