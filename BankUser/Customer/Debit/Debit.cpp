#include "Debit.h"
#include <iostream>
#include <string>
using namespace std;

Debit::Debit() {
    m_displayDebit = "";
    m_lockCard = "OPEN";
    m_overdraft = false;
}

Debit::Debit(double DebitAmount, string Debit, string LockCard, bool Overdraft){
    m_displayDebit = Debit;
    m_lockCard = LockCard;
    m_overdraft = Overdraft;
}

void Debit::displayDebit(){
    cout << "W";
}

void Debit::lockCard() {
    if (m_lockCard == "OPEN") {
        m_lockCard = "CLOSED";
    cout << "Your card is successfully locked.\n";
    }
}

void Debit::unlockCard() {
  if (m_lockCard == "CLOSED") {
      m_lockCard = "OPEN";
    cout << "Your card is successfully unlocked.\n";
  }
}

void Debit::Overdraft() { // [set a limit for the overdraft]
  if (m_overdraft == false){
    cout << "Your account is not overdrawn.\n";
  }
  if (m_overdraft == true){
    cout << "Your account is overdrawn.\n";
    cout << "You will be charged a $25 fee for every overdraft.\n";
  }
}
