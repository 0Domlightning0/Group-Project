#pragma once
#include "Admin.h"
#include "Customer.h"
class CustomerSettings :
    public Admin, public Customer
{
private:

public:
    CustomerSettings();

    CustomerSettings(string fi, string la, string da, string pa, string ag);

    ~CustomerSettings();

    bool login(string p);

    // Changing Account Information
    Customer changeAccount();

    // Creating a Customer Account, creates a new customer object
    Customer createAccount();

    // Flagging Account
    void flagAccount();

};

