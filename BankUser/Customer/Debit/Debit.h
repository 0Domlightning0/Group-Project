#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;
class Debit : public Customer
{
private:
    double m_debitAmount;
    string m_displayDebit;
    string m_lockCard;
    bool m_overdraft;

public:
    Debit();
    Debit(double DebitAmount, string Debit, string LockCard, bool Overdraft);

    // Getters and setters
    double getDebitAmount() { return m_debitAmount; }
    string getDebit() { return m_displayDebit; }
    string getLockCard() { return m_lockCard; }
    bool getOverdraft() { return m_overdraft; }

    void setDebitAmount(double DebitAmount) { m_debitAmount = DebitAmount; }
    void setDebit(string Debit) { m_displayDebit = Debit; }
    void setLockCard(string LC) { m_lockCard = LC; }
    void setOverdraft(bool overdraft) { m_overdraft = overdraft; }

    // Functions
    void displayDebit();  // Outputs vslue in account
    void lockCard();      // Lock or freeze credit card
    void unlockCard();    // Unfreeze account, need permission
    void Overdraft();     // Checks overdraft
};
