#include "Customer.h"

#include "BankUser.h"

Customer::Customer() {};

Customer::Customer(string fi, string la, string da, string pa, string ag, int id) : BankUser(fi,la,pa,da,ag,id)
{

};

Customer::~Customer() {};
