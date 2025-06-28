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
        cout << RED << "Stock encontrasse cheio ! " << RESET << endl;
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
        cout << RED << "Stock encontrasse cheio ! " << RESET << endl;
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
    cout << "--------------------------------------------\n";
    cout << "| ID  | Nome           | Qtd | Preco Custo |\n";
    cout << "--------------------------------------------\n";
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
             << RED << "Nao existe esse Produto" << RESET;
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
    cout << RED << "Artigo Removido." << RESET;
    Sleep(2000);
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
        cout << RED << "Produto nao encontrado!" << RESET << endl;
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
        cout << RED << "Produto nao encontrado!" << RESET << endl;
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
        cout << endl
             << endl;
        cout << "Nome: ";
        getline(cin, nameClient); // Maneira de conseguir ler tudo ate ao enter inves de ate ao espaco
        cout << "Telemovel: ";
        getline(cin, cellClient);
        cout << "Morada: ";
        getline(cin, addressClient);

        saveClient(nameClient, cellClient, addressClient);
    }
    else
    {
        cout << RED << "A Lista encontrasse cheia ! " << RESET << endl;
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
    cout << RED << "Cliente apagado da lista." << RESET;
    Sleep(2000);
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
        cout << RED << "Cliente nao encontrado!" << RESET << endl;
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
        cout << RED << "Cliente nao encontrado!" << RESET << endl;
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
                cout << GREEN << "Produto adicionado ao carrinho!" << RESET << endl;
            }
            else
            {
                cout << endl
                     << RED << "Quantidade Insuficiente em stock! " << RESET << endl;
                Sleep(3000);
                continue;
            }
            continueToAdd = charInputValidation("\nDeseja adicionar mais produtos ao carrinho? (S/N): ");
        }
        else
        {
            cout << RED << "Produto nao encontrado na loja. Tente novamente." << RESET;
            Sleep(2000);
            continue;
        }
    }
}

void Shop::printCart()
{
    if (sizeCart > 0)
    {
        cout << BRIGHT_YELLOW << "=== Carrinho de Compras ===\n"
             << RESET;
        cout << "----------------------------------------------------------------\n";
        cout << "| ID  | Nome           | Qtd | Preco Unit. |  IVA  | Subtotal   |\n";
        cout << "----------------------------------------------------------------\n";
        for (int i = 0; i < sizeCart; i++)
        {

            cout << cart[i].toStringCart() << endl;
        }
    }
}

