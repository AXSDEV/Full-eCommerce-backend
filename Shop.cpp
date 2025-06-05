#include "Shop.h"
#include "Stock.h"
#include "ClientList.h"
#include "ShopCart.h"
Shop::Shop()
{
}
void Shop::saveCart(string name, int quantity, double priceWoiva)
{
    if (sizeCart < 100)
    {
        ShopCart cartobj(name, quantity, priceWoiva);
        cart[sizeCart] = cartobj;
        sizeCart++;
    }
    else
    {
        cout << "Carrinho encontrasse cheio ! " << endl;
    }
}
void Shop::addProductCart()
{
    if (sizeCart < 100)
    {
        int idProdAdd;
        product.printStock();
        cout << endl
             << endl;
        cout << "ID do Produto a adicionar: ";
        cin >> idProdAdd;

        int idx = product.searchProduct(idProdAdd);
        if (idx != -1)
        {
            Product prod = product.products[idx];
            int quantidade;
            cout << "Quantidade a adicionar: ";
            cin >> quantidade;
            // Adicionar ao carrinho
            ShopCart cartobj(prod.getName(), quantidade, prod.getPriceWoiva());
            cart[sizeCart] = cartobj;
            sizeCart++;
            // TODO atualizar stock
            cout << "Produto adicionado ao carrinho!";
        }
        else
        {
            cout << "Produto nao encontrado !";
        }
    }
    else
    {
        cout << "Carrinho encontrasse cheio ! " << endl;
    }
}