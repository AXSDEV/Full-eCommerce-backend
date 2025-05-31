#include "Client.h"
#include "Product.h"
#include "Stock.h"
int main()
{
    // Preenchimento do Objeto
    Stock products;
    products.saveProduct(1, "Lapis", 20, 0.20);
    products.saveProduct(2, "Caneta", 20, 0.40);
    products.saveProduct(3, "Caderno", 20, 1.50);
    products.saveProduct(4, "Borracha", 15, 0.30);
    products.saveProduct(5, "Apontador", 10, 0.50);
    products.saveProduct(6, "Regua", 12, 0.80);
    products.saveProduct(7, "Marcador", 18, 1.20);
    products.saveProduct(8, "Bloco Notas", 8, 2.00);
    products.saveProduct(9, "Estojo", 5, 3.50);
    products.saveProduct(10, "Mochila", 3, 12.00);

    products.printStock(); // Impressao do Stock
}