#pragma once
#include "Customer.h"
class Transactions :
    public Customer
{
protected:
    double m_balance;
    int m_numDep;
    int m_numWith;
public:
    // Default Constructor
    Transactions();

    // Overloaded Constructor
    Transactions(double balance, int numDep, int numWith);

    // Deconstructor
    ~Transactions();

    // Getters
    double getBalance() { return m_balance; }
    int getnumDep() { return m_numDep; }
    int getnumWith() { return m_numWith; }

    // Setters
    void setBalance(double balance) { m_balance = balance; }
    void setnumDep(int numDep) { m_numDep = numDep; }
    void setnumWith(int numWith) { m_numWith = numWith; }

    // Deposit function that allows a user to add money to an account
    virtual void deposit(double amount);

    // Withdraw function that allows a user to take money out of an account
    virtual void withdraw(double amount);


};


