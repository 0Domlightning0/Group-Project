#include "Admin.h"

#include "BankUser.h"

Admin::Admin() {
	adminAccess = false;
};

Admin::Admin(string fi, string la, string da, string pa, string ag) : BankUser(fi,la,da,pa,ag) {
};

Admin::~Admin() {};

// Creates a new Customer; Datatype will be Customer
void Admin::regClient() {
	// return Customer(blah, blah)
};

// Must input a password to access admin functions
bool Admin::login(string p) {
	if (p == get_password()) {
		cout << "Welcome " << get_firstname() << endl;
		adminAccess = true;
		return true;
	}
	else {
		cout << "Incorrect Password "<< endl;
		return false;
		adminAccess = false;
	}
};

// Shows all the data of the customers
void Admin::viewCustomers() {
	if (adminAccess == true) {

	}
};

// Shows all transactions made on the program, uses transaction class
void Admin::viewTransactions() {
	if (adminAccess == true) {

	}

};

// Shows all requests made on the program, uses requests class
void Admin::viewRequests() {
	if (adminAccess == true) {

	}

};

// exits the account
void Admin::logout() {

};
