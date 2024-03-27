#include "CustomerSettings.h"


#include <fstream>

using namespace std;

CustomerSettings::CustomerSettings() {};

CustomerSettings::~CustomerSettings() {};

CustomerSettings::CustomerSettings(string fi, string la, string da, string pa, string ag, int id) : Admin(fi, la, da, pa, ag,id) {
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
Customer CustomerSettings::createAccount(ofstream& outfile) {

	if (adminAccess == true) {
		// Customer Variables
		string firstname;
		string lastname;
		string date;
		string age;
		string password;
		int ID;

		// Input
		cout << "What is the users first name?";
		cin >> firstname;
		cout << "What is the users last name?";
		cin >> lastname;
		cout << "What is the date of creation?";
		cin >> date;
		cout << "What is the users age?";
		cin >> age;
		cout << "What is the users password?";
		cin >> password;
		cout << "What is the users ID?";
		cin >> ID;



		outfile << firstname<< " " << lastname << " "<< date << " " << age << " " << password << " " << ID <<  endl;
		outfile.flush();
		return Customer(firstname, lastname, date, password, age, ID);
	}
	else {
		cout << "you do not have access";
		return Customer();
	}
};



// Flagging Account
void CustomerSettings::flagAccount() {};
