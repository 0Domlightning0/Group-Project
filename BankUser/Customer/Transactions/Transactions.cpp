#include "Transactions.h"
#include <iostream>

using namespace std;

// Defualt constructor
Transactions::Transactions()
{
	m_balance = 0.0;
	m_numDep = 0;
	m_numWith = 0;
}

// Overloaded Constructor
Transactions::Transactions(double balance, int numDep, int numWith)
{
	m_balance = balance;
	m_numDep = numDep;
	m_numWith = numWith;
}

// Deconstructor
Transactions::~Transactions()
{
}

//The following functions use temp values, the intstructions in green will be followed to assign real values later:

// Deposit function that allows a user to add money to a checking(debit) account
void Transactions::depositC(double amount)
{
	//Fetch unique userID from a file
	//Use an if statement to verify the user has an active checking account, else cout error
	//Use getter to fetch amount currently held in the account
	//Ask user how much money they would like to add to account, store in a variable
	//userBalance += amount
	//cout updated balance, transaction complete

	double userBalance = 20;

	cout << "\nPlease enter the amount you would like to deposit: " << endl;
	cin >> amount;

	userBalance += amount;

	cout << "\nTransaction Successful!\nYour updated balance is: $" << userBalance << endl;
	
}

// Deposit function that allows a user to add money to a savings account
void Transactions::depositS(double amount)
{
	//Fetch unique userID from a file
	//Use an if statement to verify the user has an active savings account, else cout error
	//Use getter to fetch amount currently held in the account
	//Ask user how much money they would like to add to account, store in a variable
	//userBalance += amount
	//cout updated balance, transaction complete

	double userBalance = 20;

	cout << "\nPlease enter the amount you would like to deposit: " << endl;
	cin >> amount;

	userBalance += amount;

	cout << "\nTransaction Successful!\nYour updated balance is: $" << userBalance << endl;
}

// Withdraw function that allows a user to take money out of a checking(debit) account
void Transactions::withdrawC(double amount)
{
	//Fetch unique userID from a file
	//Use an if statement to verify the user has an active checking account, else cout error
	//Use getter to fetch amount currently held in the account
	//Ask user how much money they would like to take out of account, store in a variable
	// if amount > userBalance, cout error, insufficient funds
	//userBalance -= amount
	//cout updated balance, transaction complete

	double userBalance = 20;

	cout << "\nPlease enter the amount you would like to withdraw: " << endl;
	cin >> amount;
	
	if (userBalance < amount)
	{
		cout << "\nERROR: Insufficient funds" << endl;
	}
	else
	{
		userBalance -= amount;

		cout << "\nTransaction Successful!\nYour updated balance is: $" << userBalance << endl;
	}
}

// Withdraw function that allows a user to take money out of a savings account
void Transactions::withdrawS(double amount)
{
	//Fetch unique userID from a file
	//Use an if statement to verify the user has an active savings account, else cout error
	//Use getter to fetch amount currently held in the account
	//Ask user how much money they would like to add to account, store in a variable
	//if amount > userBalance, cout error, insufficient funds
	//userBalance -= amount
	//cout updated balance, transaction complete
	
	double userBalance = 20;

	cout << "\nPlease enter the amount you would like to withdraw: " << endl;
	cin >> amount;

	if (userBalance < amount)
	{
		cout << "\nERROR: Insufficient funds" << endl;
	}
	else
	{
		userBalance -= amount;

		cout << "\nTransaction Successful!\nYour updated balance is: $" << userBalance << endl;
	}
}

void Transactions::createTransaction(double amount)
{
	int choice;
	do
	{
		cout << "\nPlease select one of the following options\n1) - Deposit\n2) - Withdraw\n3) - Go Back\n" << endl;
		cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3)
		{
			cout << "ERROR: Please enter a vailid choice." << endl;
		}
		else if (choice == 1)
		{
			int c1;
			cout << "\nYou chose: DEPOSIT\n\nPlease choose an account from the following options\n1) - Checking\n2) - Savings\n3) - Go Back\n" << endl;
			cin >> c1;

			if (c1 != 1 && c1 != 2 && c1 != 3)
			{
				cout << "Error" << endl;
			}
			else if (c1 == 1)
			{
				depositC(amount);
			}	
			else if (c1 == 2)
			{
				depositS(amount);
			}
			else if (c1 == 3)
			{
				//Go back
			}
		}

		else if (choice == 2)
		{
			int c2;
			cout << "\nYou chose: WITHDRAW\n\nPlease choose an account from the following options\n1) - Checking\n2) - Savings\n3) - Go Back\n" << endl;
			cin >> c2;

			if (c2 != 1 && c2 != 2 && c2 != 3)
			{
				cout << "Error" << endl;
			}
			else if (c2 == 1)
			{
				withdrawC(amount);
			}
			else if (c2 == 2)
			{
				withdrawS(amount);
			}
			else if (c2 == 3)
			{
				//Go back
			}
		}

		else if (choice == 3)
		{
			// go back to the MAIN transactions menu
		}
	} while (choice != 1 && choice != 2 && choice != 3);

}

void Transactions::navigate(double amount)
{
	int choice;
	do
	{
		cout << "Please select one of the following options\n\n1) - Make a Transaction\n2) - View Transaction History\n3) - Requests Menu\n4) - Go Back\n" << endl;
		cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			cout << "ERROR: Please enter a vailid choice." << endl;
		}
		else if (choice == 1)
		{
			createTransaction(amount);
		}
		else if (choice == 2)
		{
			// View Transaction History
		}
		else if (choice == 3)
		{
			// create a requests menu? (not sure if this should go on the main page after logging in, or hidden away in transactions
		}
		else if (choice == 4)
		{
			// go back to the beginning page after logging in
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}
