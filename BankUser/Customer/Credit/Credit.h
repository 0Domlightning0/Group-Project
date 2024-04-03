#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

class Credit : public Customer
{
private:
    bool m_lockCard;
    int m_creditScore;
    bool m_overdraft;

public:
    Credit();
    Credit(bool LC, int score, bool overdraft);
    ~Credit();

// Getters and setters
    bool getLockCard() { return m_lockCard; }
    int getCreditScore() { return m_creditScore; }
    bool getOverdraft() { return m_overdraft; }

    void setLockCard(bool LC) { m_lockCard = LC; }
    void setCreditScore(int score) { m_creditScore = score; }
    void setOverdraft(bool overdraft) { m_overdraft = overdraft; }

// Functions
    void lockCard(bool LC);         // Lock or freeze credit card
    void unlockCard(bool LC);       // Unfreeze account, needs permission
    void CreditScore(int score);    // Checks credit score
    void Overdraft(bool overdraft); // Checks overdraft
};
