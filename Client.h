#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Client
{
private:
    int id;
    string name;
    int phone;
    string address;
    static int nextId;

public:
    // Construtores
    Client();
    Client(int id, string name, int phone, string address);

    // Gets
    int getId();
    string getName();
    int getPhone();
    string getAddress();
    // Sets
    void setId();
    void setName();
    void setPhone();
    void setAddress();

    string toString();
};

#endif