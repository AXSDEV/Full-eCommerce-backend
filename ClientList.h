#ifndef CLIENTLIST_H
#define CLIENTLIST_H
#include "Client.h"

class ClientList
{
    Client list[100];
    int sizeClientList = 0;

public:
    ClientList();

    void saveClient(string name, string phone, string address);
    int searchClient(int id);
    void printClientList();
    void removeClient(int id);
    void removeFromclientlist();
    void addClient();
    void setClientPhone();
    void setClientAddress();

private:
};

#endif