void Shop::removefromCart()
{
    printCart();
    int idRemove;
    cout << "Insira o ID do produto a adicionar ao carrinho: ";
    cin >> idRemove;
    // Index para ir buscar a posicao para depois apagar puxando o seguinte para a posicao escolhida
    int index = -1;
    for (int i = 0; i < sizeCart; i++)
    {
        if (idRemove == cart[i].getId())
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        // Apaga tipo matriz puxa o da frente para tras e decrementa
        for (int i = index; i < sizeCart - 1; i++)
        {
            cart[i] = cart[i + 1];
        }
        sizeCart--;
        cout << RED << "Produto removido do carrinho. " << RESET << endl;
    }
    else
    {
        cout << RED << "Nao existe um produto com esse ID no carrinho. " << RESET << endl;
    }
}
void Shop::modifyqntCart()
{
    printCart(); // Mostra o carrinho atual ao utilizador

    int idModify;
    int newcartQnt;

    cout << endl
         << endl;
    cout << "ID do Produto a modificar a quantidade: ";
    cin >> idModify;

    int index = -1; // Variavel para guardar o indice do produto no carrinho

    // Procura o produto no carrinho pelo ID
    for (int i = 0; i < sizeCart; i++)
    {
        if (cart[i].getId() == idModify)
        {
            index = i; // Guarda o indice se encontrar
            break;     // Sai do ciclo assim que encontra
        }
    }

    if (index != -1) // Se encontrou o produto no carrinho
    {
        int oldQnt = cart[index].getQuantity(); // Guarda a quantidade antiga no carrinho

        // Procura o produto no stock pelo mesmo ID
        int stockIndex = searchStockProduct(idModify);
        if (stockIndex == -1)
        {
            cout << RED << "Produto nao encontrado no stock!" << RESET << endl;
            return; // Sai da funcao se nao encontrar no stock
        }

        cout << "Quantidade atual no carrinho: " << oldQnt << endl;
        cout << "Nova quantidade: ";
        cin >> newcartQnt; // Le a nova quantidade desejada

        if (newcartQnt <= 0)
        {
            cout << RED << "Quantidade invalida!" << RESET << endl;
            return; // Sai se a quantidade for invalida
        }

        // Calcula o stock disponivel (stock atual s+ o que ja estava no carrinho)
        int availableStock = products[stockIndex].getQuantity() + oldQnt;

        if (newcartQnt > availableStock)
        {
            cout << RED << "Quantidade insuficiente em stock!" << RESET << endl;
            return; // Sai se nao houver stock suficiente
        }

        // Atualiza o stock do produto (stock disponivel - nova quantidade no carrinho)
        products[stockIndex].setQuantity(availableStock - newcartQnt);

        // Atualiza a quantidade do produto no carrinho
        cart[index].setQuantity(newcartQnt);

        cout << GREEN << "Quantidade modificada com sucesso!" << RESET << endl;
    }
    else // Se nao encontrou o produto no carrinho
    {
        cout << RED << "Produto nao encontrado no carrinho!" << RESET << endl;
    }
}

int Shop::cartSize()
{
    return sizeCart;
}

void Shop::clearCart()
{
    if (cartSize() > 0)
    {
        char confirmation;
        confirmation = charInputValidation("Tem certeza que deseja cancelar a comprar e esvaziar o carrinho? (S/N): ");

        if (confirmation == 's')
        {
            for (int i = 0; i < sizeCart; i++)
            {
                products[i].setQuantity(products[i].getQuantity() + cart[i].getQuantity());
            }

            sizeCart = 0;
            cout << endl
                 << RED << "Compra cancelada com sucesso e carrinho vazio!" << RESET;
            Sleep(2000);
        }
    }
}

