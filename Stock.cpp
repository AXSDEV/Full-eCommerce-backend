#include "Stock.h"

Stock::Stock()
{
    // Stock
    saveProduct("Lapis", 20, 0.20);
    saveProduct("Caneta", 20, 0.40);
    saveProduct("Caderno", 20, 1.50);
    saveProduct("Borracha", 15, 0.30);
    saveProduct("Apontador", 10, 0.50);
    saveProduct("Regua", 12, 0.80);
    saveProduct("Marcador", 18, 1.20);
    saveProduct("Bloco Notas", 8, 2.00);
    saveProduct("Estojo", 5, 3.50);
    saveProduct("Mochila", 3, 12.00);
}

void Stock::saveProduct(string name, int quantity, double priceWoiva)
{
    if (sizeStock < 100)
    {
        Product product(name, quantity, priceWoiva);
        products[sizeStock] = product;
        sizeStock++;
    }
    else
    {
        cout << "Stock encontrasse cheio ! " << endl;
    }
}

void Stock::addProductstock()
{
    if (sizeStock < 100)
    {
        string nameProduct;
        int quantityProduct;
        double priceProduct;
        printStock();
        cout << endl
             << endl;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nameProduct); // Maneira de conseguir ler tudo ate ao enter inves de ate ao espaco
        cout << "Quantidade: ";
        cin >> quantityProduct;
        cout << "Preco: ";
        cin >> priceProduct;

        saveProduct(nameProduct, quantityProduct, priceProduct);
    }
    else
    {
        cout << "Stock encontrasse cheio ! " << endl;
    }
}

int Stock::searchProduct(int id)
{
    for (int i = 0; i < sizeStock; i++)
    {
        if (products[i].getId() == id)
        {
            return i;
        }
    }
    return -1;
}

void Stock::printStock()
{
    cout << left << setw(5) << "ID"
         << setw(20) << "Nome"
         << setw(10) << "Qnt"
         << setw(10) << "Preco" << endl;
    for (int i = 0; i < sizeStock; i++)
    {
        cout << endl
             << products[i].tostring();
    }
}
void Stock::printProduct(int i)
{
    if (i > 0 && i < sizeStock)
    {
        cout << endl
             << products[i].tostring();
    }
    else
    {
        cout << endl
             << "Nao existe esse Produto";
    }
}
void Stock::removeProduct(int id)
{
    int position = searchProduct(id);
    for (int i = position; i < sizeStock; i++)
    {
        products[i] = products[i + 1];
    }
    sizeStock--;
}
void Stock::removeProductstock()
{
    int idRemoveProduct;
    printStock();
    cout << endl
         << endl;

    cout << "ID do Artigo a Apagar: ";
    cin >> idRemoveProduct;
    removeProduct(idRemoveProduct);
}
void Stock::setProductPrice()
{
    int idProdAlt;
    double novoPreco;
    printStock();
    cout << endl
         << endl;
    cout << "ID do Produto: ";
    cin >> idProdAlt;
    int index = searchProduct(idProdAlt);
    if (index == -1)
    {
        cout << "Produto nao encontrado!" << endl;
        return;
    }
    cout << "Novo Preco: ";
    cin >> novoPreco;
    products[index].setPriceWoiva(novoPreco);
}
void Stock::setProductQuantity()
{
    int idProdAlt;
    double newQuantity;
    printStock();
    cout << endl
         << endl;
    cout << "ID do Produto: ";
    cin >> idProdAlt;
    int index = searchProduct(idProdAlt);
    if (index == -1)
    {
        cout << "Produto nao encontrado!" << endl;
        return;
    }
    cout << "Nova Quantidade: ";
    cin >> newQuantity;
    products[index].setQuantity(newQuantity);
}
