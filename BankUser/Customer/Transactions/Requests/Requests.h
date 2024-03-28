#pragma once
#include "Transactions.h"
class Requests :
    public Transactions
{
protected:
    double m_loanAmount;

public:

    // Default constructor
    Requests();

    // Overloaded constructor
    Requests(double loanAmount);

    // Deconstructor
    ~Requests();

    // Getters
    double getloanAmount() { return m_loanAmount; }

    //Setters
    void setloanAmount(double loanAmount) { m_loanAmount = loanAmount; }

    // Function to navigate a requests menu
    virtual void navigateRequests(double amount);

    // Function to apply for a bank loan
    virtual void loanApply(double amount);

    // Function to send a request to another user
    void outRequests(double amount);

    // Function to view and approve/deny incoming requests
    void inRequests(double amount);

    void sendMoney(double amount);

    void requestMoney(double amount);
};
