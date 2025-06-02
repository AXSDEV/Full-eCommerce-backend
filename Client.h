#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

class Client
{
private:
    int id;
    string name;
    string phone;
    string address;
    static int nextId;

public:
    // Construtores
    Client();
    Client(string name, string phone, string address);

    // Gets
    int getId();
    string getName();
    string getPhone();
    string getAddress();
    // Sets
    void setName(string name);
    void setPhone(string phone);
    void setAddress(string address);

    string toString();
};

#endif