#pragma once

// Also child of Transactions
#include "Admin.h"
#include "Transactions.h"
class TransactionsFilter : public Admin, public Transactions
{
protected:
	double m_loanAmount = 0;
	double m_amount = 0;
	int m_senderID = 0;
	int m_reciverID = 0;
	string m_senderaccountType = "";
	string m_reciveraccountType = "";

public:

	TransactionsFilter();

	TransactionsFilter(double loanAmount, double amount, int senderID, int reciverID, string senderaccountType, string reciveraccountType);

	~TransactionsFilter();


	// getters
	double get_loanAmount() { return m_loanAmount; };
	double get_amount() { return m_amount; };
	int get_senderID() { return m_senderID; };
	int get_reciverID() { return m_senderID; };
	string get_reciveraccountType() { return m_reciveraccountType; };
	string get_senderaccountType() { return m_senderaccountType; };

	// setters
	void set_loanAmount(double loanAmount) { m_loanAmount = loanAmount; };
	void set_amount(double amount) { m_amount = amount; };
	void set_senderID(int senderID) { m_senderID = senderID; };
	void set_reciverID(int reciverID) { m_reciverID = reciverID; };
	void set_senderaccountType(string senderaccountType) { m_senderaccountType = senderaccountType; };
	void set_reciveraccountType(string reciveraccountType) { m_reciveraccountType = reciveraccountType; };

	void displayTransactions(ifstream& infile, int len);
};
