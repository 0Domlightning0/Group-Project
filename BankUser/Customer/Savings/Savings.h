#pragma once
#include <iostream>
#include <string>
using namespace std;
class Savings : public Customer
{
private: // Variables
  double m_savingsAmount;
  string m_displaySavings;
  double m_interest;
  bool m_lockCard;
  double m_limit;

public:
  Savings();
  Savings(string Display, double Interest, double Savings, bool LockCard, double Limit);

// Getters and Setters
  double getSavingsAmount() { return m_savingsAmount; }
  string getSavings() { return m_displaySavings; }
  double getInterest() { return m_interest; }
  bool getLockCard() { return m_lockCard; }
  double getLimit() { return m_limit; }

  void setSavingsAmount(double Savings) { m_savingsAmount = Savings; }
  void setSavings(string Display) { m_displaySavings = Display; }
  void setInterest(double Interest) { m_lockCard = Interest; }
  void setLockCard(bool LockCard) { m_lockCard = LockCard; }
  void setLimit(double Limit) { m_limit = Limit; }

  // Functions
  void displaySavings();
  void requestLock();
  void requestUnlock();
  void Interest();
  void accountLimit(double Limit);
};
