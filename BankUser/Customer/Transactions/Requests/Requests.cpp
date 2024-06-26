// Jalen Taylor, 400470470
#include "Requests.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Default constructor
Requests::Requests()
{
	m_loanAmount = "";
}

// Overloaded constructor
Requests::Requests(string loanAmount)
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

// Function to apply for a bank loan, sent to admin for approval
void Requests::loanApply(double amount)
{
	// prompt for the current user to enter their ID
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	// Creating a variable set to the current filename for convenience
	const char* cfilename = "CustomerList.txt";

	string line;

	// Open the current file
	ifstream cfile(cfilename);

	// If the current file is not opening, cout an error message
	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl;

			// Close the current file
			cfile.close();

			cout << "\nPlease enter the amount of money you would like to apply for, without any spaces, symbols, or commas.\nType 'BACK' if you would like to return to the previous page.\n" << endl;
			cin >> m_loanAmount;

			if (m_loanAmount == "Back" || m_loanAmount == "BACK" || m_loanAmount == "back")
			{
				navigateRequests(amount);
			}

			// Creating a variable set to the current filename for convenience
			const char* filename = "BankLoan.txt";

			// Open the current file
			ofstream file;

			file.open(filename, ios_base::app);

			// If the current file is not opening, cout an error message
			if (!file.is_open())
			{
				cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
			}
			else if (file.is_open())
			{
				cout << "\n";

				file << userID << m_loanAmount << "\n";
			}

			// Close the current file
			file.close();

			Requests req;

			cout << "Your application for a $" << getloanAmount() << " loan has been sent to the admin for approval :)" << endl;

			navigateRequests(amount);
		}
	}
	cout << "Error: User not found" << endl;

	navigateRequests(amount);
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
			requestHistory(amount);
		}
		else if (choice == 4)
		{
			navigateRequests(amount);
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

// Function that allows a user to send money to another user
void Requests::sendMoney(double amount)
{
	// prompt for the current user to enter their ID
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	// Creating a variable set to the current filename for convenience
	const char* cfilename = "CustomerList.txt";

	string line;

	// Open the current file
	ifstream cfile(cfilename);

	// If the current file is not opening, cout an error message
	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl;

			// Close the current file
			cfile.close();

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

			cout << "\nYou Chose: Y\nThe request to send $" << enteredAmount << " to user #" << enteredID << " from your " << account << " has been sent and is awaiting their approval\n" << endl;

			// Creating a variable set to the current filename for convenience
			const char* filename = "MoneySent.txt";

			// Open the current file
			ofstream file;

			file.open(filename, ios_base::app);

			// If the current file is not opening, cout an error message
			if (!file.is_open())
			{
				cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
			}
			else if (file.is_open())
			{
				cout << "\n";

				file << userID << " sent " << enteredID << " " << enteredAmount << "\n";
			}

			// Close the current file
			file.close();

			outRequests(amount);
		}
	}
	cout << "Error: User not found" << endl;

	outRequests(amount);
}

// Function that allows a user to request money from another user
void Requests::requestMoney(double amount)
{
	// prompt for the current user to enter their ID
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	// Creating a variable set to the current filename for convenience
	const char* cfilename = "CustomerList.txt";

	string line;

	// Open the current file
	ifstream cfile(cfilename);

	// If the current file is not opening, cout an error message
	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl;

			// Close the current file
			cfile.close();

			int enteredID;
			double enteredAmount;
			int selectedAcc;
			string account;
			char confirm;

			cout << "\nPlease enter the user ID of the person you would like to request money from: " << endl;
			cin >> enteredID;

			cout << "\nPlease enter the amount of money you would like to request from user #" << enteredID << ": " << endl;
			cin >> enteredAmount;

			cout << "\nPlease select the account you would like the money deposited to:\n1) - Checking\n2) - Savings" << endl;
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

			cout << "\nYou are currently attempting to request " << enteredAmount << " from user #" << enteredID << " to be deposited to your " << account << " account\nIs this correct ? (Y / N) : \n" << endl;
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

			cout << "\nYou Chose: Y\nThe request for $" << enteredAmount << " from user #" << enteredID << " to be deposited to your " << account << " has been sent and is awaiting their approval\n" << endl;

			// Creating a variable set to the current filename for convenience
			const char* filename = "RequestSent.txt";

			// Open the current file
			ofstream file;

			file.open(filename, ios_base::app);

			// If the current file is not opening, cout an error message
			if (!file.is_open())
			{
				cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
			}
			else if (file.is_open())
			{
				cout << "\n";

				file << "(USERID)" << " asked " << enteredID << " for " << enteredAmount << "\n";
			}

			// Close the current file
			file.close();

			outRequests(amount);

		}
	}
	cout << "Error: User not found" << endl;

	outRequests(amount);
}

// Function to view outgoing request history
void Requests::requestHistory(double amount)
{
	// prompt for the current user to enter their ID
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	// Creating a variable set to the current filename for convenience
	const char* cfilename = "CustomerList.txt";

	string line;

	// Open the current file
	ifstream cfile(cfilename);

	// If the current file is not opening, cout an error message
	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl << endl;

			// Close the current file
			cfile.close();

			// Creating a variable set to the current filename for convenience
			const char* rfilename = "RequestSent.txt";
			const char* sfilename = "MoneySent.txt";

			string line;

			// Open the current file
			ifstream rfile(rfilename);

			// If the current file is not opening, cout an error message
			if (!rfile.is_open())
			{
				cout << "Error opening file: " << rfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
			}

			while (getline(rfile, line))
			{
				if (line.find(userID) != string::npos)
				{
					cout << line << endl;
				}
			}

			// Close the current file
			rfile.close();

			// Open the current file
			ifstream sfile(sfilename);

			// If the current file is not opening, cout an error message
			if (!sfile.is_open())
			{
				cout << "Error opening file: " << sfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
			}

			while (getline(sfile, line))
			{
				if (line.find(userID) != string::npos)
				{
					cout << line << endl;
				}
			}

			// Close the current file
			sfile.close();

			outRequests(amount);
		}
	}
	cout << "Error: User not found" << endl;

	outRequests(amount);
}

// Function to view and approve/deny incoming requests
void Requests::inRequests(double amount)
{
	// prompt for the current user to enter their ID
	string userID;

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> userID;
	cout << "\n";

	// Creating a variable set to the current filename for convenience
	const char* cfilename = "CustomerList.txt";

	string line;

	// Open the current file
	ifstream cfile(cfilename);

	// If the current file is not opening, cout an error message
	if (!cfile.is_open())
	{
		cout << "Error opening file: " << cfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(cfile, line))
	{
		if (line.find(userID) != string::npos)
		{
			cout << line << endl << endl;

			cfile.close();

			// Creating a variable set to the current filename for convenience
			const char* rfilename = "RequestSent.txt";

			string line;

			// Open the current file
			ifstream rfile(rfilename);

			// If the current file is not opening, cout an error message
			if (!rfile.is_open())
			{
				cout << "Error opening file: " << rfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
			}

			while (getline(rfile, line))
			{
				if (line.find(userID) != string::npos)
				{
					cout << line << endl;
				}
			}

			// Close the current file
			rfile.close();

			navigateRequests(amount);
		}
	}
	cout << "Error: User not found" << endl;

	navigateRequests(amount);
}
