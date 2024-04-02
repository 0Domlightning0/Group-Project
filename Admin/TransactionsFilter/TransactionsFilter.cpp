#include "TransactionsFilter.h"

#include <fstream>

TransactionsFilter::TransactionsFilter() {};

TransactionsFilter::TransactionsFilter(double loanAmount, double amount, int senderID, int reciverID, string senderaccountType, string reciveraccountType) {
	m_loanAmount = loanAmount;
	m_amount = amount; 
	m_senderID = senderID; 
	m_reciverID = reciverID; 
	m_senderaccountType = senderaccountType;
	m_reciveraccountType = reciveraccountType;

};

TransactionsFilter::~TransactionsFilter() {};



void TransactionsFilter::displayTransactions(ifstream& infile, int len) {
	// Customer Variables
	double loanAmount = 0;
	double amount = 0;
	int senderID = 0;
	int reciverID = 0;
	string senderaccountType = "";
	string reciveraccountType = "";



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
	TransactionsFilter* list = new TransactionsFilter[len];



	// Reading from the file and populating the lisy
	for (int i = 0; i < (len); i++) {
		infile >> loanAmount >> amount >> senderID >> reciverID >> senderaccountType >> reciveraccountType;

		list[i].set_loanAmount(loanAmount);
		list[i].set_amount(amount);
		list[i].set_senderID(senderID);
		list[i].set_reciverID(reciverID);
		list[i].set_senderaccountType(senderaccountType);
		list[i].set_reciveraccountType(reciveraccountType);
		

		//cout << "ID is " << list[i].get_ID() << "i is " << i << endl;
	}


	// Running the changing loop until the admin wants to stop;
	while (end == false) {

		found = false;

		// Getting the Id of the customer the admin wants to change
		cout << "What User would you like to look for (Input ID) Put 99 for exit: ";
		cin >> searchID;

		// Checking the list of customers 
		for (int j = 0; j < len; j++) {

			if (list[j].get_senderID() == searchID) {
				cout << list[j].get_loanAmount() << " " << list[j].get_amount() << " " << list[j].get_senderID() << " " << list[j].get_reciverID() << " " << list[j].get_senderaccountType() << " " << list[j].get_reciveraccountType() << endl;
				//cout << searchID;

				// Found will be true if the ID of the customer we are searching matches the ID we are searching for
				found = true;



				
			}
			else {

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
		}

	}
};






