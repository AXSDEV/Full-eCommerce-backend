#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#include "Shop.h"
#include "Sales.h"
#include "Menu.h"

Shop::Shop()
{
    // Stock
    saveProduct("Xadrez", 2000, 9.99);
    saveProduct("Catan", 2000, 35.00);
    saveProduct("Ticket To Ride", 2000, 49.99);
    saveProduct("Carcassonne", 1500, 27.99);
    saveProduct("Pandemic", 1000, 40.00);
    saveProduct("Monopolio", 1200, 21.95);
    saveProduct("UNO", 1800, 5.99);
    saveProduct("RISK", 800, 49.98);
    saveProduct("Mysterium", 1500, 35.00);
    saveProduct("Concept", 3000, 32.50);
    // Lista de Clientes
    saveClient("Carlos", "911223344", "Rua do Sol, 77");
    saveClient("Sofia", "932109876", "Largo da Igreja, 5");
    saveClient("Diogo", "967890123", "Avenida dos Descobrimentos, 10");
    saveClient("Rita", "919876543", "Praca da Republica, 1");
    saveClient("Tiago", "934567890", "Rua das Flores, 42");
    saveClient("Leandro", "993294921", "Debaixo da Ponte, 42");
    // Lista de Vendas  4 vendas de exemplo
    for (int i = 0; i < 8; i++)
    {
        vector<Product> carrinho;
        // Adiciona 2 produtos diferentes ao carrinho (ajusta conforme o teu stock)
        int numProdutosCarrinho = 1 + rand() % 7; // Entre 1 e 7 produtos por venda

        for (int j = 0; j < numProdutosCarrinho; j++)
        {
            int idxProduto = rand() % sizeStock; // Índice aleatório do produto
            Product p = products[idxProduto];
            int qnt = 1 + rand() % 5; // Quantidade aleatória entre 1 e 5
            p.setQuantity(qnt);
            carrinho.push_back(p);
        }
        int idCliente = list[i % sizeClientList].getId();
        double total = 0;
        for (const auto &prod : carrinho)
            total += prod.getPrice() * prod.getQuantity();

        addtosalesList(1 + i, idCliente, carrinho, total);
    }
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
        Sleep(2000);
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
        getline(cin, nameProduct); // Maneira de conseguir ler tudo ate ao enter inves de ate ao espaco
        quantityProduct = intInputValidation("Quantidade: ");
        priceProduct = doubleInputValidation("Preco: ");

        saveProduct(nameProduct, quantityProduct, priceProduct);
    }
    else
    {
        cout << RED << "Stock encontrasse cheio ! " << RESET << endl;
        Sleep(2000);
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
    cout << "=============================================\n";
    cout << "| ID  | Nome           | Qtd | Preco Custo  |\n";
    cout << "=============================================\n";
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
        Sleep(2000);
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

    idRemoveProduct = intInputValidation("ID do Artigo a Apagar: ");
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
    idProdAlt = intInputValidation("ID do Produto: ");
    int index = searchStockProduct(idProdAlt);
    if (index == -1)
    {
        cout << RED << "Produto nao encontrado!" << RESET << endl;
        Sleep(2000);
        return;
    }
    novoPreco = doubleInputValidation("Novo Preco: ");
    products[index]
        .setPrice(novoPreco);
}

