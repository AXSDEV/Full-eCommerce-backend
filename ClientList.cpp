#include "ClientList.h"

ClientList::ClientList()
{
    // Lista de Clientes
    saveClient("Carlos", "911223344", "Rua do Sol, 77");
    saveClient("Sofia", "932109876", "Largo da Igreja, 5");
    saveClient("Diogo", "967890123", "Avenida dos Descobrimentos, 10");
    saveClient("Rita", "919876543", "Praca da Republica, 1");
    saveClient("Tiago", "934567890", "Rua das Flores, 42");
    saveClient("Leandro", "999PfNaoincomode", "Debaixo da Ponte, 42");
}

void ClientList::saveClient(string name, string phone, string address)
{
    if (sizeClientList < 100)
    {
        Client client(name, phone, address);
        list[sizeClientList] = client;
        sizeClientList++;
    }
}
void ClientList::addClient()
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

int ClientList::searchClient(int id)
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

void ClientList::printClientList()
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

void ClientList::removeClient(int id)
{
    int pos = searchClient(id); // pos = position
    for (int i = pos; i < sizeClientList; i++)
    {
        list[i] = list[i + 1];
    }
    sizeClientList--;
}
void ClientList::removeFromclientlist()
{
    int IdRemoveclient;
    printClientList();
    cout << endl
         << endl;

    cout << "ID do Cliente a Apagar: ";
    cin >> IdRemoveclient;
    removeClient(IdRemoveclient);
}

void ClientList::setClientPhone()
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
void ClientList::setClientAddress()
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