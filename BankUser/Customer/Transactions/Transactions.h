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

    // Deposit function that allows a user to add money to a checking(debit) account
    virtual void depositC(double amount);

    // Deposit function that allows a user to add money to a savings account
    virtual void depositS(double amount);

    // Withdraw function that allows a user to take money out of a checking(debit) account
    virtual void withdrawC(double amount);

    // Withdraw function that allows a user to take money out of a savings account
    virtual void withdrawS(double amount);

    // Engage in one of the above transactions through a menu-driven function
    void createTransaction(double amount);

    // Navigate the transactions section using a menu
    void navigate(double amount);

    // View prior transaction history after entering ID
    void transactionHistory(double amount);
};