void Shop::setProductQuantity()
{
    int idProdAlt;
    int newQuantity;
    printStock();
    cout << endl
         << endl;
    idProdAlt = intInputValidation("ID do Produto: ");
    int index = searchStockProduct(idProdAlt);
    if (index == -1)
    {
        cout << RED << "Produto nao encontrado!" << RESET << endl;
        Sleep(2000);
        return;
    }
    newQuantity = intInputValidation("Nova Quantidade: ");
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
        cout << RED << "A lista encontrasse cheia ! " << RESET << endl;
        Sleep(2000);
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
    cout << endl;
    cout << "============================================================================================\n";
    cout << setw(5) << "| ID " << setw(5) << "| Nome " << setw(20) << "| Telemovel " << setw(30) << "| Morada " << setw(30) << "|";
    cout << endl
         << "============================================================================================\n";
    for (int i = 0; i < sizeClientList; i++)
    {
        cout << endl
             << list[i].toString();
    }
    cout << endl
         << "============================================================================================\n";
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
    IdRemoveclient = intInputValidation("ID do Cliente a Apagar: ");
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
    idProdAlt = intInputValidation("ID do Cliente: ");
    int index = searchClient(idProdAlt);
    if (index == -1)
    {
        cout << RED << "Cliente nao encontrado!" << RESET << endl;
        Sleep(2000);
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
    idProdAlt = intInputValidation("ID do Cliente: ");
    int index = searchClient(idProdAlt);
    if (index == -1)
    {
        cout << RED << "Cliente nao encontrado!" << RESET << endl;
        Sleep(2000);
        return;
    }
    cout << "Nova Morada: ";
    cin.ignore();
    getline(cin, newAddress);
    list[index].setAddress(newAddress);
}

void Shop::setclientName()
{
    int idclientChange;
    string newName;
    printClientList();
    cout << endl
         << endl;
    idclientChange = intInputValidation("ID do Cliente: ");
    int index = searchClient(idclientChange);
    if (index == -1)
    {
        cout << RED << "Cliente nao encontrado!" << RESET << endl;
        Sleep(2000);
        return;
    }
    cout << "Novo Nome: ";
    getline(cin, newName);
    list[index].setName(newName);
    cout << GREEN << "Alteracoes Guardadas com Sucesso! ";
    Sleep(2000);
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
            Sleep(2000);
            break;
        }
        int idProdAdd;
        int quantityAdd;

        printStock();
        cout << endl
             << endl;
        idProdAdd = intInputValidation("Insira o ID do produto a adicionar ao carrinho. (0 para cancelar): ");
        if (idProdAdd == 0)
        {
            cout << RED << "Operacao Cancelada." << RESET << endl;
            Sleep(2000);
            break;
        }

        int index = searchStockProduct(idProdAdd);

        if (index != -1)
        {
            Product productInStock = products[index];
            cout << endl
                 << "Produto: " << productInStock.getName() << endl
                 << "Disponivel em stock: " << productInStock.getQuantity() << "." << endl;
            cout << endl;
            quantityAdd = intInputValidation("Insira a quantidade que deseja adicionar ao carrinho: ");

            if (quantityAdd <= 0)
            {
                cout << RED << "Quantidade a adicionar deve ser um numero positivo." << RESET << endl;
                Sleep(2000);
                continue;
            }

            if (quantityAdd <= productInStock.getQuantity())
            {
                productInStock.setQuantity(quantityAdd);
                cart[sizeCart] = productInStock;
                sizeCart++;
                products[index].setQuantity(products[index].getQuantity() - quantityAdd);
                cout << GREEN << "Produto adicionado ao carrinho!" << RESET << endl;
                Sleep(2000);
            }
            else
            {
                cout << endl
                     << RED << "Quantidade Insuficiente em stock! " << RESET << endl;
                Sleep(2000);
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
        cout << BRIGHT_YELLOW << "|====================| Carrinho de Compras |====================|\n"
             << RESET;
        cout << "=================================================================\n";
        cout << "| ID  | Nome           | Qtd | Preco Unit. |  IVA  | Subtotal   |\n";
        cout << "=================================================================\n";
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
    idRemove = intInputValidation("Insira o ID do produto a adicionar ao carrinho: ");
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
        Sleep(2000);
    }
    else
    {
        cout << RED << "Nao existe um produto com esse ID no carrinho. " << RESET << endl;
        Sleep(2000);
    }
}

void Shop::modifyqntCart()
{
    printCart(); // Mostra o carrinho atual ao utilizador

    int idModify;
    int newcartQnt;

    cout << endl
         << endl;
    idModify = intInputValidation("ID do Produto a modificar a quantidade: ");
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
            Sleep(2000);
            return; // Sai da funcao se nao encontrar no stock
        }

        cout << "Quantidade atual no carrinho: " << oldQnt << endl;
        newcartQnt = intInputValidation("Nova quantidade: ");
        if (newcartQnt <= 0)
        {
            cout << RED << "Quantidade invalida!" << RESET << endl;
            Sleep(2000);
            return; // Sai se a quantidade for invalida
        }

        // Calcula o stock disponivel (stock atual s+ o que ja estava no carrinho)
        int availableStock = products[stockIndex].getQuantity() + oldQnt;

        if (newcartQnt > availableStock)
        {
            cout << RED << "Quantidade insuficiente em stock!" << RESET << endl;
            Sleep(2000);
            return; // Sai se nao houver stock suficiente
        }

        // Atualiza o stock do produto (stock disponivel - nova quantidade no carrinho)
        products[stockIndex].setQuantity(availableStock - newcartQnt);

        // Atualiza a quantidade do produto no carrinho
        cart[index].setQuantity(newcartQnt);

        cout << GREEN << "Quantidade modificada com sucesso!" << RESET << endl;
        Sleep(2000);
    }
    else // Se nao encontrou o produto no carrinho
    {
        cout << RED << "Produto nao encontrado no carrinho!" << RESET << endl;
        Sleep(2000);
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
    int receiptNumber = 8;
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
            cout << endl;
            idSearchClient = intInputValidation("Insira o seu ID de Cliente: ");
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
            Sleep(2000);
            return;
        }

        cout << "\nTotal a pagar: " << fixed << setprecision(2) << subtotal << " euros\n";

        payment = intInputValidation("Valor Entregue: (0 para cancelar): ");

        if (payment == 0)
            return;

        if (payment >= subtotal)
        {
            srand(time(0));
            int sorteio = rand() % 10;
            bool compraGratis = (sorteio < 9);
            if (compraGratis)
            {

                cout << BRIGHT_GREEN << "Parabens! Ganhou o Sorteio, esta compra sera gratis!" << RESET;
                Sleep(3000);
                subtotal = 0;
                payment = subtotal;
            }
            const int largura_total = 60;
            receiptNumber++;
            system("CLS");
            cout << "\033[47m\033[30m";
            time_t now = time(0);
            tm localTime;
            localtime_s(&localTime, &now);
            cout << string(largura_total, ' ') << endl;

            string titulo_talao = "===================== TALAO DE COMPRA ======================";
            cout << left << setw(largura_total) << titulo_talao << endl;

            // Usar stringstream para construir a linha e depois setw para preencher
            stringstream ss_data_hora;
            ss_data_hora << "Data: " << localTime.tm_mday << "/" << localTime.tm_mon + 1 << "/" << localTime.tm_year + 1900;
            cout << left << setw(largura_total) << ss_data_hora.str() << endl;

            stringstream ss_hora_completa;
            ss_hora_completa << "Hora: " << setfill('0') << setw(2) << localTime.tm_hour << ":"
                             << setw(2) << localTime.tm_min << ":" << setw(2) << localTime.tm_sec;
            cout << left << setw(largura_total) << ss_hora_completa.str() << endl;
            cout << setfill(' '); // Resetar setfill para espaço

            stringstream ss_fatura_cliente;
            ss_fatura_cliente << "Fatura n: " << receiptNumber << " | Cliente n: " << list[idClientSale].getId();
            cout << left << setw(largura_total) << ss_fatura_cliente.str() << endl;

            cout << left << setw(largura_total) << "============================================================" << endl;
            // 6 + 12 + 8 + 10 + 8 + 16 = 60
            cout << left
                 << setw(6) << "" // Espaço inicial
                 << setw(12) << "Produto"
                 << setw(8) << "Qtd"
                 << setw(10) << "Pr.S/IVA"
                 << setw(14) << "IVA"
                 << setw(10) << "Total" << endl; // O último setw preenche o resto da linha

            cout << left << setw(largura_total) << "============================================================" << endl;

            int counter = 0;
            for (int i = 0; i < sizeCart; i++)
            {
                counter++;
                stringstream ss_item;
                ss_item << counter
                        << setw(12) << cart[i].getName()
                        << setw(8) << cart[i].getQuantity()
                        << setw(10) << fixed << setprecision(2) << cart[i].getPrice()
                        << setw(8) << fixed << setprecision(2) << cart[i].getIva()
                        << setw(16) << fixed << setprecision(2) << cart[i].getTotal();
                cout << left << setw(largura_total) << ss_item.str() << endl;
            }

            cout << left << setw(largura_total) << "============================================================" << endl;

            stringstream ss_total;
            ss_total << "Total: " << fixed << setprecision(2) << subtotal;
            cout << left << setw(largura_total) << ss_total.str() << endl;

            stringstream ss_valor_entregue;
            ss_valor_entregue << "Valor Entregue: " << fixed << setprecision(2) << payment;
            cout << left << setw(largura_total) << ss_valor_entregue.str() << endl;

            stringstream ss_troco;
            ss_troco << "Troco: " << fixed << setprecision(2) << (payment - subtotal);
            cout << left << setw(largura_total) << ss_troco.str() << endl;

            cout << left << setw(largura_total) << "============================================================" << endl;
            cout << string(largura_total, ' ') << endl;
            // Resetar para cor padrão
            cout << "\033[0m";
            addtosalesList(receiptNumber, list[idClientSale].getId(), vector<Product>(cart, cart + sizeCart), subtotal);
            sizeCart = 0;
            cout << "Pressione ENTER para voltar ao Menu.";
            cin.get();
            break;
        }
        else
        {
            cout << RED << "Valor entregue insuficiente." << RESET << endl;
            Sleep(2000);
        }
    } while (payment != 0);
}

