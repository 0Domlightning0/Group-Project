#include "CustomerSettings.h"


#include <fstream>

using namespace std;

CustomerSettings::CustomerSettings() {};

CustomerSettings::~CustomerSettings() {};

CustomerSettings::CustomerSettings(string fi, string la, string da, string pa, string ag, int id) : Admin(fi, la, da, pa, ag, id){
};






bool CustomerSettings::login(string p) {

	if (Admin::login(p) == true) {

		adminAccess = true;
	}

	return Admin::login(p);
}





// Changing Account Information
Customer CustomerSettings::changeAccount(ifstream& infile, int len) {
	if (adminAccess == true) {


		// Customer Variables
		string firstname;
		string lastname;
		string date;
		string age;
		string password;
		int ID;
		double balance;
		bool flagged;



		//List variables

		int length = 0;
		string s;
		int listLength = 0;
		// Loop governing variable
		bool end = false;
		// Detection variable
		bool found = false;

		// Used for setting an ID that the admin wants to look for
		int searchID = 0;

		int editList = 0;
		int menu = 0;
		string edit = "";
		int editID = 0;
		double editB = 0;
		bool editF = false;



		// Creating list fo Customers
		Customer* list = new Customer[len];



		// Reading from the file and populating the lisy
		for (int i = 0; i < (len); i++) {
			infile >> firstname >> lastname >> date >> age >> password >> ID >> balance >> flagged;

			list[i].set_firstname(firstname);
			list[i].set_lastname(lastname);
			list[i].set_dateOfBirth(date);
			list[i].set_age(age);
			list[i].set_password(password);
			list[i].set_ID(ID);
			list[i].set_balance(balance);
			list[i].set_flagged(flagged);

			//cout << "ID is " << list[i].get_ID() << "i is " << i << endl;
		}


		// Running the changing loop until the admin wants to stop;
		while (end == false) {

			found = false;

			// Getting the Id of the customer the admin wants to change
			cout << "What User would you like to change (Input ID) Put 99 for exit: ";
			cin >> searchID;

			// Checking the list of customers 
			for (int j = 0; j < len; j++) {

				if (list[j].get_ID() == searchID) {
					//cout << list[j].get_ID();
					//cout << searchID;

					// Found will be true if the ID of the customer we are searching matches the ID we are searching for
					found = true;

					// The position in the list of the found customer will be saved
					editList = j;


					//cout << j;
					//cout << "FOUND";
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

				cout << "1 for firstname" << endl;
				cout << "2 for lastname" << endl;
				cout << "3 for date of birth" << endl;
				cout << "4 for age" << endl;
				cout << "5 for password" << endl;
				cout << "6 for ID" << endl;
				cout << "7 for balance" << endl;
				cout << "8 for flagged status" << endl;
				cout << "9 to exit" << endl;
				cout << "what variable would you like to edit? " << endl;

				cin >> menu;

				if (menu == 1) {
					cout << "What do you want the new firstname to be? ";
					cin >> edit;
					list[editList].set_firstname(edit);
					cout << list[editList].get_firstname();
				}

				if (menu == 2) {
					cout << "What do you want the new lastname to be? ";
					cin >> edit;
					list[editList].set_lastname(edit);
					cout << list[editList].get_lastname();
				}

				if (menu == 3) {
					cout << "What do you want the new date of birth to be? ";
					cin >> edit;
					list[editList].set_dateOfBirth(edit);
					cout << list[editList].get_dateOfBirth();
				}

				if (menu == 4) {
					cout << "What do you want the new age to be? ";
					cin >> edit;
					list[editList].set_age(edit);
					cout << list[editList].get_age();
				}

				if (menu == 5) {
					cout << "What do you want the new password to be? ";
					cin >> edit;
					list[editList].set_password(edit);
					cout << list[editList].get_password();
				}

				if (menu == 6) {
					cout << "What do you want the new ID to be? ";
					cin >> editID;
					list[editList].set_ID(editID);
					cout << list[editList].get_ID();
				}

				if (menu == 7) {
					cout << "What do you want the new balance to be? ";
					cin >> editB;
					list[editList].set_balance(editB);
					cout << list[editList].get_balance();
				}

				if (menu == 8) {
					cout << "What do you want the new flagged status to be? ";
					cin >> editF;
					list[editList].set_flagged(editF);
					cout << list[editList].get_flagged();
				}

				if (menu == 9) {
					cout << "Exiting" << endl;

				}
			}

		}

		//cout << "ended";

		// Opening the file to add the list data, this removes all existing info from the file
		ofstream outfilechangeAccount;

		outfilechangeAccount.open("CustomerList.txt");

		// Putting the info back into the file
		for (int i = 0; i < len; i++) {
			//cout << "Working" << list[i].get_firstname() << endl;
			outfilechangeAccount << list[i].get_firstname() << " " << list[i].get_lastname() << " " << list[i].get_dateOfBirth() << " " << list[i].get_age() << " " << list[i].get_password() << " " << list[i].get_ID() << " " << list[i].get_balance() << " " << list[i].get_flagged() << endl;
		}
		return Customer();
	}
	else {
		cout << "you do not have access";
		return Customer();
	}
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
		double balance;
		bool flagged;

		// Input
		cout << "What is the users first name?";
		cin >> firstname;
		cout << "What is the users last name?";
		cin >> lastname;
		cout << "What is users date of birth?";
		cin >> date;
		cout << "What is the users age?";
		cin >> age;
		cout << "What is the users password?";
		cin >> password;
		cout << "What is the users ID?";
		cin >> ID;
		cout << "What is the users starting balance?";
		cin >> balance;
		cout << "Is the user flagged? (0/1)";
		cin >> flagged;



		outfile << firstname << " " << lastname << " " << date << " " << age << " " << password << " " << ID << " " << balance << " " << flagged << endl;
		return Customer(firstname, lastname, date, password, age, ID, balance, flagged);
	}
	else {
		cout << "you do not have access";
		return Customer();
	}
};



