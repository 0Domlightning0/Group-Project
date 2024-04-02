#include "Admin.h"

#include "BankUser.h"

Admin::Admin() {
	adminAccess = false;
};

Admin::Admin(string fi, string la, string da, string pa, string ag, int id) : BankUser(fi,la,da,pa,ag,id) {
};

Admin::~Admin() {};

// Creates a new Customer; Datatype will be Customer
void Admin::regClient() {
	// return Customer(blah, blah)
};

// Must input a password to access admin functions
bool Admin::login(string p) {
	if (BankUser::login(p) == true) {
		cout << "Welcome " << get_firstname() << endl;
		adminAccess = true;
		return true;
	}
	else {
		cout << "Incorrect Password " << endl;
		adminAccess = false;
		return false;
	}
};



// exits the account
void Admin::logout() {

};
