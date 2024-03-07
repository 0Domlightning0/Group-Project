// Header for BankUser class

#include "BankUser.h"

// Default Constructor
BankUser::BankUser() {};

// Overloaded Constructor
BankUser::BankUser(string fi, string la, string da, string pa) {
	firstname = fi;
	lastname = la;
	dateCreated = da;
	password = pa;
};

// Deconstructor 
BankUser::~BankUser() {};
