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

// Deposit function that allows a user to add money to an account
void Transactions::deposit(double amount)
{
	

}

// Withdraw function that allows a user to take money out of an account
void Transactions::withdraw(double amount)
{

}

/* ignore, don't really know where im gonna put this, just putting it here for now so i have a bit of a map*/
void temp()
{
	int choice;
	do
	{
	cout << "Please select one of the following options\n1) - Deposit Money\n2) - Withdraw Money\n3) - Requests Menu\n4) - Go Back" << endl;
	cin >> choice;

		if (choice != 1 || choice != 2 || choice != 3 || choice != 4)
		{
			cout << "ERROR: Please enter a vailid choice." << endl;
		}
		else if (choice == 1)
		{
			// deploy deposit function
		}
		else if (choice == 2)
		{
			// deploy withdraw function
		}
		else if (choice == 3)
		{
			// create a requests menu? (not sure if this should go on the main page after logging in, or hidden away in transactions
		}
		else if (choice == 4)
		{
			// go back to the beginning page after logging in
		}
	} while (choice != 1 || choice != 2 || choice != 3 || choice != 4);
}
