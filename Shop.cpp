#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#include "Shop.h"
#include "Sales.h"
#include "Menu.h"

Shop::Shop()
{
    // Stock
    saveProduct("Xadrez", 20, 9.99);
    saveProduct("Catan", 20, 35.00);
    saveProduct("Ticket To Ride", 20, 49.99);
    saveProduct("Carcassonne", 15, 27.99);
    saveProduct("Pandemic", 10, 40.00);
    saveProduct("Monopolio", 12, 21.95);
    saveProduct("UNO", 18, 5.99);
    saveProduct("RISK", 8, 49.98);
    saveProduct("Mysterium", 15, 35.00);
    saveProduct("Concept", 3, 32.50);
    // Lista de Clientes
    saveClient("Carlos", "911223344", "Rua do Sol, 77");
    saveClient("Sofia", "932109876", "Largo da Igreja, 5");
    saveClient("Diogo", "967890123", "Avenida dos Descobrimentos, 10");
    saveClient("Rita", "919876543", "Praca da Republica, 1");
    saveClient("Tiago", "934567890", "Rua das Flores, 42");
    saveClient("Leandro", "993294921", "Debaixo da Ponte, 42");
    // Lista de Vendas  6 vendas de exemplo
    for (int i = 0; i < 4; i++)
    {
        vector<Product> carrinho;
        // Adiciona 2 produtos diferentes ao carrinho (ajusta conforme o teu stock)
        if (sizeStock >= 2)
        {
            Product p1 = products[0];
            p1.setQuantity(1 + i);
            Product p2 = products[1];
            p2.setQuantity(2 + i);
            carrinho.push_back(p1);
            carrinho.push_back(p2);
        }
        int idCliente = (sizeClientList > i) ? list[i].getId() : list[0].getId();
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
        quantityProduct = numberInputValidation("Quantidade: ");
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
    cout << "============================================\n";
    cout << "| ID  | Nome           | Qtd | Preco Custo |\n";
    cout << "============================================\n";
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

    idRemoveProduct = numberInputValidation("ID do Artigo a Apagar: ");
    removeProduct(idRemoveProduct);
    cout << RED << "Artigo Removido." << RESET;
}
void Shop::setProductPrice()
{
    int idProdAlt;
    double novoPreco;
    printStock();
    cout << endl
         << endl;
    idProdAlt = numberInputValidation("ID do Produto: ");
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
    idProdAlt = numberInputValidation("ID do Produto: ");
    int index = searchStockProduct(idProdAlt);
    if (index == -1)
    {
        cout << RED << "Produto nao encontrado!" << RESET << endl;
        return;
    }
    newQuantity = numberInputValidation("Nova Quantidade: ");
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
    IdRemoveclient = numberInputValidation("ID do Cliente a Apagar: ");
    removeClient(IdRemoveclient);
    cout << RED << "Cliente apagado da lista." << RESET;
}

void Shop::setClientPhone()
{
    int idProdAlt;
    string newPhone;
    printClientList();
    cout << endl
         << endl;
    idProdAlt = numberInputValidation("ID do Cliente: ");
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
    idProdAlt = numberInputValidation("ID do Cliente: ");
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
void Shop::setclientName()
{
    int idclientChange;
    string newName;
    printClientList();
    cout << endl
         << endl;
    idclientChange = numberInputValidation("ID do Cliente: ");
    int index = searchClient(idclientChange);
    if (index == -1)
    {
        cout << RED << "Cliente nao encontrado!" << RESET << endl;
        return;
    }
    cout << "Novo Nome: ";
    cin.ignore();
    getline(cin, newName);
    list[index].setAddress(newName);
    cout << GREEN << "Alteracoes Guardadas com Sucesso! ";
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
        idProdAdd = numberInputValidation("Insira o ID do produto a adicionar ao carrinho. (0 para cancelar): ");
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
            quantityAdd = numberInputValidation("Insira a quantidade que deseja adicionar ao carrinho: ");

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
    idRemove = numberInputValidation("Insira o ID do produto a adicionar ao carrinho: ");
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
    idModify = numberInputValidation("ID do Produto a modificar a quantidade: ");
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
        newcartQnt = numberInputValidation("Nova quantidade: ");
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
            cout << endl;
            idSearchClient = numberInputValidation("Insira o seu ID de Cliente: ");
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
            Sleep(2000);
            return;
        }

        cout << "\nTotal a pagar: " << fixed << setprecision(2) << subtotal << " euros\n";

        payment = numberInputValidation("Valor Entregue: (0 para cancelar): ");

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

    for (int i = 0; i < sizeList; i++)
    {
        cout << "=============================================\n";
        cout << "| ID Venda | ID Fatura | ID Cliente | Total |\n";
        cout << "=============================================\n";
        cout << salesList[i].toString() << endl;
    }
    cout << "Pressione ENTER para voltar ao Menu.";
    cin.get();
}

void Shop::printTotalStock()
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
    cout << "=====================================\n";
    cout << "| ID Cliente | Nome   | Total Gasto |\n";
    cout << "=====================================\n";
    cout << left << setw(2) << "" << setw(13) << idBestClient;
    cout << setw(13) << list[idBestClient].getName();
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

    for (int i = 0; i < sizeStock; i++)
    {
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
                }
            }
        }

        if (qntSoldProduct > qntBestSeller)
        {
            qntBestSeller = qntSoldProduct;
            idBestSeller = idProduct;
        }
    }

    if (idBestSeller != -1)
    {
        cout << "Produto mais vendido: ID " << idBestSeller << " com " << qntBestSeller << " unidades vendidas." << endl;
    }
    else
    {
        cout << "Nenhum produto vendido ainda." << endl;
    }
    cout << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

