#include <iostream>
#include <string>
#include "Credit.h"
using namespace std;

Credit::Credit() {
    m_lockCard = false;
    m_creditScore = 0;

}

Credit::Credit(bool LC, int score) {
    m_lockCard = LC;
    m_creditScore = score;
}

void Credit::lockCard(bool LC) {
    LC = true;
    m_lockCard = LC;
    cout << "Your card is successfully locked.\n";
}

void Credit::unlockCard(bool LC) {
    LC = false;
    m_lockCard = LC;
    cout << "Your card is successfully unlocked.\n";
}

void Credit::CreditScore(int score) {
    cout << "Credit Score: " << m_creditScore << endl;
}
