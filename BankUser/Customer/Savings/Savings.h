#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;
class Savings : public Customer
{
private: // Variables
	double m_savingsAmount;
	double m_displaySavings;
	double m_interest;
	bool m_lockCard;
	double m_limit;

public:
	Savings();
	Savings(double Display, double Interest, double Amount, bool LockCard, double Limit);

// Getters and Setters
	double getSavingsAmount() { return m_savingsAmount; }
	double getSavings() { return m_displaySavings; }
	double getInterest() { return m_interest; }
	bool getLockCard() { return m_lockCard; }
	double getLimit() { return m_limit; }

	void setSavingsAmount(double Savings) { m_savingsAmount = Savings; }
	void setSavings(double Display) { m_displaySavings = Display; }
	void setInterest(double Interest) { m_lockCard = Interest; }
	void setLockCard(bool LockCard) { m_lockCard = LockCard; }
	void setLimit(double Limit) { m_limit = Limit; }

// Functions
	void displaySavings();
	void requestLock();
	void requestUnlock();
	void Interest(double Interest);
	void accountLimit(double Limit);
};
