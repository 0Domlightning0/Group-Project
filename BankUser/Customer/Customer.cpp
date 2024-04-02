#include "Customer.h"

#include "BankUser.h"

Customer::Customer() {};

Customer::Customer(string fi, string la, string da, string pa, string ag, int id, double ba, bool fl) : BankUser(fi,la,pa,da,ag,id)
{
	balance = ba;
	flagged = fl;
};

Customer::~Customer() {};
