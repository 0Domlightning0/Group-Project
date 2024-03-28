#include "Savings.h"
#include <iostream>
#include <string>
using namespace std;

Savings::Savings() {
  m_savingsAmount = 0.0;
  m_displaySavings = "";
  m_interest = 3.5;
  m_lockCard = false;
  m_limit = 3000.0;
}

Savings::Savings(string Display, double Interest, double Savings, bool LockCard, double Limit) {
  m_savingsAmount = Savings;
  m_displaySavings = Display;
  m_interest = Interest;
  m_lockCard = LockCard;
  m_limit = Limit;
}
// Displays the user's savings amount
void Savings::displaySavings() {
  cout << "Your current saving amount is: $" << m_displaySavings << endl;
  }
// Request to lock account
void Savings::requestLock(){
  m_lockCard = true;
  cout << "Your account is now locked.\n";
}
// Request to unlock account
void Savings::requestUnlock(){
  m_lockCard = false;
  cout << "Your account is now unlocked.\n";
}
// Displays the user's interest rate
// Outputs the new savings amount after interest
void Savings::Interest() {
  cout << "The interest rate for your savings account is: " << m_interest << "%" << endl;
  m_savingsAmount * m_interest = m_savingsAmount;
}
// Sets a limit to your savings account
void Savings::accountLimit(double Limit) {
  m_limit = Limit;
  cout << "Your card limit has been set to: $" << m_limit << endl;
  if (m_savingsAmount += m_savingsAmount > 3000.0) {
  }

  else if (m_savingsAmount += m+savingsAmount < 3000.0) {
  }
