#include "Client.h"
int Client::nextId = 1;
// Construtores

Client::Client(string name, string phone, string address)
{
    this->id = nextId++;
    this->name = name;
    this->phone = phone;
    this->address = address;
}
// Gets
int Client::getId()
{
    return id;
}
string Client::getName()
{
    return name;
}
string Client::getPhone()
{
    return phone;
}
string Client::getAddress()
{
    return address;
}
// Sets
void Client::setName(string name)
{
    this->name = name;
}
void Client::setPhone(string phone)
{
    this->phone = phone;
}
void Client::setAddress(string address)
{
    this->address = address;
}

// toString
string Client::toString()
{
    return "ID: " + to_string(id) + "\nName: " + name + "\nPhone: " + phone + "\nAddress: " + address;
}