#pragma once
#include "BankUser.h"
class Customer :
    public BankUser
{
private:

public:
    Customer();

    Customer(string fi, string la, string da, string pa, string ag, int id);

    ~Customer();
};

