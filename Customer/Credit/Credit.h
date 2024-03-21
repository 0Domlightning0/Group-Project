#include <iostream>
#include <string>
using namespace std;

class Credit : public Customer
{
private:
    bool m_lockCard;      
    int m_creditScore;
    double m_overdraw;

public:
    Credit();
    Credit(bool LC, int score);

// Getters and setters
    bool getLockCard() { return m_lockCard; 
    int getCreditScore() { return m_creditScore; }
    void setLockCard(bool LC) { m_lockCard = LC; }
    void setCreditScore(int score) { m_creditScore = score; }

// Functions
    void lockCard(bool LC);        // Lock or freeze credit card
    void unlockCard(bool LC);      // Unfreeze account, needs permission
    void CreditScore(int score);   // Checks credit score
};
