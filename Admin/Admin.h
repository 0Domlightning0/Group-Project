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

	Admin(string fi, string la, string da, string pa, string ag, int id);

	~Admin();

	// Getters
	bool get_adminAccess() { return adminAccess; };

	// Setters
	void set_adminAccess(bool ad) { adminAccess = ad; };
	// Creates a new Customer 
	void regClient();

	// Must input a password to access admin functions
	bool login(string p);

	// exits the account
	void logout();

	void displayTransactions();

	void displayRequests();

	void displayInvestments();
};



