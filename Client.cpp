#include "Client.h"

// Construtores
Client::Client()
{
}

int Client::nextId = 1;

Client::Client(int id, string name, int phone, string address)
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
int Client::getPhone()
{
    return phone;
}
string Client::getAddress()
{
    return address;
}
// Sets
void Client::setName()
{
    this->name = name;
}
void Client::setPhone()
{
    this->phone = phone;
}
void Client::setAddress()
{
    this->address = address;
}

// toString
string Client::toString()
{
    return "ID: \n" + to_string(id) + "Name: \n" + name + "Phone: \n" + to_string(phone) + "Address: \n" + address;
}