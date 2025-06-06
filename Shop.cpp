#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#include "Shop.h"
#include "Sales.h"
#include "Menu.h"

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
    saveClient("Leandro", "999PfNaoincomode", "Debaixo da Ponte, 42");
}

// Products
void Shop::saveProduct(string name, int quantity, double price)
{
    if (sizeStock < 100)
    {
        Product product(name, quantity, price);
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

int Shop::searchStockProduct(int id)
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
void Shop::removeProduct(int id)
{
    int position = searchStockProduct(id);
    for (int i = position; i < sizeStock; i++)
    {
        products[i] = products[i + 1];
    }
    sizeStock--;
}
void Shop::removeProductstock()
{
    int idRemoveProduct;
    printStock();
    cout << endl
         << endl;

    cout << "ID do Artigo a Apagar: ";
    cin >> idRemoveProduct;
    removeProduct(idRemoveProduct);
}
void Shop::setProductPrice()
{
    int idProdAlt;
    double novoPreco;
    printStock();
    cout << endl
         << endl;
    cout << "ID do Produto: ";
    cin >> idProdAlt;
    int index = searchStockProduct(idProdAlt);
    if (index == -1)
    {
        cout << "Produto nao encontrado!" << endl;
        return;
    }
    cout << "Novo Preco: ";
    cin >> novoPreco;
    products[index].setPrice(novoPreco);
}
void Shop::setProductQuantity()
{
    int idProdAlt;
    double newQuantity;
    printStock();
    cout << endl
         << endl;
    cout << "ID do Produto: ";
    cin >> idProdAlt;
    int index = searchStockProduct(idProdAlt);
    if (index == -1)
    {
        cout << "Produto nao encontrado!" << endl;
        return;
    }
    cout << "Nova Quantidade: ";
    cin >> newQuantity;
    products[index].setQuantity(newQuantity);
}

// Clients
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
    if (sizeClientList < 100)
    {
        string nameClient;
        string cellClient;
        string addressClient;
        printClientList();
        cout << endl
             << endl;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nameClient); // Maneira de conseguir ler tudo ate ao enter inves de ate ao espaco
        cout << "Telemovel: ";
        getline(cin, cellClient);
        cout << "Morada: ";
        getline(cin, addressClient);

        saveClient(nameClient, cellClient, addressClient);
    }
    else
    {
        cout << "Stock encontrasse cheio ! " << endl;
    }
}

int Shop::searchClient(int id)
{
    for (int i = 0; i < sizeClientList; i++)
    {
        if (list[i].getId() == id)
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

void Shop::removeClient(int id)
{
    int pos = searchClient(id); // pos = position
    for (int i = pos; i < sizeClientList; i++)
    {
        list[i] = list[i + 1];
    }
    sizeClientList--;
}
void Shop::removeFromclientlist()
{
    int IdRemoveclient;
    printClientList();
    cout << endl
         << endl;

    cout << "ID do Cliente a Apagar: ";
    cin >> IdRemoveclient;
    removeClient(IdRemoveclient);
}

void Shop::setClientPhone()
{
    int idProdAlt;
    string newPhone;
    printClientList();
    cout << endl
         << endl;
    cout << "ID do Cliente: ";
    cin >> idProdAlt;
    int index = searchClient(idProdAlt);
    if (index == -1)
    {
        cout << "Cliente nao encontrado!" << endl;
        return;
    }
    cout << "Novo Telefone: ";
    cin >> newPhone;
    list[index].setPhone(newPhone);
}
void Shop::setClientAddress()
{
    int idProdAlt;
    string newAddress;
    printClientList();
    cout << endl
         << endl;
    cout << "ID do Cliente: ";
    cin >> idProdAlt;
    int index = searchClient(idProdAlt);
    if (index == -1)
    {
        cout << "Cliente nao encontrado!" << endl;
        return;
    }
    cout << "Nova Morada: ";
    cin.ignore();
    getline(cin, newAddress);
    list[index].setAddress(newAddress);
}

// Sales

void Shop::addProductInCart()
{
    char continueToAdd = 's';

    while (continueToAdd == 's')
    {
        system("CLS");
        if (sizeCart >= 100)
        {
            cout << RED << "O carrinho esta cheio!" << RESET << endl;
            break;
        }
        int idProdAdd;
        int quantityAdd;

        printStock();
        cout << endl
             << endl;
        cout << "Insira o ID do produto a adicionar ao carrinho. (0 para cancelar): ";
        cin >> idProdAdd;

        if (idProdAdd == 0)
        {
            cout << BRIGHT_YELLOW << "Operacao Cancelada." << RESET << endl;
            break;
        }

        int index = searchStockProduct(idProdAdd);

        if (index != -1)
        {
            Product productInStock = products[index];
            cout << endl
                 << "Produto: " << productInStock.getName() << endl
                 << "Disponivel em stock: " << productInStock.getQuantity() << "." << endl;
            cout << endl
                 << "Insira a quantidade de " << productInStock.getName() << " a adicionar ao carrinho: ";
            cin >> quantityAdd;

            if (quantityAdd <= 0)
            {
                cout << RED << "Quantidade a adicionar deve ser um numero positivo." << RESET << endl;
                continue;
            }

            if (quantityAdd <= productInStock.getQuantity())
            {

                productInStock.setQuantity(quantityAdd);
                cart[sizeCart] = productInStock;
                sizeCart++;
                products[index].setQuantity(products[index].getQuantity() - quantityAdd);
                cout << "Produto adicionado ao carrinho!" << endl;
            }
            else
            {
                cout << endl
                     << RED << "Quantidade Insuficiente em stock! " << RESET << endl;
                Sleep(3000);
                continue;
            }
            cout << "\nDeseja adicionar mais produtos ao carrinho? (S/N): ";
            cin >> continueToAdd;
        }
    }
}

void Shop::printCart()
{
    if (sizeCart > 0)
    {
        cout << "=== Carrinho de Compras ===\n";
        cout << "----------------------------------------------------------------\n";
        cout << "| ID  | Nome           | Qtd | Preco Unit. |  IVA  | Subtotal   |\n";
        cout << "----------------------------------------------------------------\n";
        for (int i = 0; i < sizeCart; i++)
        {
            cout << cart[i].tostring();
        }
    }
}

void Shop::removefromCart()
{
}