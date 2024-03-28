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
			int tempID = 12345;
			int enteredID;
			double enteredAmount;
			cout << "\nPlease enter the user ID of the person you would like to send money to: \n" << endl;
			cin >> enteredID;

			cout << "/Please enter the amount of money you would like to send to user #" << enteredID << ": \n" << endl;
			cin >> enteredAmount;



		}
		else if (choice == 2)
		{
			outRequests();
		}
		else if (choice == 3)
		{
			inRequests();
		}
		else if (choice == 4)
		{
			navigateRequests(amount);
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

// Function to view and approve/deny incoming requests
void Requests::inRequests(double amount)
{

}
