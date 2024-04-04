#include "Transactions.h"
#include "Requests.h"
#include <iostream>
#include <fstream>
#include <string>

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
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	const char* cfilename = "CustomerList.txt";

	string line;

	ifstream cfile(cfilename);

	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl;

			cfile.close();

			double userBalance = 1000;

			cout << "\nPlease enter the amount you would like to deposit: " << endl;
			cin >> amount;

			userBalance += amount;

			cout << "\nTransaction Successful!\nYour updated balance is: $" << userBalance << endl;

			const char* filename = "CheckingDeposits.txt";

			ofstream file;

			file.open(filename, ios_base::app);

			if (!file.is_open())
			{
				cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
			}
			else if (file.is_open())
			{
				cout << "\n";

				file << userID << " deposited " << amount << " to checking" << "\n";
			}

			file.close();

			createTransaction(amount);
		}
	}
	cout << "Error: User not found" << endl;

	createTransaction(amount);
}

// Deposit function that allows a user to add money to a savings account
void Transactions::depositS(double amount)
{
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	const char* cfilename = "CustomerList.txt";

	string line;

	ifstream cfile(cfilename);

	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl;

			cfile.close();

			double userBalance = 1000;

			cout << "\nPlease enter the amount you would like to deposit: " << endl;
			cin >> amount;

			userBalance += amount;

			cout << "\nTransaction Successful!\nYour updated balance is: $" << userBalance << endl;

			const char* filename = "SavingsDeposits.txt";

			ofstream file;

			file.open(filename, ios_base::app);

			if (!file.is_open())
			{
				cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
			}
			else if (file.is_open())
			{
				cout << "\n";

				file << userID << " deposited " << amount << " to savings" << "\n";
			}

			file.close();

			createTransaction(amount);
		}
	}
	cout << "Error: User not found" << endl;

	createTransaction(amount);
}

// Withdraw function that allows a user to take money out of a checking(debit) account
void Transactions::withdrawC(double amount)
{
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	const char* cfilename = "CustomerList.txt";

	string line;

	ifstream cfile(cfilename);

	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl;

			cfile.close();

			double userBalance = 1000;

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

				const char* filename = "CheckingWithdrawals.txt";

				ofstream file;

				file.open(filename, ios_base::app);

				if (!file.is_open())
				{
					cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
				}
				else if (file.is_open())
				{
					cout << "\n";

					file << userID << " withdrew " << amount << " from checking" << "\n";
				}

				file.close();
			}

			createTransaction(amount);
		}
	}
	cout << "Error: User not found" << endl;

	createTransaction(amount);
}

// Withdraw function that allows a user to take money out of a savings account
void Transactions::withdrawS(double amount)
{
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	const char* cfilename = "CustomerList.txt";

	string line;

	ifstream cfile(cfilename);

	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl;

			cfile.close();

			double userBalance = 1000;

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

				createTransaction(amount);

				const char* filename = "CheckingWithdrawals.txt";

				ofstream file;

				file.open(filename, ios_base::app);

				if (!file.is_open())
				{
					cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
				}
				else if (file.is_open())
				{
					cout << "\n";

					file << userID << " withdrew " << amount << " from checking" << "\n";
				}

				file.close();
			}

			createTransaction(amount);
		}
	}
	cout << "Error: User not found" << endl;

	createTransaction(amount);
}

// Function that allows you to engage with the deposit and withdraw functions though a menu
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
				createTransaction(amount);
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
				createTransaction(amount);
			}
		}

		else if (choice == 3)
		{
			navigate(amount);
		}
	} while (choice != 1 && choice != 2 && choice != 3);

}

// Function that allows you to navigate the transactions class using a menu
void Transactions::navigate(double amount)
{
	int choice;
	do
	{
		cout << "\nPlease select one of the following options\n\n1) - Make a Transaction\n2) - View Transaction History\n3) - Requests Menu\n4) - Go Back\n" << endl;
		cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			cout << "\nERROR: Please enter a vailid choice.\n" << endl;
		}
		else if (choice == 1)
		{
			createTransaction(amount);
		}
		else if (choice == 2)
		{
			transactionHistory(amount);
		}
		else if (choice == 3)
		{
			Requests back;
			back.navigateRequests(amount);
		}
		else if (choice == 4)
		{
			// Return to a menu function in customer (likely seen immediately after logging in)
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

// Function that allows a user to view thier previous transactions by searching their userID
void Transactions::transactionHistory(double amount)
{
	string TempID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> TempID;
	cout << "\n";

	const char* dcfilename = "CheckingDeposits.txt";
	const char* dsfilename = "SavingsDeposits.txt";
	const char* wcfilename = "CheckingWithdrawals.txt";
	const char* wsfilename = "SavingsWithdrawals.txt";

	string line;

	ifstream dcfile(dcfilename);

	if (!dcfile.is_open())
	{
		cout << "Error opening file: " << dcfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(dcfile, line))
	{
		if (line.find(TempID) != string::npos)
		{
			cout << line << endl;
		}
	}

	dcfile.close();

	ifstream dsfile(dsfilename);

	if (!dsfile.is_open())
	{
		cout << "Error opening file: " << dsfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(dsfile, line))
	{
		if (line.find(TempID) != string::npos)
		{
			cout << line << endl;
		}
	}

	dsfile.close();

	ifstream wcfile(wcfilename);

	if (!wcfile.is_open())
	{
		cout << "Error opening file: " << wcfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(wcfile, line))
	{
		if (line.find(TempID) != string::npos)
		{
			cout << line << endl;
		}
	}

	wcfile.close();

	ifstream wsfile(wsfilename);

	if (!wsfile.is_open())
	{
		cout << "Error opening file: " << wsfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(wsfile, line))
	{
		if (line.find(TempID) != string::npos)
		{
			cout << line << endl;
		}
	}

	wsfile.close();

	navigate(amount);
}
