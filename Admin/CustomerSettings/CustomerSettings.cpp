#include "CustomerSettings.h"

using namespace std;

CustomerSettings::CustomerSettings() {};

CustomerSettings::~CustomerSettings() {};

CustomerSettings::CustomerSettings(string fi, string la, string da, string pa, string ag) : Admin(fi, la, da, pa, ag) {
};

bool CustomerSettings::login(string p) {
	if (Admin::login(p) == true) {
		adminAccess = true;
	}
	return Admin::login(p);
}

// Changing Account Information
Customer CustomerSettings::changeAccount() {
	return Customer();
};

// Creating a Customer Account, creates a new customer object
Customer CustomerSettings::createAccount() {

	if (adminAccess == true) {
		string firstname;
		string lastname;
		string age;

		cout << "What is the users first name?";
		cin >> firstname;
		cout << "What is the users last name?";
		cin >> lastname;
		cout << "What is the users age?";
		cin >> age;

		return Customer(firstname, lastname, age, "wsds", "sdsd");
	}
	else {
		cout << "you do not have access";
		return Customer();
	}
};

// Flagging Account
void CustomerSettings::flagAccount() {};
