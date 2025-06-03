#include "Shop.h"
#include "Product.h"
#include "Client.h"
Shop::Shop()
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

    // Lista de Clientes
    saveClient("Carlos", "911223344", "Rua do Sol, 77");
    saveClient("Sofia", "932109876", "Largo da Igreja, 5");
    saveClient("Diogo", "967890123", "Avenida dos Descobrimentos, 10");
    saveClient("Rita", "919876543", "Praca da Republica, 1");
    saveClient("Tiago", "934567890", "Rua das Flores, 42");
    saveClient("Leandro", "999PorfavorNincomode", "Debaixo da Ponte, 42");
}
// Shop::Product
void Shop::saveProduct(string name, int quantity, double priceWoiva)
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

void Shop::addProductstock()
{
    if (sizeStock < 100)
    {
        string nameProduct;
        int quantityProduct;
        double priceProduct;
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

int Shop::searchProduct(string name)
{
    for (int i = 0; i < sizeStock; i++)
    {
        if (name == products[i].getName())
        {
            return i;
        }
    }
    return -1;
}
void Shop::printStock()
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
void Shop::printProduct(int i)
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
void Shop::removeProduct(string name)
{
    int position = searchProduct(name);
    for (int i = position; i < sizeStock; i++)
    {
        products[i] = products[i + 1];
    }
    sizeStock--;
}
void Shop::removeProductstock()
{
    string nameRemoveprod;
    printStock();
    cout << endl
         << endl;

    cout << "Nome do Artigo a Apagar: ";
    cin.ignore();
    getline(cin, nameRemoveprod);
    removeProduct(nameRemoveprod);
}

// Shop::Client
void Shop::saveClient(string name, string phone, string address)
{
    if (sizeClientList < 100)
    {
        Client client(name, phone, address);
        list[sizeClientList] = client;
        sizeClientList++;
    }
}
void Shop::addClient()
{
    if (sizeStock < 100)
    {
        string nameClient;
        string cellClient;
        string addressClient;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nameClient); // Maneira de conseguir ler tudo ate ao enter inves de ate ao espaco
        cout << "CellPhoneNumber: ";
        getline(cin, cellClient);
        cout << "Address: ";
        getline(cin, addressClient);

        saveClient(nameClient, cellClient, addressClient);
    }
    else
    {
        cout << "Stock encontrasse cheio ! " << endl;
    }
}

int Shop::searchClient(string name)
{
    for (int i = 0; i < sizeClientList; i++)
    {
        if (name == list[i].getName())
        {
            return i;
        }
    }
    return -1;
}

void Shop::printClientList()
{
    cout << left << setw(5) << "ID"
         << setw(20) << "Nome"
         << setw(30) << "Telemovel"
         << setw(30) << "Morada" << endl;
    for (int i = 0; i < sizeClientList; i++)
    {
        cout << endl
             << list[i].toString();
    }
}

void Shop::removeClient(string name)
{
    int pos = searchClient(name); // pos = position
    for (int i = pos; i < sizeClientList; i++)
    {
        list[i] = list[i + 1];
    }
    sizeClientList--;
}
void Shop::removeFromclientlist()
{
    string nameRemoveclient;
    printClientList();
    cout << endl
         << endl;

    cout << "Nome do Cliente a Apagar: ";
    cin.ignore();
    getline(cin, nameRemoveclient);
    removeClient(nameRemoveclient);
}