void Shop::printWorstProduct()
{
    int qntWorstSeller = 9999;
    int idWorstSeller = -1;

    for (int i = 0; i < sizeStock; i++)
    {
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
                }
            }
        }

        if (qntSoldProduct > 0 && qntSoldProduct < qntWorstSeller)
        {
            qntWorstSeller = qntSoldProduct;
            idWorstSeller = idProduct;
        }
    }

    if (idWorstSeller != -1)
    {
        cout << "Produto menos vendido: ID " << idWorstSeller << " com " << qntWorstSeller << " unidades vendidas." << endl;
    }
    else
    {
        cout << "Nenhum produto vendido ainda." << endl;
    }
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
        cout << "Produto mais vendido: " << products[idx].getName() << " (ID " << idBestSeller << ") com lucro de " << fixed << setprecision(2) << profit << " EUR." << endl;
    }
    else
    {
        cout << "Nenhum produto vendido ainda." << endl;
    }
    cout << endl
         << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

void Shop::salesSearch()
{
    int id;
    double sellPrice;
    int counter = 0;
    string nameProd;
    int totalUnitsSold = 0;
    cout << "Insira o nome do produto para ver as suas estatisticas: " << endl;
    getline(cin, nameProd);
    for (char &c : nameProd)
    {
        c = tolower(static_cast<unsigned char>(c));
    }

    for (int i = 0; i < sizeList; i++)
    {
        vector<Product> salesSearchProducts = salesList[i].getProducts();

        for (int j = 0; j < salesSearchProducts.size(); j++)
        {
            string existingName = (salesSearchProducts[j].getName());
            for (char &c : existingName)
            {
                c = tolower(static_cast<unsigned char>(c));
            }

            if (salesSearchProducts[i].getName() == nameProd)
            {
                counter++;
                totalUnitsSold += salesSearchProducts[j].getQuantity();
                id = i + 1;
            }
            else
            {
                cout << "Nao existem vendas do produto: " << nameProd;
            }
        }
    }
    for (auto &product : products)
    {
        if (product.getName() == nameProd)
        {
            cout << product.tostring();
            break;
        }
    }
    int idx = searchStockProduct(id);
    double SellPrice = products[idx].getSellPrice();
    double costPrice = products[idx].getPrice();
    double profit = (SellPrice - costPrice) * totalUnitsSold;
    cout << "=====================================\n";
    cout << "| ID | Nome   | Qnt Vendida | Lucro |\n";
    cout << "=====================================\n";
    cout << left << setw(2) << products[idx].getId() << setw(13);
    cout << products[idx].getName() << setw(13);
    cout << totalUnitsSold << setw(10);
    cout << profit << setw(10) << endl
         << endl
         << "Pressione ENTER para voltar ao menu.";
    cin.get();
}

int Shop::numberInputValidation(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value && value > 0)
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