void Shop::checkout()
{
    char isClient;
    int idClientSale;
    double payment;
    double total;
    int receiptNumber = 0;
    int counter = 0;
    do
    {
        isClient = charInputValidation("Ja e nosso Cliente? (S/N) (0 para voltar atras!): ");

        if (isClient == '0')
            break;

        if (isClient == 's')
        {
            int idSearchClient;
            printClientList();
            cout << endl
                 << "Insira o seu ID de Cliente: ";
            cin >> idSearchClient;
            cin.ignore(1000, '\n');
            cout << endl;
            idClientSale = searchClient(idSearchClient);
            break;
        }
        else if (isClient == 'n')
        {
            cout << BRIGHT_YELLOW << "--- Novo Cliente ---" << RESET;
            addClient();
            idClientSale = sizeClientList - 1;
            break;
        }
    } while (isClient != '0');

    printCart();
    do
    {
        double subtotal = 0;
        for (int i = 0; i < sizeCart; i++)
        {
            subtotal += cart[i].getTotal();
        }

        if (sizeCart == 0)
        {
            cout << RED << "Carrinho encontra-se vazio." << RESET << endl;
            return;
        }

        cout << "\nTotal a pagar: " << fixed << setprecision(2) << subtotal << " euros\n";

        payment = numberInputValidation("Valor Entregue: (0 para cancelar): ");

        if (payment == 0)
            return;

        if (payment >= subtotal)
        {
            receiptNumber++;
            system("CLS");
            time_t now = time(0);
            tm localTime;
            localtime_s(&localTime, &now);
            cout << "====================== TALAO DE COMPRA ======================\n"
                 << "Data: " << localTime.tm_mday << "/" << localTime.tm_mon + 1 << "/" << localTime.tm_year + 1900 << "\n"
                 << "Hora: "
                 << localTime.tm_hour << ":" << localTime.tm_min << ":" << localTime.tm_sec << endl
                 << "Fatura n: " << receiptNumber << " | Cliente n: " << list[idClientSale].getId() << endl
                 << "-------------------------------------------------------------\n"
                 << setw(6) << "" << setw(15) << "Produto" << setw(10) << "Qtd" << setw(15) << "Preco S/IVA" << setw(10) << "IVA" << setw(10) << "Total" << endl
                 << "-------------------------------------------------------------\n";

            for (int i = 0; i < sizeCart; i++)
            {
                counter++;
                cout << setw(6) << counter << setw(15) << cart[i].getName()
                     << setw(10) << cart[i].getQuantity()
                     << setw(15) << fixed << setprecision(2) << cart[i].getPrice()
                     << setw(10) << fixed << setprecision(2) << cart[i].getIva()
                     << setw(10) << fixed << setprecision(2) << cart[i].getTotal() << endl;
            }
            cout << "-------------------------------------------------------------\n";
            cout << "Total: " << subtotal;
            cout << endl
                 << "Valor Entregue: " << payment;
            cout << endl
                 << "Troco: " << (payment - subtotal) << endl;
            cout << "-------------------------------------------------------------\n";
            addtosalesList(receiptNumber, list[idClientSale].getId(), vector<Product>(cart, cart + sizeCart), subtotal);
            sizeCart = 0;
            cout << "Pressione ENTER para voltar ao Menu.";
            cin.get();
            break;
        }
        else
        {
            cout << RED << "Valor entregue insuficiente." << RESET << endl;
        }
    } while (payment != 0);
}

void Shop::addtosalesList(int receiptnumber, int idClient, vector<Product> cart, double total)
{
    // TODO: nao esta a imprimir o carrinho Bernardo.
    int pos = sizeList % 100; // Garante que nunca passa do índice 99
    Sales sale(receiptnumber, idClient, cart, total);
    salesList[pos] = sale;
    sizeList++; // Continua a incrementar para garantir o ciclo
    cout << BRIGHT_YELLOW << "Venda adicionada a lista de vendas!" << RESET << endl;
}

void Shop::printSales()
{
    cout << "---------------------------------------------\n";
    cout << "| ID Venda | ID Fatura | ID Cliente | Total |\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < sizeList; i++)
    {
        cout << salesList[i].toString() << endl;
        cout << "Pressione ENTER para voltar ao Menu.";
        cin.get();
        break;
    }
}

void Shop::printTotalSales()
{
    int total = 0;
    printStock();
    for (int i = 0; i < sizeStock; i++)
    {
        total = total + products[i].getQuantity();
    }
    cout << endl
         << BRIGHT_YELLOW
         << "Stock Total = " << total << " produtos.\n"
         << RESET;
    cout << endl
         << "Pressione ENTER para voltar ao menu.";
    cin.ignore();
    cin.get();
}

int Shop::numberInputValidation(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(1000, '\n');
            return value;
        }
        else
        {
            cout << RED << "Por favor introduza um numero valido. Tente novamente.\n"
                 << RESET;
            cin.clear();
            cin.ignore(1000, '\n');
            Sleep(1000);
        }
    }
}

char Shop::charInputValidation(const string &prompt)
{
    char answer;
    while (true)
    {
        cout << prompt;
        cin >> answer;
        cin.ignore(1000, '\n');
        answer = tolower(answer);
        if (answer == 's' || answer == 'n' || answer == '0')
        {
            return answer;
        }
        else
        {
            cout << RED << "Por favor introduza 'S' ou 'N'\n"
                 << RESET;
            Sleep(2000);
        }
    }
}
