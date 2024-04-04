// Jalen Taylor, 400470470
#pragma once
#include "Transactions.h"
class Requests :
    public Transactions
{
protected:
    // Class variables
    string m_loanAmount;

public:

    // Default constructor
    Requests();

    // Overloaded constructor
    Requests(string loanAmount);

    // Deconstructor
    ~Requests();

    // Getters
    string getloanAmount() { return m_loanAmount; }

    //Setters
    void setloanAmount(string loanAmount) { m_loanAmount = loanAmount; }

    // Function to navigate a requests menu
    virtual void navigateRequests(double amount);

    // Function to apply for a bank loan
    virtual void loanApply(double amount);

    // Function to send a request to another user
    void outRequests(double amount);

    // Function to view and approve/deny incoming requests
    void inRequests(double amount);

    // Function to send money to another user
    void sendMoney(double amount);

    // Function to request money from another user
    void requestMoney(double amount);

    // View outgoing request history
    void requestHistory(double amount);
};
