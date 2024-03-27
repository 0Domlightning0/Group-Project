// Cpp for BankUser class

#include "BankUser.h"

// Default Constructor
BankUser::BankUser() {

	firstname = "";
	lastname = "";
	dateCreated = "";
	password = "";
};

// Overloaded Constructor
BankUser::BankUser(string fi, string la, string da, string pa, string ag, int id) {
	firstname = fi;
	lastname = la;
	dateCreated = da;
	password = pa;
	age = ag;
	ID = id;
};

// Deconstructor 
BankUser::~BankUser() {};

// Login function that uses the password and returns a bool that signals if the user(Admin/Customer) is given acccess
bool BankUser::login(string p) {
	return false;
};

// Logout function that brings the user ack to the menu
void BankUser::logout() {};
