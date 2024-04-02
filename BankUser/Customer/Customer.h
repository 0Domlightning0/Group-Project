#pragma once
#include "BankUser.h"
class Customer : public BankUser
{
private:
    double balance = 0;
    bool flagged = false;
public:
    Customer();

    Customer(string fi, string la, string da, string pa, string ag, int id, double ba, bool fl);

    ~Customer();

    // getters 
    double get_balance() { return balance; };
    bool get_flagged() { return flagged; }

    //setters
    void set_balance(double ba) { balance = ba; };
    void set_flagged(bool fl) { flagged = fl; };
};

