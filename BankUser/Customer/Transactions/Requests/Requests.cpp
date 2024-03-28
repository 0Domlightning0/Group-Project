#include "Requests.h"
#include <iostream>

using namespace std;

// Default constructor
Requests::Requests()
{
	m_loanAmount = 0.0;
}

// Overloaded constructor
Requests::Requests(double loanAmount)
{
	m_loanAmount = loanAmount;
}

// Deconstructor
Requests::~Requests()
{

}

// Function to navigate a requests menu
void Requests::navigateRequests(double amount)
{
	int choice;
	do
	{
		cout << "\nPlease select one of the following options\n\n1) - Apply for a Loan\n2) - View Outgoing Requests\n3) - View Incoming Requests\n4) - Go Back\n" << endl;
		cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			cout << "\nERROR: Please enter a vailid choice.\n" << endl;
		}
		else if (choice == 1)
		{
			loanApply(amount);
		}
		else if (choice == 2)
		{
			outRequests(amount);
		}
		else if (choice == 3)
		{
			inRequests(amount);
		}
		else if (choice == 4)
		{
			navigate(amount);
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

// Function to apply for a bank loan
// Will update to output this set amount to a file, linked to account number for admin to approve
void Requests::loanApply(double amount)
{
	int lAmount;
	do
	{
		cout << "\nHow much money would you like to apply for?\n\n1) - $50\n2) - $500\n3) - $5000\n4) - Go Back\n" << endl;
		cin >> lAmount;

		if (lAmount != 1 && lAmount != 2 && lAmount != 3 && lAmount != 4)
		{
			cout << "\nERROR: Please enter a vailid choice.\n" << endl;
		}
		else if (lAmount == 1)
		{
			cout << "\nYou have applied for $50!\nPlease wait for an admin to approve this request :)\n" << endl;

			navigateRequests(amount);
		}
		else if (lAmount == 2)
		{
			cout << "\nYou have applied for $500!\nPlease wait for an admin to approve this request :)\n" << endl;

			navigateRequests(amount);
		}
		else if (lAmount == 3)
		{
			cout << "\nYou have applied for $5000!\nPlease wait for an admin to approve this request :)\n" << endl;

			navigateRequests(amount);
		}
		else if (lAmount == 4)
		{
			navigateRequests(amount);
		}
	} while (lAmount != 1 && lAmount != 2 && lAmount != 3 && lAmount != 4);
}

// Function to send a request to another user
void Requests::outRequests(double amount)
{
	int choice;
	do
	{
		cout << "\nPlease select one of the following options\n\n1) - Send Money to Another User\n2) - Request Money From Another User\n3) - View Outgoing Request History\n4) - Go Back\n" << endl;
		cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			cout << "\nERROR: Please enter a vailid choice.\n" << endl;
		}
		else if (choice == 1)
		{
			sendMoney(amount);
		}
		else if (choice == 2)
		{
			requestMoney(amount);
		}
		else if (choice == 3)
		{
			
		}
		else if (choice == 4)
		{
			navigateRequests(amount);
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

void Requests::sendMoney(double amount)
{
	int tempID = 12345;
	int enteredID;
	double enteredAmount;
	int selectedAcc;
	string account;
	char confirm;

	cout << "\nPlease enter the user ID of the person you would like to send money to: " << endl;
	cin >> enteredID;

	cout << "\nPlease enter the amount of money you would like to send to user #" << enteredID << ": " << endl;
	cin >> enteredAmount;

	cout << "\nPlease select the account you would like to send money from:\n1) - Checking\n2) - Savings" << endl;
	cin >> selectedAcc;

	if (selectedAcc == 1)
	{
		account = "Checking";
	}
	else if (selectedAcc == 2)
	{
		account = "Savings";
	}
	else if (selectedAcc != 1 && selectedAcc != 2)
	{
		cout << "\nERROR: Please restart and choose a valid account" << endl;

		outRequests(amount);
	}

	cout << "\nYou are currently attempting to send " << enteredAmount << " to user #" << enteredID << " From your " << account << " account\nIs this correct ? (Y / N) : \n" << endl;
	cin >> confirm;

	if (confirm == 'N')
	{
		cout << "\nYou Chose: N\nYou are now being taken back to the outgoing requests menu." << endl;

		outRequests(amount);
	}
	else if (confirm != 'Y' && confirm != 'N')
	{
		cout << "\nYou must enter a valid choice.\nPlease restart this process." << endl;

		sendMoney(amount);
	}

	if (enteredID != tempID)
	{
		cout << "\nERROR: The user you are attempting to send money to does not exist.\nPlease try again.\n" << endl;

		outRequests(amount);
	}
	else if (enteredID == tempID)
	{
		cout << "\nYou Chose: Y\nThe request to send $" << enteredAmount << " to user #" << enteredID << " from your " << account << " has been sent and is awaiting their approval\n" << endl;

		outRequests(amount);
	}

}

void Requests::requestMoney(double amount)
{

}

// Function to view and approve/deny incoming requests
void Requests::inRequests(double amount)
{

}
