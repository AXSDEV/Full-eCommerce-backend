#ifndef SHOP_H
#define SHOP_H

#include "Client.h"
#include "Sales.h"
#include "Product.h"

#define RESET "\033[0m"          // Define a cor de texto para padrão
#define RED "\033[31m"           // Define a cor de texto para vermelho
#define GREEN "\033[32m"         // Define a cor de texto para verde
#define BRIGHT_YELLOW "\033[93m" // Define a cor de texto amarelo brilhante
#define BRIGHT_GREEN "\e[0;92m"  // Define a cor verde brilhante
class Shop
{
private:
    Sales salesList[100];
    int sizeList = 0;
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
    void setclientName();

    // Buying
    void addProductInCart();
    void printCart();
    void removefromCart();
    void modifyqntCart();
    int cartSize();
    void clearCart();
    void checkout();

    // Sales
    void addtosalesList(int receiptnumber, int idClient, vector<Product> cart, double total);
    void printSales();
    void printTotalStock();
    void printBestClient();
    void printbestsellProduct();
    void printBestSeller();
    void printWorstProduct();
    void printBestProductProfit();
    void salesSearch();

    // Validations
    int intInputValidation(const string &prompt);
    char charInputValidation(const string &prompt);
    int doubleInputValidation(const string &prompt);
    string toLower(string name);
};

#endif