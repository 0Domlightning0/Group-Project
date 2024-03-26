// Header File Admin

#pragma once

#include "BankUser.h"

#include <iostream>

using namespace std;

// Connects to Customer, Requests, Transactions

// Parent: BankUser

// Children: None




class Admin : public BankUser
{
protected:
	bool adminAccess = false;
public:

	Admin();

	Admin(string fi, string la, string da, string pa, string ag);

	~Admin();

	// Creates a new Customer 
	void regClient();

	// Must input a password to access admin functions
	bool login(string p);

	// Shows all the data of the customers
	void viewCustomers();

	// Shows all transactions made on the program, uses transaction class
	void viewTransactions();

	// Shows all requests made on the program, uses requests class
	void viewRequests();

	// exits the account
	void logout();
};

