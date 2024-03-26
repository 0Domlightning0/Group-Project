#include "Savings.h"
#include <iostream>
#include <string>
using namespace std;

Savings::Savings(){
	m_displaySavings = "";
	m_interest = 0.0;
	m_lockCard = "";
	m_limit = 3000.0;
}

Savings::Savings(double Interest, string Savings, string LockCard, double Limit){
	m_displaySavings = Savings;
	m_interest = Interest;
	m_lockCard = LockCard;
	m_limit = Limit;
}

void Savings::displaySavings(){}

void Savings::Interest(){}

void Savings::accountLimit(){
	if ([AMOUNT] > 3000.0) {}

	else if ([AMOUNT] < 3000.0){}
}
