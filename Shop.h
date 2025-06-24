#ifndef SHOP_H
#define SHOP_H

#include "Client.h"
#include "Sales.h"
#include "Product.h"

#define RESET "\033[0m"          // Define a cor de texto para padrão
#define RED "\033[31m"           // Define a cor de texto para vermelho
#define GREEN "\033[32m"         // Define a cor de texto para verde
#define BRIGHT_YELLOW "\033[93m" // Define a cor de texto amarelo brilhante

class Shop
{
private:
    Sales salesReport[100];
    int sizeReport = 0;
    // Criacao do Vector do Objeto Receipt
    Product cart[100];
    int sizeCart = 0;
    // Criacao do Vetor do Objeto Product
    Product products[100];
    int sizeStock = 0;
    // Criacao do Vetor do Objeto Client
    Client list[100];
    int sizeClientList = 0;

public:
    Shop();
    // Products
    void saveProduct(string name, int quantity, double price);
    int searchStockProduct(int id);
    void printStock();
    void printProduct(int i);
    void removeProduct(int id);
    void addProductstock();
    void removeProductstock();
    void setProductPrice();
    void setProductQuantity();

    // Clients
    void saveClient(string name, string phone, string address);
    int searchClient(int id);
    void printClientList();
    void removeClient(int id);
    void removeFromclientlist();
    void addClient();
    void setClientPhone();
    void setClientAddress();

    // Sales
    void addProductInCart();
    void printCart();
    void removefromCart();
    void modifyqntCart();
    int cartSize();
    void clearCart();
    void checkout();
};

#endif