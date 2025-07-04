#include "Client.h"

// Construtores
Client::Client()
{
}
int Client::nextId = 1;
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
    stringstream oss;
    oss << left << setw(8) << id
        << setw(15) << name
        << setw(32) << phone
        << setw(30) << address;
    return oss.str();
}