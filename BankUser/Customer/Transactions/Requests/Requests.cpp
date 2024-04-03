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

	cout << "\nPlease enter the amount of money you would like to apply for, without any spaces, symbols, or commas.\nType 'BACK' if you would like to return to the previous page.\n" << endl;
	cin >> m_loanAmount;

	if (m_loanAmount == "Back" || m_loanAmount == "BACK" || m_loanAmount == "back")
	{
		navigateRequests(amount);
	}

	const char* filename = "BankLoan.txt";

	ofstream file;

	file.open(filename, ios_base::app);

	if (!file.is_open())
	{
		cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}
	else if (file.is_open())
	{
		cout << "\n";

		file << "(USER ID) " << m_loanAmount << "\n";
	}

	file.close();

	Requests req;

	cout << "Your application for a $" << getloanAmount() << " loan has been sent to the admin for approval :)" << endl;

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

void Requests::sendMoney(double amount)
{
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

	const char* filename = "MoneySent.txt";

	ofstream file;

	file.open(filename, ios_base::app);

	if (!file.is_open())
	{
		cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}
	else if (file.is_open())
	{
		cout << "\n";

		file << "(USERID)" << " sent " << enteredID << " " << enteredAmount << "\n";
	}

	file.close();

	outRequests(amount);

}

void Requests::requestMoney(double amount)
{
	int tempID = 12345;
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

		//should probably add something to ensure account is still unlocked and active
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

	const char* filename = "RequestSent.txt";

	ofstream file;

	file.open(filename, ios_base::app);

	if (!file.is_open())
	{
		cout << "Error opening file: " << filename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}
	else if (file.is_open())
	{
		cout << "\n";

		file << "(USERID)" << " asked " << enteredID << " for " << enteredAmount << "\n";
	}

	file.close();

	outRequests(amount);
	
}

// Function to view outgoing request history
void Requests::requestHistory(double amount)
{
	string TempID;

	string tempRealID = "12345";

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> TempID;
	cout << "\n";

	// make a quick thing that grabs real userid and validates it is correct

	const char* rfilename = "RequestSent.txt";
	const char* sfilename = "MoneySent.txt";

	string line;

	ifstream rfile(rfilename);

	if (!rfile.is_open())
	{
		cout << "Error opening file: " << rfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(rfile, line))
	{
		if (line.find(TempID) != string::npos)
		{
			cout << line << endl;
		}
	}

	rfile.close();

	ifstream sfile(sfilename);

	if (!sfile.is_open())
	{
		cout << "Error opening file: " << sfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(sfile, line))
	{
		if (line.find(TempID) != string::npos)
		{
			cout << line << endl;
		}
	}

	sfile.close();

	outRequests(amount);
}

// Function to view and approve/deny incoming requests
void Requests::inRequests(double amount)
{
	string TempID;

	string tempRealID = "12345";

	cout << "\nPlease enter your userID: \n" << endl;
	cin >> TempID;
	cout << "\n";

	// make a quick thing that grabs real userid and validates it is correct

	const char* rfilename = "RequestSent.txt";

	string line;

	ifstream rfile(rfilename);

	if (!rfile.is_open())
	{
		cout << "Error opening file: " << rfilename << ". Please ensure that the file is downloaded and it exists in the correct location." << endl;
	}

	while (getline(rfile, line))
	{
		if (line.find(TempID) != string::npos)
		{
			cout << line << endl;
		}
	}

	rfile.close();
}
