// Header for BankUser class

#pragma once

#include <iostream>

using namespace std;

// Used for both the Admin and Customer class

// Parent: none

// Children: Admin, Customer

class BankUser
{
private:
	string firstname = "";
	string lastname = "";
	string dateCreated = "";
	string password = "";
	string age = "";


public:
	// Default Constructor
	BankUser();

	// Overloaded Constructor
	BankUser(string fi, string la, string da, string pa, string ag);

	// Deconstructor 
	~BankUser();


	// Getters: void get_[Variable name](){ return [Variable name];};

	string get_firstname() { return firstname; };
	string get_lastname() { return lastname; };
	string get_dateCreated() { return dateCreated; };
	string get_password() { return password; };

	// Setters set_[Variable name](datatype [First 2 letters of variable]){ [Variable name] = [First 2 letters of variable];};

	void set_firstname(string fi) { firstname = fi; };
	void set_lastname(string la) { lastname = la; };
	void set_dateCreated(string da) { dateCreated = da; };
	void set_password(string pa) { password = pa; };


	// Functions:

	// Login function that uses the password and returns a bool that signals if the user(Admin/Customer) is given acccess
	virtual bool login(string p);

	// Logout function that brings the user ack to the menu
	virtual void logout();



};

