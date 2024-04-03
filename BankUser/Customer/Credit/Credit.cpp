#include <iostream>
#include <string>
#include "Credit.h"
using namespace std;

Credit::Credit() {
    m_lockCard = false;
    m_creditScore = 0;
    m_overdraft = false;
}

Credit::Credit(bool LC, int score, bool overdraft) {
    m_lockCard = LC;
    m_creditScore = score;
    m_overdraft = overdraft;
}

Credit::~Credit() {}

// Locks/Freezes the account
void Credit::lockCard(bool LC) {
    if (LC == true) {
        m_lockCard = LC;
        cout << "Your card is successfully locked.\n";
    }
}

// Unlocks/Unfreezes the account
void Credit::unlockCard(bool LC) {
    if (LC == false) {
        m_lockCard = LC;
        cout << "Your card is successfully unlocked.\n";
    }
}

// Displays user's credit score
void Credit::CreditScore(int score) {
    cout << "Credit Score: " << m_creditScore << endl;
}

// Displays overdraft status
void Credit::Overdraft(bool overdraw) {
    if (m_overdraft == false) {
        cout << "Your account is not overdrawn.\n";
    }
    if (m_overdraft == true) {
        cout << "Your account is overdrawn.\n";
        cout << "You will be charged a $25 fee for every overdraft.\n";
    }
}
