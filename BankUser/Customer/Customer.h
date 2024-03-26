#pragma once
#include "BankUser.h"
class Customer :
    public BankUser
{
private:
    int ID = 0;

public:
    Customer();

    Customer(string fi, string la, string da, string pa, string ag);

    ~Customer();
};

