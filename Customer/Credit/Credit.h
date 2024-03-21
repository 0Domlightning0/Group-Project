#include <iostream>
#include <string>
using namespace std;

class Credit : 
{
private:
    bool m_lockCard; // Sets whether card is locked or unlocked
    int m_creditScore;  // Checks credit score
    double m_overdraw; // implement later...

public:
    Credit();
    Credit(bool LC, int score);

    bool getLockCard() { return m_lockCard; 
    int getCreditScore() { return m_creditScore; }
    void setLockCard(bool LC) { m_lockCard = LC; }
    void setCreditScore(int score) { m_creditScore = score; }

    void lockCard(bool LC);
    void unlockCard(bool LC);
    void CreditScore(int score);
};
