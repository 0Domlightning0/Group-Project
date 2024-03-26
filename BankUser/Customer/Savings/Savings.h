#pragma once
#include <iostream>
#include <string>
using namespace std;
class Savings //: Class Customer
{
private:
	string m_displaySavings;
	double m_interest;
	string m_lockCard;
	double m_limit;

public:
	Savings();
	Savings(double Interest, string Savings, string LockCard, double Limit);

	string getSavings() { return m_displaySavings; }
	double getInterest() { return m_interest; }
	string getLockCard() { return m_lockCard; }
	double getLimit() { return m_limit; }

	void setSavings(string Savings) { m_displaySavings = Savings; }
	void setInterest(double Interest) { m_lockCard = Interest; }
	void setLockCard(string LockCard) { m_lockCard = LockCard; }
	void setLimit(double Limit) { m_limit = Limit; }

// Functions
	void displaySavings();
	void Interest();
	void accountLimit();
};
