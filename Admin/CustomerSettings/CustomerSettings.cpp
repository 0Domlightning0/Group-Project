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
Customer CustomerSettings::changeAccount(ifstream& infile, int len) {

	

	// Customer Variables
	string firstname;
	string lastname;
	string date;
	string age;
	string password;
	int ID;



	//List variables
	int length = 0;
	string s;
	int listLength = 0;
	bool end = false;
	bool found = false;
	int searchID = 0;
	int editList = 0;
	int menu = 0;
	string edit = "";



	// Creating lsit fo Customers
	Customer* list = new Customer[100];



	// Reading from the file and populating the lisy
	for (int i = 0; i < (len); i++) {
		infile >> firstname >> lastname >> date >> age >> password >> ID;

		list[i].set_firstname(firstname);
		list[i].set_lastname(lastname);
		list[i].set_dateOfBirth(date);
		list[i].set_age(age);
		list[i].set_password(password);
		list[i].set_ID(ID);

		cout << "ID is " << list[i].get_ID() << "i is " << i << endl;
	}


	// Running the changing loop until the admin wants to stop;
	while (end == false) {


		// Getting the Id of the customer the admin wants to change
		cout << "What User would you like to change (Input ID) Put 99 for exit: ";
		cin >> searchID;

		// Checking the list of customers 
		for (int j = 0; j < len; j++) {

			if (list[j].get_ID() == searchID) {
				cout << list[j].get_ID();
				cout << searchID;

				// Found will be true if the ID of the customer we are searching matches the ID we are searching for
				found = true;

				// The position in the list of the found customer will be saved
				editList = j;


				cout << j;
				cout << "FOUND";
			}
			else {

			}
		}

	// If 99 is inputted the loop ends and the found vaiable is back to default
		if (searchID == 99) {
			end = true;
			found = false;
		}

		// If the loop finding matching ID's doesnt find any, the program will display an error messsage and loop again
		else if (found == false) {
			cout << "Could not Find customer with that ID, try again" << endl << endl;
		}

		// This function happens if the matching loop finds a matching  ID
		else if (found == true) {
			cout << "what variable would you like to edit?" << endl;
			cout << "1 for firstname";
			cin >> menu;

			if (menu == 1) {
				cout << "What do you want your new firstname to be";
				cin >> edit;
				list[editList].set_firstname(edit);
				cout << list[editList].get_firstname();
			}
		}

	}
	
	cout << "ended";

	ofstream outfilechangeAccount;

	outfilechangeAccount.open("CustomerList.txt");

	for (int i = 0; i < len; i++) {
		cout << "Working" << list[i].get_firstname() << endl;
		outfilechangeAccount << list[i].get_firstname() << " " << list[i].get_lastname() << " " << list[i].get_dateOfBirth() << " " << list[i].get_age() << " " << list[i].get_password() << " " << list[i].get_ID() << endl;
	}
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



		outfile << firstname << " " << lastname << " " << date << " " << age << " " << password << " " << ID << endl;
		return Customer(firstname, lastname, date, password, age, ID);
	}
	else {
		cout << "you do not have access";
		return Customer();
	}
};



// Flagging Account
void CustomerSettings::flagAccount() {};
