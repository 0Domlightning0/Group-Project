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
private:
	bool adminAccess = false;
public:

	Admin();

	Admin(string fi, string la, string da, string pa, bool ad);

	~Admin();


	// Getters: void get_[Variable name](){ return [Variable name];};
	bool get_adminAccess() { return adminAccess; };

	// Setters set_[Variable name](datatype [First 2 letters of variable]){ [Variable name] = [First 2 letters of variable];};
	bool set_adminAccess(bool ad) { adminAccess = ad; };

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
