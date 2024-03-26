#pragma once
#include "Transactions.h"
class Requests :
    public Transactions
{
protected:

public:
    // Default Constructor
    Requests();

    // Overloaded Constructor
    Requests(int temp);

    // Deconstructor
    ~Requests();

    // Getters
    

    // Setters


    // Function to apply for a bank loan

    // Function to send a request (either send money or request money (outputs to file))

    // Function to display your request history (reads your prior requests from a file)

    // Function to approve/deny incoming requests (also lets you know if you have none to avoid a blank output)


};


