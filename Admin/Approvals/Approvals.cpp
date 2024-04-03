#include "Approvals.h"

#include "Debit.h"

#include "RequestsFilter.h"

#include "Credit.h"

// Changing The open/closed status on a Debit Card
void Approvals::flagDebitAccount(ifstream& infile, int len) {
	


		// Debit Variables
		double debitAmount;
		string displayDebit;
		string lockCard;
		bool overdraft;
		int ID;



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
		Debit* list = new Debit[len];



		// Reading from the file and populating the lisy
		for (int i = 0; i < (len); i++) {
			infile >> debitAmount >> displayDebit >> lockCard >> overdraft >> ID;

			list[i].setDebitAmount(debitAmount);
			list[i].setDebit(displayDebit);
			list[i].setLockCard(lockCard);
			list[i].setOverdraft(overdraft);
			list[i].set_ID(ID);


			cout << "ID is " << list[i].get_ID() << endl;
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

				cout << "1 for Lock, 2 for Unlock, 3 for exit " << "It is currently " << list[editList].getLockCard() << endl;

				cin >> menu;

				if (menu == 1) {
					
					list[editList].setLockCard("CLOSED");
					//cout << list[editList].getLockCard();
				}

				if (menu == 2) {
					
					list[editList].setLockCard("OPEN");
					//cout << list[editList].getLockCard();
				}

				if (menu == 3) {
					cout << "Exiting" << endl;

				}

			}

		}



		//cout << "ended";

		// Opening the file to add the list data, this removes all existing info from the file
		ofstream outfilechangeAccount;

		outfilechangeAccount.open("CreditList.txt");

		// Putting the info back into the file
		for (int i = 0; i < len; i++) {
			//cout << "Working" << list[i].get_firstname() << endl;
			outfilechangeAccount << list[i].getDebitAmount() << " " << list[i].getDebit() << " " << list[i].getLockCard() << " " << list[i].getOverdraft() << " " << list[i].get_ID() << endl;
		}

		// Updating requests
		ifstream infile3;

		infile3.open("RequestsList.txt", std::ios_base::app);

		len = 0;

		while (infile3 >> s) {
			len += 1;
			//cout << s;
		}

		cout << list[editList].get_ID() << endl;
		ifstream infileRequestsList;

		infileRequestsList.open("RequestsList.txt", std::ios_base::app);

		updateRequests(infileRequestsList, len / 8, "creditUnlock", list[editList].get_ID());
	
};












void Approvals::flagCreditAccount(ifstream& infile, int len) {



	// Debit Variables
	double creditScore = 0;
	bool lockCard;
	bool overdraft;
	int ID;



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
	Credit* list = new Credit[len];



	// Reading from the file and populating the lisy
	for (int i = 0; i < (len); i++) {
		infile >> creditScore >> overdraft >> lockCard  >> ID;

		list[i].setCreditScore(creditScore);
		list[i].setOverdraft(overdraft);
		list[i].setLockCard(lockCard);
		list[i].set_ID(ID);


		cout << "ID is " << list[i].get_ID() << endl;
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

			cout << "1 for Lock, 2 for Unlock, 3 for exit " << "It is currently " << list[editList].getLockCard() << endl;

			cin >> menu;

			if (menu == 1) {

				list[editList].setLockCard(0);
				//cout << list[editList].getLockCard();
			}

			if (menu == 2) {

				list[editList].setLockCard(1);
				//cout << list[editList].getLockCard();
			}

			if (menu == 3) {
				cout << "Exiting" << endl;

			}

		}

	}



	//cout << "ended";

	// Opening the file to add the list data, this removes all existing info from the file
	ofstream outfilechangeAccount;

	outfilechangeAccount.open("DebitList.txt");

	// Putting the info back into the file
	for (int i = 0; i < len; i++) {
		//cout << "Working" << list[i].get_firstname() << endl;
		outfilechangeAccount << list[i].getCreditScore() << " " << list[i].getOverdraft() << " " << list[i].getLockCard() << " " << list[i].getOverdraft() << " " << list[i].get_ID() << endl;
	}

	// Updating requests
	ifstream infile3;

	infile3.open("RequestsList.txt", std::ios_base::app);

	len = 0;

	while (infile3 >> s) {
		len += 1;
		//cout << s;
	}

	cout << list[editList].get_ID() << endl;
	ifstream infileRequestsList;

	infileRequestsList.open("RequestsList.txt", std::ios_base::app);

	updateRequests(infileRequestsList, len / 8, "CreditUnlock", list[editList].get_ID());

};






















void Approvals::updateRequests(ifstream& infile, int len, string type, int ID) {
	// Requests Variables
	double loanAmount = 0;
	double amount = 0;
	int senderID = 0;
	int reciverID = 0;
	string senderaccountType = "";
	string reciveraccountType = "";
	string typeRequest = "";
	char confirm = 'N';



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
	string searchType;

	int editList = 0;
	int menu = 0;
	string edit = "";
	int editID = 0;
	double editB = 0;
	bool editF = false;



	// Creating list fo Customers
	RequestsFilter* list = new RequestsFilter[len];



	// Reading from the file and populating the lisy
	for (int i = 0; i < (len); i++) {
		infile >> loanAmount >> amount >> senderID >> reciverID >> senderaccountType >> reciveraccountType >> typeRequest >> confirm;

		list[i].set_loanAmount(loanAmount);
		list[i].set_amount(amount);
		list[i].set_senderID(senderID);
		list[i].set_reciverID(reciverID);
		list[i].set_senderaccountType(senderaccountType);
		list[i].set_reciveraccountType(reciveraccountType);
		list[i].set_typeRequest(typeRequest);
		list[i].set_confirm(confirm);

		//cout << "working";
		cout << "Sender ID: " << list[i].get_senderID() << "  Reciver ID: " << list[i].get_reciverID() << endl;
	}


	// Running the changing loop until the admin wants to stop;
	while (end == false) {

		found = false;

		// GGiving the program the ID and Type of request we want to search for
		searchID = ID;
		searchType = type;
		

		

		// Checking the list of customers 
		for (int j = 0; j < len; j++) {

			if (list[j].get_senderID() == searchID and list[j].get_typeRequest() == type) {
				cout << list[j].get_loanAmount() << " " << list[j].get_amount() << " " << list[j].get_senderID() << " " << list[j].get_reciverID() << " " << list[j].get_senderaccountType() << " " << list[j].get_typeRequest() << " " << list[j].get_confirm() << endl;
				cout << "found!!" << endl;
				list[j].set_confirm('Y');
				// Found will be true if the ID of the customer we are searching matches the ID we are searching for
				found = true;
			}
			else {

			}

		}
		// If the loop finding matching ID's doesnt find any, the program will display an error messsage and loop again

		if (found == true) {
			end = true;
			found = false;
		}

		else if (found == false) {
			cout << "Could not Find Request with that ID, try again" << endl << endl;
			end = true;
		}
	}
	// Opening the file to add the list data, this removes all existing info from the file
	ofstream outfileUpdateReq;

	outfileUpdateReq.open("RequestsList.txt");

	// Putting the info back into the file
	for (int i = 0; i < len; i++) {
		//cout << "Working" << list[i].get_firstname() << endl;
		outfileUpdateReq << list[i].get_loanAmount() << " " << list[i].get_amount() << " " << list[i].get_senderID() << " " << list[i].get_reciverID() << " " << list[i].get_senderaccountType() << " " << list[i].get_reciveraccountType() << " " << list[i].get_typeRequest() << " " << list[i].get_confirm() << endl;
	}
	
};
