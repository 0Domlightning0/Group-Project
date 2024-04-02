#include "Savings.h"
#include <iostream>
#include <string>
using namespace std;

Savings::Savings() {
	m_savingsAmount = 0.0;
	m_displaySavings = 0.0;
	m_interest = 0.0;
	m_lockCard = false;
	m_limit = 0.0;
}

Savings::Savings(double Display, double Interest, double Amount, bool LockCard, double Limit) {
	m_displaySavings = Display;
	m_savingsAmount = Amount;
	m_interest = Interest;
	m_lockCard = LockCard;
	m_limit = Limit;
}

// Displays the user's savings amount
void Savings::displaySavings() {
	cout << "Your current savings amount is $" << m_displaySavings << endl;
}

// Request to lock account
void Savings::requestLock() {
	if (m_lockCard == false) {
		m_lockCard = true;
		cout << "Your account is now locked.\n";
	}
	else { cout << "ACCOUNT ALREADY LOCKED\n"; }
}

// Request to unlock account
void Savings::requestUnlock() {
	if (m_lockCard == true) {
		m_lockCard = false;
		cout << "Your account is now unlocked.\n";
	}
	else { cout << "ACCOUNT ALREADY UNLOCKD\n"; }
}

// Displays the user's interest rate
// Outputs the new savings amount after interest
void Savings::Interest(double Interest) {
	cout << "The interest rate is " << m_interest << "%" << endl;
	m_savingsAmount = (m_savingsAmount * m_interest);
}

// Sets a limit to your savings account
void Savings::accountLimit(double Limit) {
	m_limit = Limit;
	cout << "Your card limit has been set to $" << m_limit << endl;
	if (m_savingsAmount += m_limit > 3000.0) {
		m_savingsAmount += m_limit;
		cout << "Current amount is " << m_savingsAmount << endl;
	}
	else if (m_savingsAmount += m_savingsAmount < 3000.0) {
		cout << "You have reached your limit.\n";
	}
}