void Shop::addtosalesList(int receiptnumber, int idClient, vector<Product> cart, double total)
{
    int pos = sizeList % 100; // Garante que nunca passa do índice 99
    Sales sale(receiptnumber, idClient, cart, total);
    salesList[pos] = sale;
    sizeList++; // Continua a incrementar para garantir o ciclo
}

void Shop::printSales()
{
    int maxSales = (sizeList < 100) ? sizeList : 100;
    for (int i = 0; i < maxSales; i++)
    {
        cout << "=============================================\n";
        cout << "| ID Venda | ID Fatura | ID Cliente | Total |\n";
        cout << "=============================================\n";
        cout << salesList[i].toString() << endl;
        int idxCliente = searchClient(salesList[i].getidClient());
        if (idxCliente != -1)
            cout << "Nome do Cliente: " << list[idxCliente].getName() << endl
                 << endl;
    }
    cout << endl;
    cout << "Pressione ENTER para voltar ao Menu.";
    cin.get();
}

void Shop::printTotalStock()
{
    int total = 0;
    cout << "============================================\n";
    cout << "|               Stock Total                |\n";
    cout << "============================================\n";
    cout << endl;
    printStock();
    for (int i = 0; i < sizeStock; i++)
    {
        total = total + products[i].getQuantity();
    }
    cout << endl
         << endl
         << BRIGHT_YELLOW
         << "Stock Total = " << total << " produtos.\n"
         << RESET;
    cout << endl
         << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

void Shop::printBestClient()
{
    double totalSpent = 0;        // total gasto de todas as vendas de cada cliente
    double highestTotalSpent = 0; // total do cliente que mais gastou
    int idClient;
    int idBestClient; // id do cliente que mais gastou
    for (int i = 0; i < sizeClientList; i++)
    {
        for (int j = 0; j < sizeList; j++)
        {
            if (list[i].getId() == salesList[j].getidClient())
            {
                totalSpent += salesList[j].getsalesTotal();
                idClient = salesList[j].getidClient();
            }
            if (totalSpent > highestTotalSpent)
            {
                highestTotalSpent = totalSpent;
                idBestClient = idClient;
            }
            totalSpent = 0;
        }
    }
    int idxCliente = searchClient(idBestClient);
    cout << "======================================\n";
    cout << "|           Melhor Cliente           |\n";
    cout << "======================================\n";
    cout << endl;
    cout << "======================================\n";
    cout << "| ID Cliente | Nome    | Total Gasto |\n";
    cout << "======================================\n";
    cout << left << setw(2) << "" << setw(13) << idBestClient;
    cout << setw(13) << list[idxCliente].getName();
    cout << setw(10) << highestTotalSpent;
    cout << endl
         << endl
         << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

void Shop::printBestSeller()
{
    int qntBestSeller = 0;
    int idBestSeller = -1;
    string nameBestSeller;

    for (int i = 0; i < sizeStock; i++)
    {
        string nameProduct;
        int qntSoldProduct = 0;
        int idProduct = products[i].getId();

        for (int j = 0; j < sizeList; j++)
        {
            // Get the vector of products sold in this sale
            vector<Product> saleProducts = salesList[j].getProducts();
            for (int k = 0; k < saleProducts.size(); k++)
            {
                if (saleProducts[k].getId() == idProduct)
                {
                    qntSoldProduct += saleProducts[k].getQuantity();
                    nameProduct = saleProducts[k].getName();
                }
            }
        }

        if (qntSoldProduct > qntBestSeller)
        {
            qntBestSeller = qntSoldProduct;
            idBestSeller = idProduct;
            nameBestSeller = nameProduct;
        }
    }

    if (idBestSeller != -1)
    {
        cout << "====================================\n";
        cout << "|       Produto Mais Vendido       |\n";
        cout << "====================================\n";
        cout << endl;
        cout << "====================================\n";
        cout << "| ID | Produto mais vendido | Qnt  |\n";
        cout << "====================================\n";
        cout << left << setw(10) << idBestSeller << setw(20) << nameBestSeller << setw(10) << qntBestSeller << endl;
    }
    else
    {
        cout << "Nenhum produto vendido ainda." << endl;
    }
    cout << endl;
    cout << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

void Shop::printWorstProduct()
{
    int qntWorstSeller = 9999;
    int idWorstSeller = -1;
    string nameWorstProduct;

    for (int i = 0; i < sizeStock; i++)
    {
        int qntSoldProduct = 0;
        string nameProduct;
        int idProduct = products[i].getId();

        for (int j = 0; j < sizeList; j++)
        {
            // Get the vector of products sold in this sale
            vector<Product> saleProducts = salesList[j].getProducts();
            for (int k = 0; k < saleProducts.size(); k++)
            {
                if (saleProducts[k].getId() == idProduct)
                {
                    qntSoldProduct += saleProducts[k].getQuantity();
                    nameProduct = saleProducts[k].getName();
                }
            }
        }

        if (qntSoldProduct > 0 && qntSoldProduct < qntWorstSeller)
        {
            qntWorstSeller = qntSoldProduct;
            idWorstSeller = idProduct;
            nameWorstProduct = nameProduct;
        }
    }

    if (idWorstSeller != -1)
    {
        cout << "=====================================\n";
        cout << "|       Produto Menos Vendido       |\n";
        cout << "=====================================\n";
        cout << endl;
        cout << "=====================================\n";
        cout << "| ID | Produto menos vendido | Qnt  |\n";
        cout << "=====================================\n";
        cout << left << setw(10) << idWorstSeller << setw(20) << nameWorstProduct << setw(10) << qntWorstSeller << endl;
    }
    else
    {
        cout << "Nenhum produto vendido ainda." << endl;
    }
    cout << endl;
    cout << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

void Shop::printBestProductProfit()
{
    int maxUnitsSold = 0;
    int idBestSeller = -1;

    for (int i = 0; i < sizeStock; i++)
    {
        int totalUnitsSold = 0;
        int idProduct = products[i].getId();
        for (int j = 0; j < sizeList; j++)
        {
            vector<Product> salesProducts = salesList[j].getProducts();
            for (int k = 0; k < salesProducts.size(); k++)
            {
                if (salesProducts[k].getId() == idProduct)
                {
                    totalUnitsSold += salesProducts[k].getQuantity();
                }
            }
        }
        if (totalUnitsSold > maxUnitsSold)
        {
            maxUnitsSold = totalUnitsSold;
            idBestSeller = idProduct;
        }
    }
    if (idBestSeller != -1)
    {
        int idx = searchStockProduct(idBestSeller);
        double SellPrice = products[idx].getSellPrice();
        double costPrice = products[idx].getPrice();
        double profit = (SellPrice - costPrice) * maxUnitsSold;
        cout << "======================================\n";
        cout << "|       Produto Com Mais Lucro       |\n";
        cout << "======================================\n";
        cout << endl;
        cout << "======================================\n";
        cout << "| ID | Produto mais vendido | Lucro  |\n";
        cout << "======================================\n";
        cout << left << setw(10) << idBestSeller << setw(20) << products[idx].getName() << setw(10) << fixed << setprecision(2) << profit << endl;
    }
    else
    {
        cout << "Nenhum produto vendido ainda." << endl;
        Sleep(2000);
    }
    cout << endl
         << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

void Shop::salesSearch()
{
    string searchName;
    cout << "Digite o nome do produto para pesquisar: ";
    getline(cin, searchName);
    cout << endl;

    bool found = false;
    cout << "==============================================\n";
    cout << "| Venda | Cliente | Produto | Qtd | Total   |\n";
    cout << "==============================================\n";

    for (int i = 0; i < sizeList; i++)
    {
        vector<Product> salesProducts = salesList[i].getProducts();
        for (int j = 0; j < salesProducts.size(); j++)
        {
            // Comparacao Case-Sensitive
            string prodName = salesProducts[j].getName();
            if (toLower(prodName).find(toLower(searchName)) != string::npos)
            {
                found = true;
                int idClient = salesList[i].getidClient();
                int idxClient = searchClient(idClient);
                string nameClient = list[idxClient].getName();
                cout << left
                     << setw(10) << salesList[i].getreceiptNumber()
                     << setw(10) << nameClient
                     << setw(10) << salesProducts[j].getName()
                     << setw(6) << salesProducts[j].getQuantity()
                     << setw(10) << salesProducts[j].getTotal()
                     << endl;
            }
        }
    }
    if (!found)
    {
        cout << RED << "Nenhum produto encontrado com esse nome nas vendas.\n"
             << RESET;
    }
    cout << "==============================================\n";
    cout << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

int Shop::intInputValidation(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value && value >= 0)
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

int Shop::doubleInputValidation(const string &prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        if (cin >> value && value >= 0)
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

string Shop::toLower(string name)
{
    transform(name.begin(), name.end(), name.begin(), ::tolower); // transforma em lowercase
    return name;                                                  // envia o nome em lowercase para variavel
}